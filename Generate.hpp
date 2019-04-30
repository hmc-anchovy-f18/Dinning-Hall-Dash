#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#else
#include <SDL.h>
#endif

#include "Map.hpp"
#include "LevelSelect.hpp"
#include "Vehicle.hpp"
#include "Sound.hpp"
#include "PlayerOne.hpp"
#include "PlayerTwo.hpp"
#include "PowerUp.hpp"


class Generate
{
private:
	//Attributes
	Map map;
	PlayerOne playerOne;
	PlayerTwo playerTwo;
	Sound sound;


public:
	//Constructor
	Generate();
	//Destructor
	~Generate();
	//Methods
	void generatePowerUps(); //generates powerups on map
};
