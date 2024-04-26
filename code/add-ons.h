#pragma once

#include <SDL.h>
#include "lib.h"
#include "catty.h"
#include "pipe.h"

class Addons: gTexture
{
    const short int numAddons = 3;    
    string saved_path;
public: 
    bool Draw();
    ~Addons();

    short int width() {return getWidth();}
    short int height() {return getHeight();}
    
    void render();
    void update(bool change);

    string lightning_path = "res/image/lightning.png";
    string gravity_path = "res/image/gravity.png";
    string stablity_path = "res/image/stablity.png";
    string addons_path;

    position posAddons;
    short int randAddons = rand() % numAddons;
};
extern bool appear;