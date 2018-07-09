#pragma once
#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include "Unit.h"


class GameScreen: public Unit
{
    public:
        GameScreen(LTexture* image, float x, float y);
        ~GameScreen();
        //virtual ~GameScreen();
        //virtual void Move();
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        int getX();
        void MoveBackground();


    protected:
        enum ANIMATION_FRAMES_SCREEN {MAIN_OBJECT = 1};
        SDL_Rect spriteClips;
        LTexture* spriteSheetTexture;

    private:

};
/**

class GameScreen: public Unit
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 800;
		static const int DOT_HEIGHT = 600;
		GameScreen();
        //~GameScreen();

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 10;

		//Initializes the variables
		//GameScreen();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot
		void Move();

		//Shows the dot on the screen
		void render(long int&, SDL_Renderer*,bool);

    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;
		SDL_Rect spriteClips;
        LTexture* spriteSheetTexture;
};
**/

#endif // GAMESCREEN_H
