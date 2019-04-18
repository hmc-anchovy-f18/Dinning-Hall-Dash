#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

class Map
{
private:
	//Attributes
	SDL_Texture* mapTexture; //texture of map
	int x1, y1; //start line
	int x2, y2; //finish line
	int walls;
	int objects;


public:
	//Constructor
	Map();
	//Destructor
	~Map();
	//Methods
	//set start and finish lines
	void setObjects(int);
	void setWalls(int);
	void setStart(int, int);
	void setFinish(int, int);
};
