#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif
#include "string"
using namespace std;
//freelines, skateboard, roller skates, skateboard, bike, unicycle, hoverboard select
class Vehicle
{
private:
	//Attributes
	int speed;
	string type;
	//hit box
	int upperHit;
	int lowerHit;
	//Texture for the car
	//unsure what type it should be


public:
	//Constructor
	Vehicle(int);
	//Destructor
	~Vehicle();
	//Methods
	void Drive(); //update player location
	int getSpeed(); //return speed;
};
