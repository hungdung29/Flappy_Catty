#include "add-ons.h"
#include "pipe.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <SDL_image.h>

bool appear = false;

bool Addons::Draw(){
    if (randAddons == 0) addons_path = lightning_path;
    if (randAddons == 1) addons_path = gravity_path;
    if (randAddons == 2) addons_path = stablity_path;

    if (saved_path == addons_path){
        posAddons.getPos (screenWidth + 4, screenWidth / 2);
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

void Addons::update(bool change)
{
    if (appear == true) {
        posAddons.x -= 3;
        posAddons.y = (screenHeight - LandHeight) / 2;
    }
    if (score % 10 == 1) appear = true;
    if (!change) appear = false;
    if (appear == false) {
        posAddons.x = screenWidth + 100;
    }
    if (appear == false && change) {        
        srand(time(0));
        randAddons = rand() % numAddons;
        Draw();
    }
}
