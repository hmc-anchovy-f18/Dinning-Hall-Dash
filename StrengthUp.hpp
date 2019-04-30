#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#else
#include <SDL.h>
#endif
#include <iostream>

#include "PowerUp.hpp"
//controls buffs and debuffs in game
class StrengthUp : PowerUp
{
private:
	//Attributes
	// int strengthEffect; //negative or positive effect on speed;
	// int time; //duration of powerUp
	// int x, y; //Location of powerup


public:
	//Constructor
	StrengthUp(int, int, int, int);
	//Destructor
	~StrengthUp();
};
