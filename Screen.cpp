#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#else
#include <SDL.h>
#endif
#include "Screen.hpp"

Screen::Screen(SDL_Surface* currentTexture, SDL_Surface* screenSurface, SDL_Rect rect) 
	: screenTexture(currentTexture), gScreenSurface(screenSurface), stretchRect(rect)
{}

Screen::~Screen() {
	delete this->screenTexture;
	delete this->gScreenSurface;
	//TODO
}

void Screen::renderScreen() {
	SDL_BlitScaled(this->screenTexture, NULL, this->gScreenSurface, &this->stretchRect);
}