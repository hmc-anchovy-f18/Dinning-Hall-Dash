#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "string"

using namespace std;
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
