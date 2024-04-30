

#include "BaseTower.hpp"
#include <string>
#include <iostream>
std::string cannons[] = {"Picture/grey_cannon.png","Picture/green_cannon.png","Picture/laser_cannon.png","Picture/black_cannon.png"};
BaseTower::BaseTower()
{
    range = 0;
    attackSpeed = 0;
    price = 0;
    Tower = nullptr;
}

void BaseTower::Place(int towerType,int tileX,int tileY)
{
    if (towerType >= 4){
        printf("Tower not existing!\n");
        return;
    }
    TowerType = towerType;
    tileX *= 100;
    tileY *= 100;
    GameObject* temp = new GameObject(cannons[TowerType].c_str(),tileY,tileX);
    Tower = temp;
}

void BaseTower::Render()
{
//    printf("%d\n",Tower->getX());
    Tower->RenderCenter();
}
// int BaseTower::getWidth()
// {
//     return Tower->getWidth();
// }
void BaseTower::Attack()
{
}