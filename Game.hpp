#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <vector>
#include "Constants.hpp"

class Game{
public:
    Game();
    ~Game();

    void init(const char* title,int xPos,int yPos,int width,int height,bool fullScreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();
    
    static SDL_Renderer* renderer;
    
private:
    int cnt = 0;
    int money = 0;
    bool isRunning;
    SDL_Point tileChosen = {0,0};    
    SDL_Window* window;
    
};
#endif