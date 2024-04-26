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

    short int width() {return getWidth();}
    short int height() {return getHeight();}
    
    void UpdateTime() {time = 0;}

    void update(short int pipeWidth, short int pipeHeight);

    double acceleration = 0.36;
    position posCatty;

private:
    short int angle, time, y0;
    short int v0 = -7;
    string saved_path;  
    
};
extern short int onward;