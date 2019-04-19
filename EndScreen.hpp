#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
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
