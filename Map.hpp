#pragma once

#include "Game.hpp"

class Map
{
public:
    Map();
    ~Map();

    void loadMap(int arr[NUMBER_OF_TILE_Y][NUMBER_OF_TILE_X]);
    void drawMap();
    int getMapState(int,int);
    int getDegreeBase(int,int,int,int);
private:
    SDL_Rect srcRect,destRect;
    SDL_Texture *road;
    SDL_Texture *base;
    SDL_Texture *portalEnd;
    int map[NUMBER_OF_TILE_Y][NUMBER_OF_TILE_X];
};