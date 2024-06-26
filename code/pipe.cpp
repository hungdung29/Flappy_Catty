#include "pipe.h"
#include "catty.h"

#include <SDL_image.h>
#include <iostream>
#include <cstdlib>
#include <vector>

position posPipe [gTexture::numPipes];

bool Pipe::Draw() {
    posPipe [gTexture::numPipes] = {};
    onward = 0;
    for (int i = 0; i < numPipes; i++){
        posPipe[i].getPos (screenWidth + i * PipeDistance, (rand() % (Max - Min + 1)) - PipeHeight + Min);
    }
    if (isNULL())
    {
        if (Load("res/image/pipe.png", 1)) return true;
    }
    return false;
}

Pipe::~Pipe() {
    gTexture::~gTexture();
}

void Pipe::render()
{
    for (int i = 0; i < numPipes; i++)
    {
        if (posPipe[i].x <= screenWidth && posPipe[i].x >= -getWidth())
        {
            Render(posPipe[i].x, posPipe[i].y);
        }
        Render(posPipe[i].x, posPipe[i].y + PipeHeight + PipeSpacing, 180);
    }
}

void Pipe::update() {
    if (!die){
        for (int i = 0; i < numPipes; i++) {
            if (posPipe[i].x < -getWidth()){
                posPipe[i].x = posPipe[(i + numPipes - 1) % numPipes].x + PipeDistance;
                posPipe[i].y = (rand() % (Max - Min + 1)) - PipeHeight + Min;
            }
            else {
                posPipe[i].x -= pipeMove;
                if (posPipe[i].y % 50 == 0) move = -move;
                if (posPipe[i].y + move > 0 || posPipe[i].y + move < -PipeHeight) move = -move;
                //if (posPipe[i].y + PipeSpacing + move >= screenHeight - LandHeight) move = -move;
                posPipe[i].y += move;
            }
        }
    }
}


