#ifndef Constants_hpp
#define Constants_hpp

#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 1800;
const int SCREEN_HEIGHT = 1000;

const int TILE_SIZE = 100;

const int NUMBER_OF_TILE_X = 18;
const int NUMBER_OF_TILE_Y = 10;

const int Grey = 100;
const int Green = 101;
const int Blue = 102;
const int Black = 103;
const int ColorNumber = 99;

const int BASE = 1;
const int ROAD = 2;
enum 
{
    Small,
    Medium,
    Large
};

const int cost[] = {50,100,150,200};

const int dx[] = {0,1,1,1,0,-1,-1,-1};
const int dy[] = {-1,-1,0,1,1,1,0,-1};

#endif

