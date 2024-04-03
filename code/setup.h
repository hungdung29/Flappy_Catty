#pragma once

#include "catty.h"
#include "pipe.h"
#include "land.h"
#include <string>
#include <fstream>

using namespace std;

class Setup: gTexture{
public: 
    Setup();
    ~Setup();

    bool Initialize();
    bool isDie() { return die; }

    void ProcessInput(bool &isRunning);
    //void Update();
    //void Render();
    void Cleanup();
    void Present();
    void Restart();

    Catty catty;
    Pipe pipe;
    Land land;


};