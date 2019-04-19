#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "MainMenu.hpp"

MainMenu::Screen(SDL_Surface* currentTexture, SDL_Surface* screenSurface, SDL_Rect rect) : screenTexture(currentTexture), gScreenSurface(screenSurface), stretchRect(rect)
{}

MainMenu::~Screen() {
	//TODO
}