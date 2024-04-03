#include <SDL.h>
#include "game.h"
#include "lib.h"
#include <iostream>

using namespace std;

Game::Game(){

}

Game::~Game(){

}

void Game::Run() {
    bool isRunning = true;
    Uint32 ticks;
    
    short int frameTime;

    Setup s;

    while (isRunning) {
        ticks = SDL_GetTicks();
        if (s.isDie()){
            while (s.isDie() && isRunning){
                s.ProcessInput(isRunning);
                s.land.render();
                s.pipe.render();

                s.pipe.Draw();
                s.catty.render();
                
                s.Restart();

                s.land.update();
                s.Present();
            }
            s.pipe.Draw();
        }
        else {
            s.ProcessInput(isRunning);

            const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
            
            s.pipe.render();
            s.land.render();
            
            s.pipe.update();
            s.land.update();

            s.Present();

        }

        frameTime = SDL_GetTicks() - ticks;
        if (frameDelay > frameTime) SDL_Delay (frameDelay - frameTime);

        
    }
}



