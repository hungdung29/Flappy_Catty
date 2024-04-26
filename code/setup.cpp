#include "setup.h"
#include "lib.h"
#include <iostream>



Setup::Setup(){
    Initialize();
    addons.Draw();
    catty.Draw();
    pipe.Draw();
    land.Draw();
}

Setup::~Setup(){
    Cleanup();
}

bool Setup::Initialize(){
    SDL_Init( SDL_INIT_EVERYTHING );

    if (SDL_Init( SDL_INIT_VIDEO ) < 0)	{
		SDL_Log ( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return false;
	}
    else {
        SDL_Window *window = SDL_CreateWindow( "Flappy Catty", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );
        if (window == NULL) {
            SDL_Log ( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            return false;
        }
        else {
            renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == NULL){
                SDL_Log( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                return false;
            }
            else {
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

                IMG_Init(IMG_INIT_PNG);
                if (!IMG_Init (IMG_INIT_PNG)) {
                    SDL_Log ( "SDL_image couldn't initialize! SDL_image Error: %s\n", IMG_GetError() );
                    return false;
                }
            }
        }
    }

    return true;
}

void Setup::ProcessInput(bool &isRunning){
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT)
        {
            userInput.Type = input::QUIT;
            isRunning = false;
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN && checkPause()) userInput.Type = input::PAUSE;
        else if (event.type == SDL_MOUSEBUTTONDOWN || (event.type == SDL_KEYDOWN && 
		(event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_UP) && event.key.repeat == 0) )
        {
            userInput.Type = input::PLAY;
        }
		else if ((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE && event.key.repeat == 0))
		{
			userInput.Type = input::PAUSE;
		}           
    }
}

void Setup::Present(){
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}

void Setup::Cleanup(){
    SDL_DestroyWindow( window );
    window = NULL;
    SDL_DestroyRenderer( renderer );
    renderer = NULL;

    IMG_Quit();
    SDL_Quit();
}
void Setup::Restart(){
    die = false;
    appear = false;
    updatetobeNormal();
    heart = 3;
    score = 0;
    catty.UpdateTime();
} 

void Setup::renderScoreSmall()
{
	string s = to_string(score);
	signed char len = s.length();
	gTexture image;

	for (signed char i = len - 1; i >= 0; i--)
	{
		signed char number = s[i] - '0';
		if (number == 1)
		{
			image.Load("res/number/small/1.png", scaleNumberS);
		}
		else if (number == 2)
		{
			image.Load("res/number/small/2.png", scaleNumberS);
		}
		else if (number == 3)
		{
			image.Load("res/number/small/3.png", scaleNumberS);
		}
		else if (number == 4)
		{
			image.Load("res/number/small/4.png", scaleNumberS);
		}
		else if (number == 5)
		{
			image.Load("res/number/small/5.png", scaleNumberS);
		}
		else if (number == 6)
		{
			image.Load("res/number/small/6.png", scaleNumberS);
		}
		else if (number == 7)
		{
			image.Load("res/number/small/7.png", scaleNumberS);
		}
		else if (number == 8)
		{
			image.Load("res/number/small/8.png", scaleNumberS);
		}
		else if (number == 9)
		{
			image.Load("res/number/small/9.png", scaleNumberS);
		}
		else
		{
			image.Load("res/number/small/0.png", scaleNumberS);
		}
		image.Render(260 - image.getWidth() * (len - i - 1) * 0.75 - 5 * (len - i - 1), 268);
	}
	image.~gTexture();
}

void Setup::renderScoreLarge()
{
    string s = to_string(score);
	signed char len = s.length();
	gTexture image;

	for (signed char i = 0; i < len; i++)
	{
		signed char number = s[i] - '0';
		if (number == 1)
		{
			image.Load("res/number/large/1.png", 1);
		}
		else if (number == 2)
		{
			image.Load("res/number/large/2.png", 1);
		}
		else if (number == 3)
		{
			image.Load("res/number/large/3.png", 1);
		}
		else if (number == 4)
		{
			image.Load("res/number/large/4.png", 1);
		}
		else if (number == 5)
		{
			image.Load("res/number/large/5.png", 1);
		}
		else if (number == 6)
		{
			image.Load("res/number/large/6.png", 1);
		}
		else if (number == 7)
		{
			image.Load("res/number/large/7.png", 1);
		}
		else if (number == 8)
		{
			image.Load("res/number/large/8.png", 1);
		}
		else if (number == 9)
		{
			image.Load("res/number/large/9.png", 1);
		}
		else 
		{
			image.Load("res/number/large/0.png", 1);
		}
		image.Render((screenWidth - (image.getWidth() * len + (len - 1) * 10)) / 2 + (i + 30) * i, 100);
	}
	image.~gTexture();
}

void Setup::renderBestScore()
{
	ifstream fileIn("res/data/bestScore.txt");
	fileIn >> bestScore; 
	ofstream fileOut("res/data/bestScore.txt", ios::trunc);

	if (score > bestScore)
	{
		bestScore = score;
	}
	string s = to_string(bestScore);
	signed char len = s.length();
	gTexture image;

	for (signed char i = len-1; i >= 0; i--)
	{
		signed char number = s[i] - '0';
		if (number == 1)
		{
			image.Load("res/number/small/1.png", scaleNumberS);
		}
		else if (number == 2)
		{
			image.Load("res/number/small/2.png", scaleNumberS);
		}
		else if (number == 3)
		{
			image.Load("res/number/small/3.png", scaleNumberS);
		}
		else if (number == 4)
		{
			image.Load("res/number/small/4.png", scaleNumberS);
		}
		else if (number == 5)
		{
			image.Load("res/number/small/5.png", scaleNumberS);
		}
		else if (number == 6)
		{
			image.Load("res/number/small/6.png", scaleNumberS);
		}
		else if (number == 7)
		{
			image.Load("res/number/small/7.png", scaleNumberS);
		}
		else if (number == 8)
		{
			image.Load("res/number/small/8.png", scaleNumberS);
		}
		else if (number == 9)
		{
			image.Load("res/number/small/9.png", scaleNumberS);
		}
		else
		{
			image.Load("res/number/small/0.png", scaleNumberS);
		}
		image.Render(260 - image.getWidth()*(len-i-1)*0.75 - 5*(len - i - 1), 315);
	}
	image.~gTexture();

	fileOut << bestScore; 
	fileIn.close();
	fileOut.close();
}

void Setup::renderMessage()
{
	gTexture image;
	image.Load("res/image/message.png", 1);
	image.Render((screenWidth - image.getWidth()) / 2, 155);
	image.~gTexture();
}

void Setup::renderBackground()
{
	gTexture image;
	image.Load("res/image/background.png", 1);
	image.Render(0, 0);
	image.~gTexture();
}

void Setup::renderBackgroundNight()
{
	gTexture image;
	image.Load("res/image/background-night.png", 1);
	image.Render(0, 0);
	image.~gTexture();
}

void Setup::renderLand()
{
	gTexture image;
	image.Load("res/image/land.png", 1);
	image.Render((screenWidth - image.getWidth()) / 2, screenHeight- image.getHeight());
	image.~gTexture();
}

void Setup::resume()
{
	gTexture image;
	image.Load("res/image/resume.png", 1);
	image.Render(screenWidth - 50, 20);
	image.~gTexture();
}

void Setup::pause()
{
	gTexture image;
	image.Load("res/image/pause.png", 1);
	image.Render(screenWidth - 50, 20);
	image.~gTexture();
}

void Setup::renderPauseTab()
{
	gTexture image;
	image.Load("res/image/pauseTab.png", 1);
	image.Render((screenWidth - image.getWidth()) / 2, 230);
	image.~gTexture();
}

void Setup::nextButton()
{
	gTexture image;
	image.Load("res/image/nextRight.png", 1);
	image.Render(149, 322);
	image.Load("res/image/nextLeft.png", 1);
	image.Render(88, 322);
	image.~gTexture();
}

bool Setup::changeTheme()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (((x > 149 && x < 149+13)  || (x > 88 && x < 88 + 13)) && (y > 322 && y < 322 + 16))
	{
		return true;
	}
	return false;
}

void Setup::renderGameOver()
{
	gTexture image;
	image.Load("res/image/gameOver.png", 1);
	image.Render((screenWidth - image.getWidth()) / 2, 150);
	image.~gTexture();
}

void Setup::replay()
{
	gTexture image;
	image.Load("res/image/replay.png", 1);
	image.Render((screenWidth - image.getWidth()) / 2, 380);
	image.~gTexture();
}

bool Setup::checkReplay()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x > (screenWidth - 100)/2 && x < (screenWidth + 100) / 2 && y > 380 && y < 380 + 60)
	{
		return true;
	}
	return false;
}

bool Setup::checkPause()
{
    int x, y;
	SDL_GetMouseState(&x, &y);
	if (x > screenWidth - 50 && x < screenWidth - 50 + 26 && y > 20 && y < 20 + 28)
	{
		return true;
	}
	return false;
}

void Setup::updatebyAddons()
{
    if (addons.randAddons == 0){
        pipe.pipeMove = 30;
        die = false;
    }
    if (addons.randAddons == 1) {
        catty.acceleration = 0.36 * 1.25;
    }
    if (addons.randAddons == 2) {
        pipe.move = 0;
    }
}

void Setup::updatetobeNormal(){
    pipe.pipeMove = 3;
    catty.acceleration = 0.36;
    pipe.move = 3;
}


bool Setup::checkAddons()
{
    if (catty.posCatty.x + catty.width() > addons.posAddons.x && catty.posCatty.x < addons.posAddons.x + addons.width()
     && catty.posCatty.y + catty.height() > addons.posAddons.y && catty.posCatty.y < addons.posAddons.y+ addons.height()) 
    {
        return true; 
        appear = false;
    }
    return false;
}

void Setup::renderHeart()
{
	gTexture image;
	image.Load("res/number/small/heart.png", 1);
	image.Render(20, 20);
	image.~gTexture();
}

void Setup::renderHeartNum()
{
    string s = to_string(heart);
	signed char len = s.length();
	gTexture image;

	for (signed char i = 0; i < len; i++)
	{
		signed char number = s[i] - '0';
		if (number == 1)
		{
			image.Load("res/number/small/1.png", 1);
		}
		else if (number == 2)
		{
			image.Load("res/number/small/2.png", 1);
		}
		else if (number == 3)
		{
			image.Load("res/number/small/3.png", 1);
		}
		else if (number == 4)
		{
			image.Load("res/number/small/4.png", 1);
		}
		else if (number == 5)
		{
			image.Load("res/number/small/5.png", 1);
		}
		else if (number == 6)
		{
			image.Load("res/number/small/6.png", 1);
		}
		else if (number == 7)
		{
			image.Load("res/number/small/7.png", 1);
		}
		else if (number == 8)
		{
			image.Load("res/number/small/8.png", 1);
		}
		else if (number == 9)
		{
			image.Load("res/number/small/9.png", 1);
		}
		else
		{
			image.Load("res/number/small/0.png", 1);
		}
		image.Render(20 + 34 + 5 + image.getWidth() * i + 2 * i, 20); //Heart_Weight = 34;
	}
	image.~gTexture();
}