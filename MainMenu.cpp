#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "MainMenu.hpp"

MainMenu::MainMenu() 
{
	index = 0;
	pictures[0] = "pictures/start.png";
	pictures[1] = "pictures/about.png";
	pictures[2] = "pictures/score.png";
	pictures[3] = "pictures/exit.png";
}

MainMenu::~MainMenu() {
	//TODO
}

string MainMenu::nextPicture(){
	if( index!= 3){
		index++;
	}
	else{
		index = 0;
	}
	return pictures[index];
}

string MainMenu::prevPicture(){
	if( index!= 0){
		index--;
	}
	else{
		index = 3;
	}
	return pictures[index];
}