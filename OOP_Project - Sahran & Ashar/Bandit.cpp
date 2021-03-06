#include "Bandit.h"

using namespace std;

Bandit::Bandit()
{
    //ctor
}


Bandit::~Bandit()
{
    cout << "Bandit deallocated" << endl;
}

Bandit::Bandit(LTexture* image, float x, float y):Unit(image,x,y)
{
    spriteClips = new SDL_Rect[4];
    //type= ENEMY;
    this->spriteSheetTexture = image;
    //spriteSheetTexture=image;

     //Frame 0
    spriteClips[ 0 ].x = 241;
    spriteClips[ 0 ].y = 4533;
    spriteClips[ 0 ].w = 85;
    spriteClips[ 0 ].h = 100;

    //Frame 1
    spriteClips[ 1 ].x = 355;
    spriteClips[ 1 ].y = 4533;
    spriteClips[ 1 ].w = 85;
    spriteClips[ 1 ].h = 100;

    //Frame 2
    spriteClips[ 2 ].x = 470;
    spriteClips[ 2 ].y = 4533;
    spriteClips[ 2 ].w = 85;
    spriteClips[ 2 ].h = 100;

     //Frame 3
    spriteClips[ 3 ].x = 919;
    spriteClips[ 3 ].y = 5129;
    spriteClips[ 3 ].w = 103;
    spriteClips[ 3 ].h = 63;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}

void Bandit::Move()
{
     if (x != 450)
     {
         x = x - 2;
     }

     /*else if (x == 450)
     {

     }*/

     if(x < -100)
     {
         SetAlive(false);
     }
}

void Bandit::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( x - width/4, y - height/4, &spriteClips[ frame % 3 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
