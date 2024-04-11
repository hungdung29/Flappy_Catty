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

    void update(short int pipeWidth, short int pipeHeight);

    

private:
    short int angle, time, y0;
    short int v0 = -7;
    double acceleration = 0.36;
    short int onward = 0;
    string saved_path;
    position posCatty;
    
};