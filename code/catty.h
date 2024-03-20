#pragma once

#include <SDL.h>
#include "lib.h"

class Catty:gTexture
{
public: 
    bool init();    

    void render();
    ~Catty();

    void fall();

    void HandleInput(SDL_Event &event);
    void UpdateTime();

    

private:
    short int angle, time ,x0;
    short int yVelocity;
    string saved_path;
    position posCatty;
    
};