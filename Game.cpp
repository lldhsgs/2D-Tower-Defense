#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
GameObject *enemy,*portal;

SDL_Renderer* Game::renderer = nullptr;
Map* map;

Game::Game(){}

Game::~Game(){}

void Game::init(const char* title,int xPos,int yPos,int width,int height,bool fullScreen)
{

    int flags = 0;

    if (fullScreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        printf("Subsystem initialized!\n");

        window = SDL_CreateWindow(title,xPos,yPos,width,height,flags);
        if (window){
            printf("Window initialized\n");
        }

        renderer = SDL_CreateRenderer(window,-1,0);
        if (renderer){
            SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);
            printf("Renderer initialized\n");
        }
        isRunning = true;
    }
    else {
        isRunning = false;
    }
    enemy = new GameObject("Picture/red_enemy.png",0,0);
    portal = new GameObject("Picture/portal_end.png",50,50);
    map = new Map();
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update()
{
    enemy->Update();
    portal->Update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->drawMap();
    enemy->Render();
    portal->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    printf("Game cleaned\n");
}
bool Game::running()
{
    return isRunning;
}