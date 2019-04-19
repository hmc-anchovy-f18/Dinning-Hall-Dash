#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif


class LevelSelect
{
private:
	//Attributes
	//starting positions for levels
	int x_start;
	int y_start;
	int x_end;
	int y_end;

public:
	int goPomona();
	int goScripps();
	int goMudd();
	int goPitzer();
	int goCMC();
	//Constructor
	LevelSelect();
	//Destructor
	~LevelSelect();
	//Methods
};
