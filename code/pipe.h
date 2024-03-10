#pragma once

#include <SDL.h>

class Pipe {
public:
    Pipe(SDL_Renderer* renderer, float x);
    ~Pipe();

    void Update(float deltaTime);
    void Draw();

private:
    float xPos, yPos;
    float xVelocity;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
};

extern const int pipeWidth;
extern const int screenWidth;