#include <SDL.h>
#include "game.h"

Game::Game() {
    Initialize();
}

Game::~Game() {
    Cleanup();
}

void Game::Initialize() {
    // Initialize SDL, create window, renderer, and load resources
    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *window = SDL_CreateWindow( "Flappy Catty", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_ALLOW_HIGHDPI );

    if ( NULL == window )
    {
        cout << "Could not create window" << SDL_GetError() << endl;
        return 1;
    }

    SDL_Event windowEvent;

    while ( true )
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( SDL_QUIT == windowEvent.type )
            { break; }
        }
    }
    catty = new Catty(renderer);

    for (int i = 0; i < numPipes; ++i) {
        pipes[i] = new Pipe(renderer, screenWidth + i * pipeSpacing);
    }
}

void Game::Run() {
    bool isRunning = true;
    SDL_Event event;

    while (isRunning) {

        Uint32 ticks = SDL_GetTicks();
        static Uint32 lastTicks = ticks;
        deltaTime = (ticks - lastTicks) / 1000.0f;
        lastTicks = ticks;

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }

            catty->HandleInput(event);
        }

        ProcessInput();
        Update();
        Render();
    }
}

void Game::ProcessInput() {
    // Process any other input if needed
}

void Game::Update() {
    catty->Update(deltaTime);

    for (int i = 0; i < numPipes; ++i) {
        pipes[i]->Update(deltaTime);

        // Check for collision between bird and pipes
    }

    // Check for game-over conditions
}

void Game::Render() {
    // Clear the screen

    catty->Draw();

    for (int i = 0; i < numPipes; ++i) {
        pipes[i]->Draw();
    }

    // Render any other UI or game elements

    // Present the renderer
}

void Game::Cleanup() {
    // Release resources and close SDL
    SDL_DestroyWindow( window );
    SDL_Quit( );
}
