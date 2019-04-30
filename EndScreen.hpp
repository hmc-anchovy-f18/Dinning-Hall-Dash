#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#else
#include <SDL.h>
#endif

class EndScreen
{
private:
	//Attributes

	string endGameText;

public:
	//Constructor
	EndScreen();
	void genText();
	//Destructor
	~EndScreen();
	//Methods
};
