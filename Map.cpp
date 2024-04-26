#include "Map.hpp"
#include "TextureManager.hpp"

int lvl1[10][18] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,2,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0}
};
Map::Map()
{
    road = TextureManager::loadTexture("Picture/green_enemy.png");
    base = TextureManager::loadTexture("Picture/yellow_enemy.png");
    
    loadMap(lvl1);

    srcRect.x = srcRect.y = 0;
    srcRect.w = destRect.w = 100;
    srcRect.h = destRect.h = 100;
    destRect.x = destRect.y = 0;
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
            destRect.x = col * 100;
            destRect.y = row * 100;
            switch (type){
                case 1:
                    TextureManager::draw(base,srcRect,destRect);
                    break;
                case 2:
                    TextureManager::draw(road,srcRect,destRect);
                    break;
                default:
                    break;
            }
        }
    }
}