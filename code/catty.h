#pragma once

#include <SDL.h>
#include "lib.h"

class Catty:gTexture
{
public: 
    bool Draw();    

    void render();
    ~Catty();

    void fall();

    void HandleInput(SDL_Event &event);
    void UpdateTime() {time = 0};

    

private:
    short int angle, time ,x0;
    short int v0;
    short int acceleration;
    short int onward = 0;
    short int yVelocity;
    string saved_path;
    position posCatty;
    
};