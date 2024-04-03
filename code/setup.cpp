#include "setup.h"
#include "lib.h"
#include <iostream>

Setup::Setup(){
    Initialize();
    catty.Draw();
    pipe.Draw();
    land.Draw();
}

Setup::~Setup(){
    catty.~Catty();
    pipe.~Pipe();
    land.~Land();
    Cleanup();
}

bool Setup::Initialize(){
    SDL_Init( SDL_INIT_EVERYTHING );

    if (SDL_Init( SDL_INIT_VIDEO ) < 0)	{
		SDL_Log ( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return false;
	}
    else {
        SDL_Window *window = SDL_CreateWindow( "Flappy Catty", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );
        if (window == NULL) {
            SDL_Log ( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            return false;
        }
        else {
            renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == NULL){
                SDL_Log( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                return false;
            }
            else {
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

                IMG_Init(IMG_INIT_PNG);
                if (!IMG_Init (IMG_INIT_PNG)) {
                    SDL_Log ( "SDL_image couldn't initialize! SDL_image Error: %s\n", IMG_GetError() );
                    return false;
                }
            }
        }
    }

    return true;
}

void Setup::ProcessInput(bool &isRunning){
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        else return;            
    }
}

void Setup::Present(){
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}

void Setup::Cleanup(){
    SDL_DestroyWindow( window );
    window = NULL;
    SDL_DestroyRenderer( renderer );
    renderer = NULL;

    IMG_Quit();
    SDL_Quit();
}
void Setup::Restart(){
    die = false;
    score = 0;
    catty.UpdateTime();
} 

