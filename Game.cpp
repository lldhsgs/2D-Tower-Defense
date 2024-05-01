#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "BaseTower.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"

GameObject *background;
GameObject *resultScreen;
GameObject *weaponMenu;
GameObject *portal;
GameObject *moneyDisplay;
GameObject *moneyTab;

SDL_Color textColor = {255,255,0,255};

SDL_Renderer* Game::renderer = nullptr;
TTF_Font* Game::gFont = nullptr;
Map* map;
std::vector<Enemy*> enemies;
std::vector<SDL_Point> curPos,tmp;
std::vector<GameObject*> lives;
std::vector<Bullet*> bullets;
std::vector<int> eraseEnemy,eraseBullet;
std::vector<SDL_Point> towers;
SDL_Point pos;
BaseTower* towerNow;
// BaseTower *baseTower;

std::string Convert(int x)
{
    std::string res = "";
    while (x){
        res.push_back(char((x % 10) + '0'));
        x /= 10;
    }
    reverse(res.begin(),res.end());
    return res;
}

Game::Game(){}

Game::~Game(){}
int mouseX,mouseY;
int rounds = 0;
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
        if (TTF_Init() == 0){
            printf("TTF initialized!\n");
        }
        isRunning = true;
    }
    else {
        isRunning = false;
    }
    gFont = TTF_OpenFont("Font/slkscr.ttf",100);
    background = new GameObject("Picture/background.png",0,0);
    map = new Map();
    weaponMenu = new GameObject("Picture/weapon_menu.png",700,900);
    portal = new GameObject("Picture/portal_end.png",1700,0);
    resultScreen = new GameObject("Picture/Victory_screen.png",0,0);
    moneyDisplay = new GameObject("Picture/heart.png",SCREEN_WIDTH,SCREEN_HEIGHT);
    moneyTab = new GameObject("Picture/moneyTab.png",0,0);
    // printf("%x\n",moneyDisplay);
    for(int LIVES = 0;LIVES < TOTAL_LIVES;++LIVES){
        lives.push_back(new GameObject("Picture/lives.png",500 + 100 * LIVES,0));
    }


}

void Game::newRound()
{
    ++rounds;
    // printf("%d\n",rounds);
    for(int i = 0;i < rounds * 3;++i){
        if (i <  5){
            enemies.push_back(new Enemy(Small,i));
        }
        else if (i < 10){
            enemies.push_back(new Enemy(Medium,i));
        }
        else{
            enemies.push_back(new Enemy(Large,i));
        }
        curPos.push_back({0,0});
        tmp.push_back({0,0});
    }
}

bool Game::checkEndRound()
{
    return enemies.empty();
}

bool Game::checkVictory()
{
    if (rounds > 4){
        resultScreen = new GameObject("Picture/Victory_screen.png",0,0);
        return true;
    }
    return false;
}

bool Game::checkDefeat()
{
    if (Lives <= 0){
        resultScreen = new GameObject("Picture/Defeat_screen.png",0,0);
        return true;
    }
    return false;
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
                        towers.push_back({tileChosen.x,tileChosen.y});
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

    if (checkDefeat() || checkVictory()){
        // resultScreen->Render(SCREEN_WIDTH,SCREEN_HEIGHT);
        return;
    }

    for(int i = 0;i < (int)enemies.size();++i){
        if (enemies[i]->checkEnd()){
            // printf("Enemy no %d has escaped\n",i);
            Lives -= enemies[i]->getDamage();
            // printf("Lives remaining: %d\n",Lives);
            if (Lives <= 0){
                // printf("You lose!\n");
                // isRunning = false;
                return;
            }
            eraseEnemy.push_back(i);
            continue;
        }
        else if (enemies[i]->checkDead()){
            money += enemies[i]->getPrize();
            eraseEnemy.push_back(i);
        }
    }

    for(int j = Lives;j < (int)lives.size();++j){
        lives.erase(lives.begin() + j);
    }
    for(int i = 0;i < (int)enemies.size();++i){
            tmp[i] = enemies[i]->getCurrentTile(enemies[i]->getDirection());
            // printf("%d %d %d\n",i,tmp[i].y,tmp[i].x);
            if (tmp[i].y > NUMBER_OF_TILE_Y){
                enemies[i]->Move();
                // map->updateEnemyState(curPos[i],tmp[i]);
                continue;
            }
            if (tmp[i].x != curPos[i].x || tmp[i].y != curPos[i].y){
                for(int direction = 0;direction < 8;direction += 2){
                    if (map->getMapState(tmp[i].y + dy[direction],tmp[i].x + dx[direction]) == ROAD){
                        if (tmp[i].x + dx[direction] != curPos[i].x || tmp[i].y + dy[direction] != curPos[i].y){
                            enemies[i]->setDirection(direction);
                            break;
                        }
                    }
                }
            map->updateEnemyState(curPos[i],tmp[i]);
            curPos[i] = tmp[i];
        }
        enemies[i]->Move();

    }
    for(SDL_Point tower : towers){
        towerNow = map->getTowers(tower.y,tower.x);
        towerNow->updateTimer();
        // printf("%d %d\n",tower.y,tower.x);
        for(int i = 0;i <(int)enemies.size();++i){
            if (enemies[i]->checkDead() || enemies[i]->checkEnd()) continue;
            pos = enemies[i]->getCurrentTile(enemies[i]->getDirection());
            for(int direction = 0;direction < 8;++direction){
                if (pos.y - tower.y == dy[direction] && pos.x - tower.x == dx[direction]){            
                    // printf("direction of the bullet: %d\n",direction);
                    towerNow->Attack(direction,enemies[i]);
                    break;
                }
            }
        }
    }
}

void Game::render()
{
    for(int i = 0;i < (int)eraseEnemy.size();++i){
        enemies.erase(enemies.begin() + eraseEnemy[i]);
        tmp.erase(tmp.begin() + eraseEnemy[i]);
        curPos.erase(curPos.begin() + eraseEnemy[i]);
    }
    eraseEnemy.clear();

    SDL_RenderClear(renderer);
    

    if (checkDefeat() || checkVictory()){
        // printf("Results");
        resultScreen->Render(SCREEN_WIDTH,SCREEN_HEIGHT);
        SDL_RenderPresent(renderer);
        return;
    }

    background->Render(SCREEN_WIDTH,SCREEN_HEIGHT);
    map->drawMap();
    weaponMenu->Render();
    map->Render();
    for(SDL_Point tower : towers){
        if (map->getTowers(tower.y,tower.x)->getDelayed() == false){
            // printf("%d %d\n",tower.y,tower.x);
            map->getTowers(tower.y,tower.x)->getBullet()->Render(); // không render được đạn????
        }
    }

    portal->Render();
    moneyTab->Render();
    moneyDisplay->loadText(Convert(money),textColor,200,0);
    moneyDisplay->Render();
    for(int i = 0;i < (int)enemies.size();++i)
    enemies[i]->Render();
    for(int i = 0;i <(int)lives.size();++i){
        lives[i]->Render(100,100);
    }
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    enemies.clear();
    lives.clear();
    curPos.clear();
    tmp.clear();
    towers.clear();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    TTF_CloseFont(gFont);
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