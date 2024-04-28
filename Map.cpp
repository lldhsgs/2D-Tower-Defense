#include "Map.hpp"
#include "TextureManager.hpp"

int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {-1,-1,0,1,1,1,0,-1};;
int lvl1[10][18] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,3},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,1,1},
    {0,0,0,0,0,0,0,0,0,0,1,1,2,2,2,1,0,0},
    {0,0,0,1,1,1,1,1,0,1,2,2,2,1,1,0,0,0},
    {1,1,1,2,2,2,2,2,1,1,2,1,1,0,0,0,0,0},
    {2,2,2,2,1,1,1,2,2,2,2,1,0,0,0,0,0,0},
    {1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
Map::Map()
{
    road = TextureManager::loadTexture("Picture/path_square.png");
    base = TextureManager::loadTexture("Picture/base_square.png");
    portalEnd = TextureManager::loadTexture("Picture/portal_end.png");
    loadMap(lvl1);

    srcRect.x = srcRect.y = 0;
    srcRect.w = destRect.w = TILE_SIZE;
    srcRect.h = destRect.h = TILE_SIZE;
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

int Map::getDegreeBase(int row,int col,int aimRow,int aimCol)
{
    int degrees = 0;
    for(int direction = 0;direction < 8;++direction){
        if (aimRow - row == dy[direction] && aimCol - col == dx[direction]){
            degrees =  45 * direction;
        }
    }
    return degrees;
}