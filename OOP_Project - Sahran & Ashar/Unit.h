#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
//#include"GameScreen.h"

using namespace std;

enum MOTION {RIGHT};
enum TYPE {ENEMY,WEAPON};

class Unit
{
    private:

    protected:

        bool alive;
        int type;
        float x;
        float y;
        int width;
        int height;
        float speedx;
        float speedy;
        float friction;

        //enum ANIMATION_FRAMES {MAIN_OBJECT_FRAMES = 3};
        SDL_Rect* spriteClips;
        LTexture* spriteSheetTexture;

    public:

        Unit(LTexture* image, float x, float y);
        Unit();
        virtual ~Unit();
        void SetAlive(bool);
        bool GetAlive();
        int GetWidth();
        int GetHeight();
        float GetX();
        float GetY();
        virtual void Move(int direction);
        virtual void Move();
        virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug) = 0;
};

