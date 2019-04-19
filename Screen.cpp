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

void Screen::renderScreen() {
	SDL_BlitScaled(screenTexture, NULL, gScreenSurface, &stretchRect);
}