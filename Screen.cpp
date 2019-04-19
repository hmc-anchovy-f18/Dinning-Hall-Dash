#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif
#include "Screen.hpp"

Screen::Screen(SDL_Surface* currentTexture, SDL_Surface* screenSurface, SDL_Rect rect) : screenTexture(currentTexture), gScreenSurface(screenSurface), stretchRect(rect)
{}

Screen::~Screen() {
	//TODO
}

void renderScreen() {
	return 0;
}

/*
class Screen
{
private:
	//Attributes
	SDL_Texture* screenTexture;


public:
	//Constructor
	Screen(SDL_Texture*); //each attribute
	//Destructor
	~Screen();
	//Methods
	void renderScreen(); //activates powerup effect
};


*/