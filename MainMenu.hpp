#pragma once


#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#else
#include <SDL.h>
#endif

#include "Screen.hpp"

class MainMenu
{
private:
	//Attributes
	int index;
	string pictures[4];

public:
   // LevelSelect level();
    //string instructions();
	//Constructor
	MainMenu(); //each attribute

	//Destructor
	~MainMenu();
	//Methods
	string nextPicture();
	string prevPicture();
};
