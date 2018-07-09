#include "GameScreen.h"

GameScreen::GameScreen(LTexture* image, float x, float y)//:Unit(image,x,y)
{
    spriteSheetTexture = image;

    spriteClips.x = 0;
    spriteClips.y = 2829;
    spriteClips.w = 800;
    spriteClips.h = 600;



    this->x = x;
    this->y = y;

    this->width = spriteClips.w;
    this->height = spriteClips.h;
}

GameScreen::~GameScreen()
{
    //dtor
}

void GameScreen::MoveBackground()
{
    if(spriteClips.x+800!=1020)
    {
        spriteClips.x+=2;

    }
    else
    {
        spriteClips.x=120;
        spriteClips.x+=2;
    }
}




void GameScreen::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture -> Render( x - width/2, y - height/2, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

/**void GameScreen::Move()
{

}
**/
/**
GameScreen::GameScreen()
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;

    spriteSheetTexture = image;

    spriteClips[0].x = 0;
    spriteClips[0].y = 3429;
    spriteClips[0].w = 800;
    spriteClips[0].h = 600;



    this->x = x;
    this->y = y;

    this->width = spriteClips[0].w;
    this->height = spriteClips[0].h;


}

void GameScreen::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
	if( e.type == SDL_SCANCODE_RIGHT && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= DOT_VEL; break;
            case SDLK_DOWN: mVelY += DOT_VEL; break;
            case SDLK_LEFT: mVelX -= DOT_VEL; break;
            case SDLK_RIGHT: mVelX += DOT_VEL; break;
        }
    }
    //If a key was released
    /**else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += DOT_VEL; break;
            case SDLK_DOWN: mVelY -= DOT_VEL; break;
            case SDLK_LEFT: mVelX += DOT_VEL; break;
            case SDLK_RIGHT: mVelX -= DOT_VEL; break;
        }
    }
}

void GameScreen::Move()
{
    //Move the dot left or right
    mPosX += mVelX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }

    //Move the dot up or down
    mPosY += mVelY;

    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        mPosY -= mVelY;
    }
}

void GameScreen::render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture -> Render( mPosX, mPosY, &spriteClips[frame % MAIN_OBJECT_FRAMES], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }

}**/

