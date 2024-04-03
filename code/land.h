#pragma once

#include "lib.h"
#include <SDL.h>

class Land : gTexture{
public:
    bool Draw();
    ~Land();
    void render();

    void update();

private:
    position posLand;
};