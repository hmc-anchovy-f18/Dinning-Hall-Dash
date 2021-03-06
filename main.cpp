#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#else
#include <SDL.h>
#endif

//#undef main //maybe needs to go above?
#include "string"
#include "CharacterSelect.hpp"
#include "EndScreen.hpp"
#include "GameState.hpp"
#include "LevelSelect.hpp"
#include "MainMenu.hpp"
#include "Map.hpp" 
#include "Player.hpp"
#include "PowerUp.hpp"
#include "ScoreBoard.hpp"
#include "Sound.hpp"
#include "SpeedDown.hpp"
#include "SpeedUp.hpp"
#include "StrengthUp.hpp"
#include "Vehicle.hpp"
#include "Screen.hpp"
//#include "stdlib.h"
using namespace std;

//Key press surfaces constants
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
     KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
    
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;

//Screen dimension constants
const int SCREEN_WIDTH = 750;
const int SCREEN_HEIGHT = 750;



bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "Dining Hall Dash Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( gScreenSurface );
    gScreenSurface = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

SDL_Surface* loadSurface( std::string path )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}
    else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}



bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load default surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "pictures/main.bmp" );
    
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
    {
        printf( "Failed to load main image!\n" );
        success = false;
    }

    //Load up surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( "pictures/start.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL )
    {
        printf( "Failed to load start image!\n" );
        success = false;
    }

    //Load down surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "pictures/about.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL )
    {
        printf( "Failed to load about image!\n" );
        success = false;
    }

        //Load left surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "pictures/score.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL )
    {
        printf( "Failed to load score image!\n" );
        success = false;
    }

    //Load right surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "pictures/exit.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
    {
        printf( "Failed to load exit image!\n" );
        success = false;
    }

    return success;
}

int main (int argc, char* args[]) {

    //Start up SDL and create window
    if(!init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if(!loadMedia())
        {
            printf( "Failed to load media!\n" );
        }
        else
        {   
        
            //Apply the image stretched
			SDL_Rect stretchRect;
			stretchRect.x = 0;
			stretchRect.y = 0;
			stretchRect.w = SCREEN_WIDTH;
			stretchRect.h = SCREEN_HEIGHT;
				//SDL_BlitScaled( gStretchedSurface, NULL, gScreenSurface, &stretchRect );

            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //Set default current surface
            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];

            //While application is running
            while( !quit )
            {
                 //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    //User presses a key
                    else if( e.type == SDL_KEYDOWN )
                    {
                        //Select surfaces based on key press
                        switch( e.key.keysym.sym )
                        {
                            default:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                            //Apply the current image
                            SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, &stretchRect );
                            //Update the surface
                            SDL_UpdateWindowSurface( gWindow );
                            break;


                            case SDLK_UP:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                            //Apply the current image
                            SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, &stretchRect );
                            //Update the surface
                            SDL_UpdateWindowSurface( gWindow );
                            break;

                            case SDLK_DOWN:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                            //Apply the current image
                            SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, &stretchRect );
                            //Update the surface
                            SDL_UpdateWindowSurface( gWindow );
                            break;
                            
                            case SDLK_LEFT:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                            //Apply the current image
                            SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, &stretchRect );
                            //Update the surface
                            SDL_UpdateWindowSurface( gWindow );
                            break;

                            case SDLK_RIGHT:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                            //Apply the current image
                            SDL_BlitSurface( gCurrentSurface, NULL , gScreenSurface, &stretchRect );
                            //Update the surface
                            SDL_UpdateWindowSurface( gWindow );
                            break;

                        }
                    }
                }

            }
        }
    }
    close();
    return 0;

}