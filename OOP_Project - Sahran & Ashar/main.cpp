#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LTexture.h"
//#include "Queue.h"
#include "Unit.h"
#include "Rastan.h"
#include"Bandit.h"
#include"GameScreen.h"
#include "Word.h"
#include "Character.h"
#include "Point.h"
//#include "Enemy.h"
//#include "Bullet.h"

//Pre defined screen width and height

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

LTexture gSpriteSheetTexture;
LTexture gFontSpriteSheet;

bool init();
bool loadMedia();
void close();

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{

		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{

			bool quit = false;                      //Main loop flag

			SDL_Event e;                            //Event handler

			long int frame = 0;                     //Current animation frame
	//		int bulletDelay = 0;

			/* initialize random seed: */
            srand (time(NULL));

            /* generate secret number between 1 and 10: */
            //int random = 0;

			//Queue objectList;

			Unit* rastan = new Rastan(&gSpriteSheetTexture, (float)SCREEN_WIDTH*0.35, (float)SCREEN_HEIGHT*0.75);  //Need to set positioning of Rastan according to the map
			//Unit* bandit = new Bandit(&gSpriteSheetTexture, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT*0.68);
			Unit* bandit = new Bandit(&gSpriteSheetTexture,(float)SCREEN_WIDTH + 50/*rastan->GetX()*/, /*rastan->GetY() - rastan->GetHeight()/2*/(float)SCREEN_HEIGHT*0.68);
			//Unit* enemy = NULL;
            //Unit* bullet = NULL;j
            //cout << "AWD" << endl;
            //Bandit b(&gSpriteSheetTexture, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2);
            GameScreen g (&gSpriteSheetTexture, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2);

			while( !quit )                          //While application is running
			{
			    /*
			    if(frame%60 == 0)
                {
                    random = rand() % SCREEN_WIDTH;
                    enemy = new Enemy(&gSpriteSheetTexture, random, 100);
                    objectList.Enqueue(enemy);
                }
                */
				while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}

				}

				const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

                    if(currentKeyStates[ SDL_SCANCODE_RIGHT ])
                    {
                        if (bandit -> GetX() != 450)
                        {
                            rastan -> Move(RIGHT);
                            g.MoveBackground();
                            bandit -> Move();
                            frame++;
                        }
                        else
                        {

                        }
                    }

/*
                    if(currentKeyStates[ SDL_SCANCODE_SPACE ])
                    {
                        if(bulletDelay > 3)
                        {
                            bullet = new Bullet(&gSpriteSheetTexture,plane->GetX(), plane->GetY() - plane->GetHeight()/2);
                            objectList.Enqueue(bullet);
                            bulletDelay = 0;
                            Unit(1);
                        }

                    }
*/
                //cout<<"AWD"<<endl;
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );    //Clear screen
				SDL_RenderClear( gRenderer );
/*
                objectList.Render(frame, gRenderer, false);
                objectList.Move();
*/

                g.Render(frame,gRenderer,true);
                rastan -> Render(frame, gRenderer, true);
                bandit -> Render(frame, gRenderer, true);
                //b.Render(frame, gRenderer, true);
                //rastan -> Move();

                //objectList.Clean();
				SDL_RenderPresent( gRenderer );       //Update screen

				//++frame;                            //Go to next frame
//				++bulletDelay;

			}
			delete rastan;
			delete bandit;
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Rastan's Epic Journey To Persia", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( !gSpriteSheetTexture.LoadFromFile( "image/collage.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

	if( !gFontSpriteSheet.LoadFromFile( "image/collage.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded images
	gSpriteSheetTexture.Free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
