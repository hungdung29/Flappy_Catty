#include "catty.h"

Catty::Catty(SDL_Renderer* renderer) : renderer(renderer), xPos(100), yPos(300), yVelocity(0) {

}

Catty::~Catty() {

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
    
}
