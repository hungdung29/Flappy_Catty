#pragma once

#include "add-ons.h"
#include "catty.h"
#include "pipe.h"
#include "land.h"
#include "sound_effect.h"
#include <string>
#include <fstream>

using namespace std;

class Setup: gTexture{
public: 
    struct input
    {
        enum type {QUIT, PLAY, NONE, PAUSE};
        type Type;
    };
    input userInput;

    Setup();
    ~Setup();

    bool Initialize();

    void ProcessInput(bool &isRunning);
    
    void renderScoreSmall();

    void renderScoreLarge();

    void renderBestScore();

    void renderMessage();

    void renderBackground();

    void renderBackgroundNight();

    void renderLand();

    void resume();

    void pause();

    void renderPauseTab();

    void nextButton();

    bool changeTheme();

    void renderGameOver();

    void replay();

    bool checkReplay();
    bool checkPause();

    void updatebyAddons();
    void updatetobeNormal();
    bool checkAddons();

    void renderHeart();

    void renderHeartNum();

    void Cleanup();
    void Present();
    void Restart();

    Catty catty;
    Pipe pipe;
    Land land;
    Addons addons;
    SoundEffect soundEffect;

private: 
    const double scaleNumberS = 0.75;
    short int bestScore;

};