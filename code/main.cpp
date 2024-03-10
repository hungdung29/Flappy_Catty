#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "game.h"

using namespace std;
const int WIDTH = 350, HEIGHT = 625;

int main( int argc, char *argv[] )
{
    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *window = SDL_CreateWindow( "Flappy Catty", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );

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
    Game game;
    game.Run();

    SDL_DestroyWindow( window );
    SDL_Quit( );

    return EXIT_SUCCESS;

}