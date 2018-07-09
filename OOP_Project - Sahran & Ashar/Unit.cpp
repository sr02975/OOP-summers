#include "Unit.h"

Unit::Unit()
{

}

Unit::Unit(LTexture* image, float x, float y)
{

    spriteClips[ 0 ].x = 185;
    spriteClips[ 0 ].y = 636;
    spriteClips[ 0 ].w = 40;
    spriteClips[ 0 ].h = 40;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    alive  = true;
}


Unit::~Unit()
{
    spriteSheetTexture = NULL;
}

void Unit::SetAlive(bool alive)
{
    this -> alive = alive;
}

bool Unit::GetAlive()
{
    return alive;
}

void Unit::Move(int direction)
{
    if(direction==RIGHT)
    {
    //Frame 0
    spriteClips[ 0 ].x = 185;
    spriteClips[ 0 ].y = 636;
    spriteClips[ 0 ].w = 40;
    spriteClips[ 0 ].h = 40;

    //Frame 1
    spriteClips[ 1 ].x = 185;
    spriteClips[ 1 ].y = 672;
    spriteClips[ 1 ].w = 40;
    spriteClips[ 1 ].h = 40;

    //Frame 2
    spriteClips[ 2 ].x = 185;
    spriteClips[ 2 ].y = 132;
    spriteClips[ 2 ].w = 40;
    spriteClips[ 2 ].h = 40;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    }
}

void Unit::Move()
{

}

void Unit::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % MAIN_OBJECT_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

int Unit::GetWidth()
{
    return width;
}

int Unit::GetHeight()
{
    return height;
}

float Unit::GetX()
{
    return x;
}
float Unit::GetY()
{
    return y;
}
