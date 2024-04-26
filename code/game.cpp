#include <SDL.h>
#include "game.h"
#include "lib.h"
#include <iostream>

using namespace std;

Game::Game(){

}

Game::~Game(){
    gTexture::~gTexture();
}

void Game::Run() {
    bool isRunning = true;
    bool isMenu = 0;
    bool isPause = 0;
    bool isAddons = 0;
    bool Mute = 0;
    Uint32 ticks;
    short int frameTime;

    Setup s;

    while (isRunning) {
        ticks = SDL_GetTicks();
        if (die){
            if (isMenu) {
                s.catty.render();
                s.renderHeart();
                s.renderHeartNum();
                s.soundEffect.playHit();
            }
            s.userInput.Type = Setup::input::NONE;
            while (die && isRunning){
                s.ProcessInput(isRunning);
                if (isMenu == 1 && s.userInput.Type == Setup::input::PLAY)
                {
                    if (s.checkReplay()) isMenu = 0;
                    s.userInput.Type = Setup::input::NONE;
                }

                s.renderBackground();
                
                s.pipe.render();
                s.land.render();
                s.renderHeart();
                s.renderHeartNum();

                if (isMenu) {
                    s.catty.render();
                    s.catty.fall();
                    s.renderGameOver();
                    s.renderScoreSmall();
                    s.renderBestScore();
                    s.replay();
                }
                else {
                    heart = 3;
                    s.pipe.Draw();
                    s.catty.Draw();
                    s.catty.render();
                    s.renderMessage();
                    if (s.userInput.Type == Setup::input::PLAY) {
                        s.Restart();
                        isAddons = 0;
                        isMenu = 1;
                        s.userInput.Type = Setup::input::NONE;
                    }
                    s.land.update();
                }              
                
                s.Present();
            }
            s.pipe.Draw();
        }
        else {
            s.ProcessInput(isRunning);
            
            if (s.userInput.Type == Setup::input::PAUSE)
            {
                isPause = !isPause;
                s.userInput.Type = Setup::input::NONE;
            }

            if (isPause == 0 && s.userInput.Type == Setup::input::PLAY){
                if (!Mute && !isAddons) s.soundEffect.playBreath();
                if (!Mute && isAddons) s.soundEffect.playCat();
                s.catty.UpdateTime();
                s.userInput.Type = Setup::input::NONE;
            }

            s.renderBackground();
                  
            s.catty.render();
            s.pipe.render();
            s.land.render();
            if (appear) s.addons.render();
            s.renderHeart();
            s.renderHeartNum();
            s.renderScoreLarge();
            if (score % 10 == 7) {                
                if (s.addons.randAddons == 0 && isAddons == true) {s.pipe.Draw();}
                isAddons = false;
                s.updatetobeNormal();
            }
            if (!isPause){
                s.addons.update(!isAddons);
                if (s.checkAddons()) {isAddons = true; appear = false;}
                s.catty.update(s.pipe.width(),s.pipe.height());
                if (isAddons) s.updatebyAddons();
                s.pipe.update();
                s.land.update();
                s.pause();
            }
            else {
                s.resume();
                s.renderPauseTab();
                s.renderScoreSmall();
                s.renderBestScore();
                s.replay();
                s.nextButton();
                s.soundEffect.renderSound();
                if (s.userInput.Type == Setup::input::PLAY)
                {
                    if (s.checkReplay()) isPause = 0;
                    else if (s.soundEffect.checkSound()) Mute = !Mute;
                    s.userInput.Type = Setup::input::NONE;
                }    
            }
            if (die && heart) {
                die = false;
                heart--;
                onward = (onward + 1) % numPipes;
            }
            
            s.Present();
            

        }

        frameTime = SDL_GetTicks() - ticks;
        if (frameDelay > frameTime) SDL_Delay (frameDelay - frameTime);

    }
}



