#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#else
#include <SDL.h>
#endif
#include <string>
#include "MainMenu.hpp"
#include "LevelSelect.hpp"
#include "CharacterSelect.hpp"
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
