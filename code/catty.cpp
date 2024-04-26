#include "catty.h"
#include "pipe.h"
#include <iostream>
#include <string>
#include <SDL_image.h>

short int onward = 0;

bool Catty::Draw(){
    string catty_path = "res/image/catty.png";
    if (saved_path == catty_path){
        posCatty.getPos (50, (screenHeight - LandHeight)  / 2 );
        onward = 0;
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
    Render (posCatty.x, posCatty.y, angle);
}

void Catty::fall() {
    if (die && posCatty.y < screenHeight - LandHeight - CattyHeight){
        if (time == 0) {
            y0 = posCatty.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)  angle += 3;

        if (time >= 0){
            posCatty.y = y0 + v0 * time + 0.5 * acceleration * time * time; 
            time++;
        }
    }
}

void Catty::update(short int pipeWidth, short int pipeHeight){
    if (!die){
        if (time == 0) {
            y0 = posCatty.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)  angle += 3;

        if (time >= 0){
            posCatty.y = y0 + v0 * time + 0.5 * acceleration * time * time;  
            time++;
        }
        
        if (posCatty.y + getHeight() > screenHeight - LandHeight ) die = true;

        if ( ((posCatty.x + getWidth() > posPipe[onward].x) && (posCatty.x < posPipe[onward].x + pipeWidth)) 
          && ((posCatty.y + getHeight() > posPipe[onward].y + pipeHeight + PipeSpacing) || posCatty.y < posPipe[onward].y + pipeHeight) )
        { die = true; }
        else if (posCatty.x >= posPipe[onward].x + pipeWidth){
            onward = (onward + 1) % numPipes;
            score++;
        }
        
    }
}
