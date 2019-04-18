#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "Vehicle.hpp"
#include "string"
using namespace std;

class CharacterSelect
{
private:
	//Attributes
	string student;
	string schoolSpirit;
	string name;

public:
	//Constructor
	CharacterSelect();
	
	//Destructor
	~CharacterSelect();
	//Methods
	string getSpirit();
	void pitzerian();
	void mudder();
	void scripps();
	void pomona();
	void cmcer();
	void getName();

};
