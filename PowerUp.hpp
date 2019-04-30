#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#else
#include <SDL.h>
#endif

//controls buffs and debuffs in game
class PowerUp
{
private:
	//Attributes
	int speedEffect; //negative or positive effect on speed;
	int strengthEffect; //negative or positive effect on strength;
	int time; //duration of powerUp
	int x, y; //Location of powerup


public:
	//Constructor
	PowerUp(int, int, int, int, int); //each attribute
	//Destructor
	~PowerUp();
	//Methods
	void activatePowerUp(); //activates powerup effect
};
