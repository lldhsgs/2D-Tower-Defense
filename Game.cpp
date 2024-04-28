#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "BaseTower.hpp"
GameObject *enemy[15],*portal;
GameObject *background;
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
    for(int i = 0;i < 6;++i)
    enemy[i] = new GameObject("Picture/red_enemy.png",0,i * TILE_SIZE);
    portal = new GameObject("Picture/portal_end.png",50,50);
    background = new GameObject("Picture/background.png",0,0);
    map = new Map();
}
BaseTower *baseTower = new BaseTower();
// std::vector<BaseTower*> baseTowers;
void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                SDL_GetMouseState(&tileChosen.x,&tileChosen.y);
                tileChosen.x /= TILE_SIZE;
                tileChosen.y /= TILE_SIZE;
                printf("%d %d\n",tileChosen.x,tileChosen.y);
                break;
            case SDL_KEYDOWN:
                if (map->getMapState(tileChosen.y,tileChosen.x) == 1){
                    switch (event.key.keysym.sym){
                        case SDLK_1:
                            baseTower->Place(Grey,tileChosen.x,tileChosen.y);
                            break;
                        case SDLK_2:
                            baseTower->Place(GreenN,tileChosen.x,tileChosen.y);
                            break;
                        case SDLK_3:
                            baseTower->Place(GreenS,tileChosen.x,tileChosen.y);
                            break;
                        case SDLK_4:
                            baseTower->Place(Blue,tileChosen.x,tileChosen.y);
                            break;
                        case SDLK_5:
                            baseTower->Place(Black,tileChosen.x,tileChosen.y);
                            break;
                        default:
                            break;
                    }
                    printf("%d\n",baseTower->getWidth());
 //                   baseTower->Render();
                }
                break;
            default:  
                break;
        }
    
    
}

void Game::update()
{
    for(int i = 0;i < 6;++i)
    enemy[i]->Update();
    portal->Update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    background->Render(SCREEN_WIDTH,SCREEN_HEIGHT);
    map->drawMap();
    for(int i = 0;i < 6;++i)
    enemy[i]->Render();
    portal->Render();
 //   baseTower->Render();
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