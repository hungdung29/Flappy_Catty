#include "sound_effect.h"

#include <stdio.h>
#include <iostream>
#include <string>

bool SoundEffect::Initialize()
{
    string breath_path = "res/sound/breath.wav";
    string hit_path = "res/sound/hit.wav";
    string cat_path = "res/sound/cat.wav";

    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        SDL_Log( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return false;
    }
    else
    {
        if( Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048) < 0 )
        {
            SDL_Log( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            return false;
        }

        breath = Mix_LoadWAV( breath_path.c_str() );
        if ( breath == NULL )
        {
            SDL_Log( "Failed to load sound! SDL_mixer Error: %s\n", breath_path.c_str(), Mix_GetError() );
            return false;
        }

        hit = Mix_LoadWAV( hit_path.c_str() );
        if (hit == NULL)
        {
            SDL_Log( "Failed to load sound! SDL_mixer Error: %s\n", hit_path.c_str(), Mix_GetError() );
            return false;
        }

        cat = Mix_LoadWAV( cat_path.c_str() );
        if (cat == NULL)
        {
            SDL_Log( "Failed to load sound! SDL_mixer Error: %s\n", hit_path.c_str(), Mix_GetError() );
            return false;
        }

        if (!Load("res/image/sound.png", 1))
        {
            return false;
        }
        
        Active.x = 0; 
        Active.y = 0; 
        Active.w = getWidth(); 
        Active.h = getHeight() / 2;

        Mute.x = 0; 
        Mute.y = getHeight() / 2; 
        Mute.w = getWidth(); 
        Mute.h = getHeight() / 2;

        isSound = true;
    }
    return true;
}

SoundEffect:: ~SoundEffect()
{
    gTexture::~gTexture();

    Mix_FreeChunk(breath);
    breath = NULL;
    Mix_FreeChunk(hit);
    hit = NULL;

    Mix_Quit();
}

void SoundEffect::playBreath()
{
    if (isSound) Mix_PlayChannel( -1, breath, 0 );    
}

void SoundEffect::playHit()
{
    if (isSound) Mix_PlayChannel(-1, hit, 0);
}

void SoundEffect::playCat()
{
    if (isSound) Mix_PlayChannel(-1, cat, 0);
}


void SoundEffect::renderSound()
{
    if (isSound)
    {
        Render(posX, posY, 0, &Active);
    }
    else
    {
        Render(posX, posY, 0, &Mute);
    }
}

bool SoundEffect::checkSound()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x > posX && x < posX + getWidth() &&  y > posY && y < posY + getHeight())
    {
        isSound = !isSound;
        return true;
    }
    return false;
}
