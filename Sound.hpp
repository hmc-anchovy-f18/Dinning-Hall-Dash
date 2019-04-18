#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif
#include <iostream>

//controls sound production
class Sound
{
private:
	//Attributes
	SDL_AudioSpec* backgroundMusic;
	SDL_AudioSpec* crash;
	SDL_AudioSpec* powerUp;
	SDL_AudioSpec* drivingNoise;
	//Sound File for background music (according to matchup)
	//Sound File for crashing
	//Sound File for power-ups



public:
	//Constructor
	Sound();
	//Destructor
	~Sound();
	//Methods
	void PlaySound(std::string); //plays a sound
};
