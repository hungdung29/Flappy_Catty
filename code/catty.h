#pragma once

#include <SDL.h>

class Catty
{
public: 
    Catty(SDL_Renderer* renderer);
    ~Catty();

    void HandleInput(SDL_Event &event);
    void Update(float deltaTime);
    void Draw();

private:
    static const int catWidth = 50;
    static const int catHeight = 35;
    
    float xPos, yPos;
    float yVelocity;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
};