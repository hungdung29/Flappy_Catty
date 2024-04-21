#pragma once

#include "lib.h"
#include <vector>
#include <SDL.h>

class Pipe:gTexture{
public:
    bool Draw();
    ~Pipe();

    void render();

    void update(); //Update position of pipe

    short int width() {return getWidth();}
    short int height() {return getHeight();}

    const short int Max = screenHeight - LandHeight - PipeSpacing - PipeShowMin;
    const short int Min = PipeShowMin;

       
    
};
extern position posPipe [gTexture::numPipes];
