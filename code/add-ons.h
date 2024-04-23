#pragma once

#include <SDL.h>
#include "lib.h"
#include "pipe.h"

class Addons: gTexture
{
    const int numAddons = 4;    
    string addons_path, saved_path;
    position posAddons;
public: 
    bool Draw();
    ~Addons();
    
    void render();
    void update();

    string heart_path = "res/image/heart.png";
    string lightning_path = "res/image/lightning.png";
    string gravity_path = "res/image/gravity.png";
    string stablity_path = "res/image/stablity.png";
};