#pragma once

#include "Game.hpp"

class Map
{
public:
    Map();
    ~Map();

    void loadMap(int arr[10][18]);
    void drawMap();

private:
    SDL_Rect srcRect,destRect;
    SDL_Texture *road;
    SDL_Texture *base;

    int map[20][25];
};