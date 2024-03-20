#pragma once

#include <SDL.h>

class Pipe{
public:
    Pipe(SDL_Renderer* renderer, float x);
    ~Pipe();

    void Update(float deltaTime);
    void Draw();

    void ResetPipePosition();

private:
    static const int pipeWidth = 50;
    static const int pipeHeight = 400;
    static const int pipeDistance = 220;
    static const int screenHeight = 625;
    static const int screenWidth = 350;

    float xPos, yPos;
    float xVelocity;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
};

extern const int pipeWidth;
extern const int screenWidth;