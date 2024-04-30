#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "BaseTower.hpp"
#include "Enemy.hpp"

GameObject *background;
GameObject *weaponMenu;
SDL_Renderer* Game::renderer = nullptr;
Map* map;
Enemy* enemy;
SDL_Point curPos,tmp;

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
    background = new GameObject("Picture/background.png",0,0);
    map = new Map();
    weaponMenu = new GameObject("Picture/weapon_menu.png",700,900);
    enemy = new Enemy(1);

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
                if (map->getMapState(mouseY,mouseX) == BASE){
                    tileChosen.x = mouseX;
                    tileChosen.y = mouseY;
                }
                else if (map->getMapState(mouseY,mouseX)  > ColorNumber){
                    int towerType = map->getMapState(mouseY,mouseX) - ColorNumber - 1;
                    if (money - cost[towerType] >= 0 && map->Update(towerType,tileChosen.y,tileChosen.x)) {
                        money -= cost[towerType];
                        printf("Money left: %d\n",money);
                    }
                }
                break;
            default:  
                break;
        }
    
    
}

void Game::update()
{
//    printf("%d %d %d %d\n",enemy->getCurrentTile().x,enemy->getCurrentTile().y,curPos.x,curPos.y);
    tmp = enemy->getCurrentTile();
    if (tmp.x != curPos.x || tmp.y != curPos.y){
        printf("%d %d %d %d\n",tmp.x,tmp.y,curPos.x,curPos.y);
        for(int direction = 0;direction < 8;direction += 2){
        if (map->getMapState(tmp.y + dy[direction],tmp.x + dx[direction]) == ROAD){
        //    printf("%d %d %d\n",map->getMapState(curPos.y + dy[direction],curPos.x + dx[direction]),curPos.y + dy[direction],curPos.x + dx[direction]);
            if (tmp.x + dx[direction] != curPos.x || tmp.y + dy[direction] != curPos.y){
 //               printf("%d %d\n",enemy->getDirection(),direction);
                enemy->setDirection(direction);
                break;
            }
        }
    }
        curPos = tmp;
    }
    enemy->Move();
    
}

void Game::render()
{
    SDL_RenderClear(renderer);
    
    background->Render(SCREEN_WIDTH,SCREEN_HEIGHT);
    map->drawMap();
    weaponMenu->Render();
    map->Render();
    enemy->Render();
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
int Game::getMoney()
{
    return money;
}