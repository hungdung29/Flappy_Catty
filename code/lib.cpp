#include <iostream>
#include "lib.h"

SDL_Window* gTexture::window = NULL;
SDL_Renderer* gTexture::renderer = NULL;
SDL_Event gTexture::event;
bool gTexture::die = true;
short int gTexture::score = 0;

gTexture::gTexture(){
    texture = NULL;
}

short int gTexture::getWidth() { return gWidth; }
short int gTexture::getHeight() { return gHeight; }

void gTexture::~gTexture(){
    if (texture != NULL) {
        SDL_DestroyTexture (texture);
        texture = NULL;
    }
}

void gTexture::Render (short int x, short int y, short int angle, SDL_Rect* clip, SDL_RendererFlip flip){
    SDL_Rect Rect_Render = {x, y, gWidth, gHeight};

    if (clip != NULL){
        Rect_Render.w = clip->w;
        Rect_Render.h = clip->h;
    }

    SDL_RenderCopyEx (renderer, texture, clip, &Rect_Render, angle, NULL, flip);    
}

bool gTexture::Load (string path, double scale){
    ~gTexture();

    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == NULL){        
        SDL_Log ("Error loading image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else {
        SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0x00, 0xFF, 0xFF));

        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture == NULL){
            SDL_Log ("Error creating texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        else {
            gWeight = (surface->w) * scale;
            gHeight = (surface->h) * scale;
        }

        SDL_FreeSurface (surface);
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return (texture != NULL);
}

bool gTexture::isNULL()
{
    if (texture == NULL) return true;
    return false;
}

void position::getPos(const short int x, const short int y)
{
    this->x = x;
    this->y = y;
}