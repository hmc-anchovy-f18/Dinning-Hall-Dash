#pragma once


#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "Screen.hpp"

class MainMenu : Screen
{
private:
	//Attributes
    bool start;
    bool instructions;

public:
   // LevelSelect level();
    //string instructions();
	//Constructor
	MainMenu();
	//Destructor
	~MainMenu();
	//Methods
};
