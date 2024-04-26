#pragma once

#include <SDL_mixer.h>
#include <string>
#include "lib.h"

class SoundEffect: gTexture
{
public:
    bool Initialize();

    ~SoundEffect();

    void playBreath();
    void playHit();
    void playCat();

    void renderSound();

    bool checkSound();

private:
    const short int posX = 107;
    const short int posY = 267;
    bool isSound = 0;
    Mix_Chunk* breath = NULL;
    Mix_Chunk* hit = NULL;
    Mix_Chunk* cat = NULL;
    SDL_Rect Mute ;
    SDL_Rect Active ;
};