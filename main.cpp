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
#include "PlayerOne.hpp"
#include "PlayerTwo.hpp"
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

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

SDL_Surface* gStretchedSurface = NULL;

int Width, Height;

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

//load media PART 2
SDL_Surface *IMG_Load(const char *file);

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface( std::string path );

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		SDL_DisplayMode DM;
		SDL_GetCurrentDisplayMode(0, &DM);

		Width = DM.w;
		Height = DM.h;

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load default surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "pictures/start.png" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    //Load up surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( "pictures/start.png" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL )
    {
        printf( "Failed to load up image!\n" );
        success = false;
    }

    //Load down surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "pictures/about.png" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL )
    {
        printf( "Failed to load down image!\n" );
        success = false;
    }

    //Load left surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "04_key_presses/left.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL )
    {
        printf( "Failed to load left image!\n" );
        success = false;
    }

    //Load right surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "04_key_presses/right.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
    {
        printf( "Failed to load right image!\n" );
        success = false;
    }

    return success;
}

// bool loadMedia()
// {
// 	//Loading success flag
// 	bool success = true;

// 	//Load splash image
// 	gHelloWorld = SDL_LoadBMP("pictures/main.bmp");
// 	if (gHelloWorld == NULL)
// 	{
// 		printf("Unable to load image! SDL Error: %s\n", SDL_GetError());
// 		success = false;
// 	}
// 	return success;
// }

void close()
{
	// //Deallocate surface
	// SDL_FreeSurface(gHelloWorld);
	// gHelloWorld = NULL;

	// //Destroy window
	// SDL_DestroyWindow(gWindow);
	// gWindow = NULL;
	std::cout << "In close.\n";
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	// //Quit SDL subsystems
	// SDL_Quit();

}






SDL_Surface* loadSurface(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface;
}

int main(int argc, const char* argv[])
{
	SDL_Event event;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    SDL_Window *window = NULL;

    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(
        500, 500,
        0, &window, &renderer
    );
    IMG_Init(IMG_INIT_PNG);
    texture = IMG_LoadTexture(renderer, "pictures/main.png");
    while (1) {
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }
    SDL_DestroyTexture(texture);
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;


	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			bool quit = false;  //Main loop controller
			SDL_Event e;
			SDL_Rect stretchRect;
			stretchRect.x = 0;
			stretchRect.y = 0;
			stretchRect.w = Width;
			stretchRect.h = Height;
			int count = 0;
			while (!quit) {
				//Handle events on queue
				while (!SDL_PollEvent(&e)) {
					// != 0
					//User requests quit
					if (e.type == SDL_QUIT) {
						std::cout << "Setting quit to true.\n";
						quit = true;
						cout << quit << endl;
					}
					//User presses a key
                    else if( e.type == SDL_KEYDOWN )
                    {
                        //Select surfaces based on key press
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_UP:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                            break;

                            case SDLK_DOWN:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                            break;

                            // case SDLK_LEFT:
                            // gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                            // break;

                            // case SDLK_RIGHT:
                            // gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                            // break;

                            default:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                            break;
                        }
                    }
					//Apply the image stretched
					gStretchedSurface = loadSurface("pictures/main.bmp");

					Screen* screen = new Screen(gStretchedSurface, gScreenSurface, stretchRect);

					screen->renderScreen();

					//SDL_BlitScaled(gStretchedSurface, NULL, gScreenSurface, &stretchRect);

					//Apply the image without stretching
					//SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

					//Update the surface
					SDL_UpdateWindowSurface(gWindow);

					//Wait two seconds
					SDL_Delay(2000);
					count++;
					std::cout << "In the game loop: " << count << "\n";
					cout << quit << endl;
				}
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}