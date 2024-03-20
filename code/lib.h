#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class position {
    public: 
        short int x, y, angle, state;
        void getPos(const short int x, const short int y);
};

class gTexture {
    
    public:
        gTexture();
        ~gTexture();

        bool isNULL();

        bool Load(string path, double scale = 1);

        short int getWidth();
        short int getHeight();

        void Render (short int x, short int y, short int angle = 0, SDL_Rect* clip = NULL, SDL_RendererFlip filp = SDL_FLIP_NONE);

        SDL_Texture* texture;
        static SDL_Window* window;
        static SDL_Renderer* renderer;
        static SDL_Event event;

        short int gWidth;
        short int gHeight;

        static const short int screenWidth = 350; //If screen ratio is 18:9, 350->300
        static const short int screenHeight = 625; //If screen ratio is 18:9, 625->600
        static const short int PipeSpacing = 160;
        static const short int TOTAL_PIPE = 5;
        static const short int PipeDistance = 220;
        static const short int CattyWidth = 50;
        static const short int CattyHeight = 35;
}