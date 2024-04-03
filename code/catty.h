#pragma once

#include <SDL.h>
#include "lib.h"
#include "pipe.h"

class Catty:gTexture
{
public: 
    bool Draw();    

    void render();
    ~Catty();

    void fall();

    
    void UpdateTime() {time = 0;}

    void check(short int pipeWidth, short int pipeHeight);

    

private:
    short int angle, time ,x0;
    short int v0;
    short int acceleration;
    short int onward = 0;
    short int yVelocity;
    string saved_path;
    position posCatty;
    
};