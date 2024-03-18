#pragma once

#include <SDL.h>
#include "catty.h"
#include "pipe.h"

class Game {
public:
    static const short int numPipes = 4;
    static const short int screenWidth = 350;
    static const short int screenHeight = 625;
    static const short int pipeSpacing = 160;

    float deltaTime;
    
    Game();
    ~Game();

    void Run();

private:
    void Initialize();
    void ProcessInput();
    void Update();
    void Render();
    void Cleanup();

    SDL_Window* window;
    SDL_Renderer* renderer;
    Catty* catty;
    Pipe* pipes[numPipes];
};
