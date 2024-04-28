

#include "BaseTower.hpp"

BaseTower::BaseTower()
{
    range = 0;
    attackSpeed = 0;
    price = 0;
    Tower = nullptr;
}

void BaseTower::Place(int towerType,int tileX,int tileY)
{
    tileX *= 100;
    tileY *= 100;
    printf("%d %d\n",tileX,tileY);
    switch(towerType){
        case Grey:
            Tower = new GameObject("Picture/grey_cannon.png",tileX,tileY);
            break;
        case GreenN:
            Tower = new GameObject("Picture/green_cannon_N.png",tileX,tileY);
            break;
        case GreenS:
            Tower = new GameObject("Picture/green_cannon_S.png",tileX,tileY);
            break;
        case Blue:
            Tower = new GameObject("Picture/laser_cannon.png",tileX,tileY);
            break;
        case Black:
            Tower = new GameObject("Picture/black_cannon.png",tileX,tileY);
            break;
    }
    Tower->RenderCenter();
}

void BaseTower::Render()
{
//    printf("%d\n",Tower->getX());
    Tower->RenderCenter();
}
int BaseTower::getWidth()
{
    return Tower->getWidth();
}