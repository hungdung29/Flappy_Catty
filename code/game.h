#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "lib.h"
#include "catty.h"
#include "pipe.h"
#include "setup.h"

#include <stdlib.h>

class Game {
public:
    Game();
    ~Game();

    void Run();
private:
    const short int FPS = 60;
    const short int frameDelay = 1000 / FPS;    
};
