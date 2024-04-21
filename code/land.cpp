#include "land.h"
#include <iostream>
#include <SDL_image.h>

bool Land::Draw(){
    posLand.getPos (0, screenHeight - LandHeight);
    if (isNULL()){
        if (Load ("res/image/land.png", 1)) return true;
    }
    return false;
}

Land::~Land(){
    gTexture::~gTexture();
}

void Land::render(){
    if (-screenWidth < posLand.x && posLand.x <= 0) {
        Render (posLand.x, posLand.y);
        Render (posLand.x + screenWidth, posLand.y);
    }
    else {
        posLand.getPos (0, screenHeight - LandHeight);
        Render (posLand.x, posLand.y);
    }
}
void Land::update(){
    posLand.x-=3;
}