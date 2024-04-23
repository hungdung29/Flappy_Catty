#include "add-ons.h"
#include "pipe.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <SDL_image.h>


bool Addons::Draw(){
    int randAddons = rand() % numAddons;
    if (randAddons == 0) addons_path = heart_path;
    if (randAddons == 1) addons_path = lightning_path;
    if (randAddons == 2) addons_path = gravity_path;
    if (randAddons == 3) addons_path = stablity_path;

    if (saved_path == addons_path){
        if (score % 5 == 0) posAddons.getPos (posPipe[hiddenPipe].x, posPipe[hiddenPipe].y );
    }
    if (isNULL() || saved_path != addons_path){
        saved_path = addons_path;
        if ( (Load (addons_path.c_str(),1) ) ) return true;
        return false;
    }
    return false;
}

Addons::~Addons()
{
    gTexture::~gTexture();
}

void Addons::render() 
{
    Render (posAddons.x, posAddons.y);
}

void Addons::update()
{
    posAddons.x -= 3;
}
