#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

class PlayerTwo
{
private:
	//Attributes
	int x, y; //player location; update to Point later?
	string name;
	Vehicle ride;
	PowerUp power;

public:
	//Constructor
	PlayerTwo();
	//Destructor
	~PlayerTwo();
	//Methods
	int getX();
	int getY();
	void setX(int);
	void setY(int);
};
