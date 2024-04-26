#pragma once

#include "lib.h"
#include <SDL.h>

class Background : gTexture
{
public:
    bool Draw(bool isDark);
    ~Background();
    void render();

    void update();

private:
    position posBackground;
    string saved_path;
};