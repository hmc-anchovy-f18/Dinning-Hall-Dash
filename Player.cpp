#include "Player.hpp"


Player::Player()
    :name("Default")
{
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);

    int Width = DM.w;
    int Height = DM.h;
    this->viewport.x = 0;
    this->viewport.y = 0;
    this->viewport.w = Width/2;;
    this->viewport.h = Height;
}

Player::Player(string s, Vehicle v, int x, int y, int w, int h)
    :name(s), ride(v)
{   
    this->viewport.x = x;
    this->viewport.y = y;
    this->viewport.w = w;
    this->viewport.h = h;
}