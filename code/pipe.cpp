#include "pipe.h"
#include <SDL_image.h>
#include <cstdlib> 

Pipe::Pipe(SDL_Renderer* renderer, float x) : renderer(renderer), xPos(x), yPos(0), xVelocity(-2.0f) {
    SDL_Surface* surface = IMG_Load("res/image/pipe.png");
    if (surface == nullptr){
        SDL_Log ("Error loading cat texture: %s", SDL_GetError());
    }
    else {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    xPos = 100;
    yPos = 300;
    xVelocity = -2.0f;


}

Pipe::~Pipe() {
    SDL_DestroyTexture(texture);    
}

void Pipe::Update(float deltaTime) {
    // Update position based on velocity
    xPos += xVelocity * deltaTime;

    // Check if the pipe is off-screen, then reset its position
    if (xPos + pipeWidth < 0) {
        ResetPipePosition();
        // Randomize the height of the pipe or implement a fixed pattern
    }
}

void Pipe::Draw() {
    SDL_Rect pipeRect = {static_cast<int>(xPos), static_cast<int>(yPos), pipeWidth, pipeHeight};
    SDL_RenderCopy(renderer, texture, nullptr, &pipeRect);
}

void Pipe::ResetPipePosition(){

    xPos = 350;
    yPos = rand() % (screenHeight - pipeHeight);
}
