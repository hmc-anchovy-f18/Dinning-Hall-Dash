#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#else
#include <SDL.h>
#endif

#include "Player.hpp"
#include "ScoreBoard.hpp"

class GameState
{
private:
	//Attributes
	string p1Name;
	string p2Name;
	int p1Score;
	int p2Score;
	int time;
	int p1Loc;
	int p2Loc;
	bool end;

public:
	void updateName(int);
	void updateScore(int, int);
	void display();
	void updateLoc(int, int, int);
	bool atEnd(int, int);
	//Constructor
	GameState();
	//Destructor
	~GameState();
	//Methods
};
