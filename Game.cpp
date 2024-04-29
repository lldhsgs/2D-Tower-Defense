#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "BaseTower.hpp"
GameObject *enemy[15],*portal;
GameObject *background;
GameObject *menu;
SDL_Renderer* Game::renderer = nullptr;
Map* map;
// BaseTower *baseTower;
Game::Game(){}

Game::~Game(){}
int mouseX,mouseY;

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
    menu = new GameObject("Picture/weapon_menu.png",700,900);


}
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
                SDL_GetMouseState(&mouseX,&mouseY);
                mouseX /= TILE_SIZE;
                mouseY /= TILE_SIZE;
//                printf("%d %d\n",tileChosen.x,tileChosen.y);
                if (map->getMapState(mouseY,mouseX) == 1){
                    tileChosen.x = mouseX;
                    tileChosen.y = mouseY;
                }
                else if (map->getMapState(mouseY,mouseX)  > ColorNumber){
                    int towerType = map->getMapState(mouseY,mouseX) - ColorNumber - 1;
                    map->Update(towerType,tileChosen.y,tileChosen.x);
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
    menu->Render();
    for(int i = 0;i < 6;++i)
    enemy[i]->Render();
    portal->Render();
    map->Render();
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