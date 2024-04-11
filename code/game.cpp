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
        // ticks = SDL_GetTicks();
        if (s.isDie()){
            s.userInput.Type = Setup::input::NONE;
            while (s.isDie() && isRunning){
                s.ProcessInput(isRunning);

                s.land.render();
                s.pipe.render();

                s.pipe.Draw();
                s.catty.Draw();
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
            if (currentKeyStates[SDL_SCANCODE_UP] || currentKeyStates[SDL_SCANCODE_SPACE]){
                s.catty.UpdateTime();
            }
                  
            s.catty.render();
            s.pipe.render();
            s.land.render();
            
            s.catty.update(s.pipe.width(),s.pipe.height());
            s.pipe.update();
            s.land.update();

            if (s.isDie()) s.catty.fall();

            s.Present();

        }

        // frameTime = SDL_GetTicks() - ticks;
        // if (frameDelay > frameTime) SDL_Delay (frameDelay - frameTime);
        SDL_Delay(16);

        
    }
}



