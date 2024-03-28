#include "catty.h"
#include "pipe.h"
#include <iostream>
#include <SDL_image.h>

bool Catty::Draw(){
    string catty_path = "res/image/catty.png";
    if (saved_path == catty_path){
        posCatty.getPos (50, screenHeight / 2);
        yVelocity = 0;
        angle = 0;
    }
    if (isNULL() || saved_path != catty_path){
        saved_path = catty_path;
        if ( (Load (catty_path.c_str(),1) ) ) return true;
        return false;
    }
    return false;
}

Catty::~Catty() {
    gTexture::~gTexture();  
}

void Catty::render() {
    Render (posCatty.x, Catty.y, angle);
}

// void Catty::HandleInput(SDL_Event& event) {
//     if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
//         yVelocity = -5.0f; 
//     }
// }

// void Catty::Update(float deltaTime) {
//     yPos += yVelocity * deltaTime;    
//     yVelocity += 0.2f; 
// }
void Catty::fall() {
    if (!die){
        if (time == 0) {
            x0 = posDoge.y;
            angle = -25;
        }

        if (time >= 0){
            posCatty.y = x0  + v0 * time + 0.5 * acceleration * time * time; 
            time++;
        }
    }
}

void Catty::check(short int pipeWidth, short int pipeHeight){
    if (!die){
        if (time == 0) {
            x0 = posDoge.y;
            angle = -25;
        }

        if (time >= 0){
            posCatty.y = x0  + v0 * time + 0.5 * acceleration * time * time; 
            time++;
        }
        
        if (posDoge.y + getHeight() > screenHeight - LandHeight ) die = true;

        if ( ((posCatty.x + getWidth() > posPipe[onward].x) && (posCatty.x < posPipe[onward].x + pipeWidth)) 
          && ((posCatty.y + getHeight() > posPipe[onward].y + pipeHeight + PipeSpacing) || posCatty.y < posPipe[onward].y + pipeHeight) )
        { die = true; }
        else if (posCatty.x >= posPipe[onward].x + pipeWidth){
            onward = (onward + 1) % numPipes;
            score++;
        }
        
    }
}
