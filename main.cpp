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
int close();

//Loads individual image
SDL_Surface* loadSurface( std::string path );

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;



int close()
{
	return 0;

}



int main(int argc, const char* argv[])

{
	SDL_Event event;
	SDL_Renderer *renderer = NULL;
	SDL_Texture *texture = NULL;
	SDL_Window *window = NULL;

    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);

    SDL_CreateWindowAndRenderer(500, 500, 0, &window, &renderer);

    IMG_Init(IMG_INIT_PNG);

    texture = IMG_LoadTexture(renderer, "pictures/start.png");

    while (1) {
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;}

	SDL_DestroyTexture(texture);
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
   

}


