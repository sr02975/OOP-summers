#pragma once
#include "Unit.h"

class Rastan:public Unit

{
private:
    //Health health;
    //foodNWaterSupplies foodNWater;
    //Weapon weapon;
protected:
    enum ANIMATION_FRAMES {MAIN_OBJECT = 3};
    //SDL_Rect spriteClips[ MAIN_OBJECT ];
    //LTexture* spriteSheetTexture;

public:
    Rastan();
    Rastan(LTexture* image, float x, float y);
    virtual ~Rastan();
    virtual void Move();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
};

