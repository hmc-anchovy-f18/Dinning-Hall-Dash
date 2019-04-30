#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#else
#include <SDL.h>
#endif

#include "Vehicle.hpp"


class CharacterSelect
{
private:
	//Attributes
	string student;
	string schoolSpirit;
	string name;

public:
	//Constructor
	CharacterSelect();
	
	//Destructor
	~CharacterSelect();
	//Methods
	string getSpirit();
	void pitzerian();
	void mudder();
	void scripps();
	void pomona();
	void cmcer();
	void getName();

};
