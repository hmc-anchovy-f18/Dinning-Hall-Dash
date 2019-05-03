#include "PlayerOne.hpp"


PlayerOne::PlayerOne(){
    //Top left corner viewport
    SDL_Rect topLeftViewport;
    topLeftViewport.x = 0;
    topLeftViewport.y = 0;
    topLeftViewport.w = SCREEN_WIDTH / 2;
    topLeftViewport.h = SCREEN_HEIGHT / 2;
    SDL_RenderSetViewport( gRenderer, &topLeftViewport );

    //Render texture to screen
    SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
}