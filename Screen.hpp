#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif
#include "string"
using namespace std;
//controls buffs and debuffs in game
class Screen
{
private:
	//Attributes
	SDL_Surface* screenTexture;
	SDL_Surface* gScreenSurface;
	SDL_Rect stretchRect;


public:
	//Constructor
	Screen(SDL_Surface*, SDL_Surface*, SDL_Rect); //each attribute
	//Destructor
	~Screen();
	//Methods
	void renderScreen(); //activates powerup effect
};
