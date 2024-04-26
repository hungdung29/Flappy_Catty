#include "land.h"
#include <iostream>
#include <SDL_image.h>
#include "background.h"

bool Background::Draw(bool isDark){
    posBackground.getPos (0, 0);
    string background_path = "res/image/background.png";
    if (isDark) background_path = "res/image/background-night.png";
    if (saved_path == background_path) posBackground.getPos (0, 0);
    if (isNULL() || saved_path != background_path)
    {
        saved_path = background_path;
        if (Load(background_path.c_str() , 1)) return true;
    }
    return false;
}

Background::~Background(){
    gTexture::~gTexture();
}

void Background::render(){
    if (-screenWidth < posBackground.x && posBackground.x <= 0) {
        Render (posBackground.x, posBackground.y);
        Render (posBackground.x + screenWidth, posBackground.y);
    }
    else {
        posBackground.getPos (0, 0);
        Render (posBackground.x, posBackground.y);
    }
}
void Background::update(){
    posBackground.x-=3;
}