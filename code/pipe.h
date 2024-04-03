#pragma once

#include "lib.h"
#include <vector>
#include <SDL.h>

class Pipe:gTexture{
public:
    bool Draw();
    ~Pipe();

    void render();

    void update();

    void ResetPipePosition();

    short int width() {return getWidth();}
    short int height() {return getHeight();}

    const short int randMin = 60;

    
    
};
extern position posPipe [gTexture::numPipes];
