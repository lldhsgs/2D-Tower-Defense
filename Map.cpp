#include "Map.hpp"
#include "TextureManager.hpp"
#include <time.h>
#include <cstdlib>

int lvl[3][10][18] = {
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,2},
    {0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,1,1},
    {0,0,0,0,0,0,0,0,0,1,1,1,2,2,2,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,2,2,2,1,1,0,0,0},
    {1,1,1,2,2,2,2,2,1,1,2,1,1,0,0,0,0,0},
    {1,2,2,2,1,1,1,2,2,2,2,1,0,0,0,0,0,0},
    {1,2,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0},
    {1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,2,1,0,0,0,0,Grey,Green,Blue,Black,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2},
    {0,0,0,0,0,0,0,0,0,0,1,1,1,1,2,2,1,1},
    {0,0,0,0,0,0,0,0,1,1,1,2,2,2,2,1,1,0},
    {0,0,0,0,0,0,0,0,1,2,2,2,1,1,1,1,0,0},
    {0,0,0,0,0,0,1,1,1,2,1,1,1,0,0,0,0,0},
    {0,0,0,1,1,1,1,2,2,2,1,0,0,0,0,0,0,0},
    {0,0,1,1,2,2,2,2,1,1,1,0,0,0,0,0,0,0},
    {1,1,1,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {1,2,2,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,2,1,1,1,0,0,Grey,Green,Blue,Black,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2,2},
    {0,0,0,0,0,0,0,0,0,1,2,2,2,1,2,2,2,1},
    {0,0,0,0,0,1,1,1,1,2,2,1,2,2,2,1,1,0},
    {0,0,0,0,0,1,2,2,2,2,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,2,1,1,1,1,0,0,0,0,0,0,0},
    {0,1,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0},
    {1,1,2,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
    {1,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,2,1,0,0,0,0,Grey,Green,Blue,Black,0,0,0,0,0,0,0}}
};
Map::Map()
{
    road = TextureManager::loadTexture("Picture/path_square.png");
    base = TextureManager::loadTexture("Picture/base_square.png");
    portalEnd = TextureManager::loadTexture("Picture/portal_end.png");
    loadMap(lvl[getRand()]);

    srcRect.x = srcRect.y = 0;
    srcRect.w = destRect.w = TILE_SIZE;
    srcRect.h = destRect.h = TILE_SIZE;
    destRect.x = destRect.y = 0;
    for(int i = 0;i < 10;++i){
        for(int j = 0;j < 18;++j){
            towers[i][j] = new BaseTower();
            towers[i][j]->Place(0,SCREEN_WIDTH,SCREEN_HEIGHT);
        }
    }
}

void Map::loadMap(int arr[10][18])
{
    for(int row = 0;row < 10;row++){
        for(int col = 0;col < 18;++col){
            map[row][col] = arr[row][col];
        }
    }
}

void Map::drawMap()
{
    int type = 0;
    for(int row = 0;row < 10;++row){
        for(int col = 0;col < 18;++col){
            type = map[row][col];
            destRect.x = col * TILE_SIZE;
            destRect.y = row * TILE_SIZE;
            switch (type){
                case 1:
                    TextureManager::draw(base,srcRect,destRect);
                    break;
                case 2:
                    TextureManager::draw(road,srcRect,destRect);
                    break;
                case 3:
                    TextureManager::draw(portalEnd,srcRect,destRect);
                default:
                    break;
            }
        }
    }
}

int Map::getMapState(int row,int col)
{
    if (row > NUMBER_OF_TILE_Y || col > NUMBER_OF_TILE_X){
        return -1;
    }
    return map[row][col];
}

bool Map::Update(int towerType,int row,int col)
{
    if (flag[row][col] == false){
        towers[row][col]->Place(towerType,row,col);
        flag[row][col] = true;
        return true;
    }
    return false;
}
void Map::Render()
{
    for(int i = 0;i < 10;++i){
        for(int j = 0;j < 18;++j){
            if (map[i][j] == 1){
                towers[i][j]->Render();
            }
        }
    }
}

bool Map::getTurretState(int row,int col)
{
    return flag[row][col];
}

void Map::updateEnemyState(SDL_Point enemyOldTile,SDL_Point enemyNewTile)
{
    EnemyStatus[enemyOldTile.y][enemyOldTile.x]--;
    EnemyStatus[enemyNewTile.y][enemyNewTile.x]++;
}

BaseTower* Map::getTowers(int row,int col)
{
    return towers[row][col];
}

int Map::getEnemyState(int row,int col)
{
    return EnemyStatus[row][col];
}

int getRand()
{
    srand(time(0));
    return (rand()%3);
}