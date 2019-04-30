#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#else
#include <SDL.h>
#endif

#include "Sound.hpp"

//displays score at end of game
class ScoreBoard
{
private:
	//Attributes
	int playerOneScore; //player scores of current game
	int playerTwoScore;
	int highScore; //high score which is saved even after closing the game
	SDL_Texture* scoreBoard; //scoreboard texture


public:
	//Constructor
	ScoreBoard();
	//Destructor
	~ScoreBoard();
	//Methods
	void renderBoard(); //plays a sound
};
