#pragma once

#include "Game.hpp"
#include "BaseTower.hpp"

int getRand();

class Map
{
public:
    Map();
    ~Map();

    void loadMap(int arr[NUMBER_OF_TILE_Y][NUMBER_OF_TILE_X]);
    void drawMap();
    int getMapState(int,int);
    void Render();
    bool Update(int,int,int);
    bool getTurretState(int,int);
    void updateEnemyState(SDL_Point,SDL_Point);
    int getEnemyState(int,int);
    BaseTower* getTowers(int,int);
private:
    SDL_Rect srcRect,destRect;
    SDL_Texture *road;
    SDL_Texture *base;
    SDL_Texture *portalEnd;
    int map[NUMBER_OF_TILE_Y][NUMBER_OF_TILE_X];
    bool flag[NUMBER_OF_TILE_Y][NUMBER_OF_TILE_X];
    int EnemyStatus[NUMBER_OF_TILE_Y][NUMBER_OF_TILE_X];
    BaseTower* towers[NUMBER_OF_TILE_Y][NUMBER_OF_TILE_X];
};