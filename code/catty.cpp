#include "catty.h"
#include <SDL_image.h>

Catty::Catty(SDL_Renderer* renderer) : renderer(renderer), xPos(100), yPos(300), yVelocity(0) {
    SDL_Surface* surface = IMG_Load("res/image/catty.png");
    if (surface == nullptr){
        SDL_Log ("Error loading cat texture: %s", SDL_GetError());
    }
    else {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    xPos = 100;
    yPos = 300;
    yVelocity = 0;
}

Catty::~Catty() {
    SDL_DestroyTexture(texture);
}

void Catty::HandleInput(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
        yVelocity = -5.0f; 
    }
}

void Catty::Update(float deltaTime) {
    yPos += yVelocity * deltaTime;    
    yVelocity += 0.2f; 
}

void Catty::Draw() {
    SDL_Rect catRect = {static_cast<int>(xPos), static_cast<int>(yPos), catWidth, catHeight};
    SDL_RenderCopy(renderer, texture, nullptr, &catRect);
}
