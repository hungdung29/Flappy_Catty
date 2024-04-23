#pragma once

#include "lib.h"
#include <vector>
#include <SDL.h>

class Pipe:gTexture{
    short int move = 3;
    const short int Max = screenHeight - LandHeight - PipeSpacing - PipeShowMin;
    const short int Min = PipeShowMin;
public:
    bool Draw();
    ~Pipe();

    void render();

    void update(); //Update position of pipe

    short int width() {return getWidth();}
    short int height() {return getHeight();}     
    
};
extern position posPipe [gTexture::numPipes];
extern int hiddenPipe;
