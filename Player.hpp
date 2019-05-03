#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#else
#include <SDL.h>
#endif

#include "Vehicle.hpp"
#include "PowerUp.hpp"

class Player
{
private:
	//Attributes
	int x, y; //player location; update to Point later?
	string name;
	Vehicle ride;
	PowerUp power;
	SDL_Rect viewport;

public:
	//Constructor
	Player();
    Player(string, Vehicle, int, int, int, int);
	//Destructor
	~Player();
	//Methods
	//get and set player location
	int getX();
	int getY();
	void move(int, int);
};
