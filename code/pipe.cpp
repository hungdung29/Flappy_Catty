#include "pipe.h"
#include <SDL_image.h>
#include <iostream>
#include <cstdlib>
#include <vector>

position posPipe [gTexture::numPipes] = {};

bool Pipe::Draw() {
    for (int i = 0; i < numPipes; i++){
        posPipe[i].getPos (screenWidth + i * PipeDistance, (rand() % (screenHeight - LandHeight - PipeSpacing - 2 * PipeHeightMin)) - PipeHeight + PipeHeightMin);
    }
    if (isNULL())
    {
        if (Load("res/image/pipe.png", 1)) return true;
    }
    return false;
}

Pipe::~Pipe() {
    
}

void Pipe::render()
{
    for (int i = 0; i < numPipes; i++)
    {
        if (posPipe[i].x <= screenWidth && posPipe[i].x > 0)
        {
            Render(posPipe[i].x, posPipe[i].y);
        }
        Render(posPipe[i].x, posPipe[i].y + PipeHeight + PipeSpacing, 180);
    }
}

void Pipe::update() {
    if (!die){
        for (int i = 0; i < numPipes; i++) {
            if (posPipe[i].x < 0){
                posPipe[i].x = posPipe[(i + numPipes - 1) % numPipes].x + PipeDistance;
                posPipe[i].y = (rand() % (screenHeight - LandHeight - PipeSpacing - 2 * PipeHeightMin)) - PipeHeight + PipeHeightMin;
            }
            else {
                posPipe[i].x-=3;
            }
        }
    }
}


