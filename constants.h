#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SDL2/SDL.h>

const static int SCREEN_WIDTH = 1000;
const static int SCREEN_HEIGHT = 600;
const static int SCREEN_DIAGONAL = 2204;

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

const static char WINDOW_TITLE[] = "Tower Defense 2D";

const SDL_Color ENEMY_PINK = {255, 33, 114};
const SDL_Color ENEMY_SPLASH = {255, 214, 255};
const SDL_Color BEFORE_ENEMY = {51, 7, 24};
const SDL_Color ENEMY_FG = {59, 8, 36};
const SDL_Color BG = {0, 26, 36};
const SDL_Color WHITE = {0xFF, 0xFF, 0xFF};
const SDL_Color DARK_GREEN = {3, 73, 97};
const SDL_Color ALLY_BLUE = {3, 255, 255};
#endif