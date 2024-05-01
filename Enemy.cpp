

#include "Enemy.hpp"

std::string enemies[] = {"Picture/green_enemy.png","Picture/yellow_enemy.png","Picture/red_enemy.png"};
Enemy::Enemy(int type,int ord)
{
    switch (type){
        case Small:
            damage = 1;
            HP = 3;
            prize = 20;
            break;
        case Medium:
            damage = 2;
            HP = 5;
            prize = 40;
            break;
        case Large:
            damage = 3;
            HP = 10;
            prize = 60;
    }
    enemy = new GameObject(enemies[type].c_str(),100,1000 + 100 * ord);
    VelX = dx[UP];
    VelY = dy[UP];
    isDead = false;
}

Enemy::~Enemy()
{
    enemy->free();
}
void Enemy::Render()
{
    if (!isDead)
    enemy->RenderCenter();
}

void Enemy::setDirection(int direction)
{
    VelX = dx[direction];
    VelY = dy[direction];
}

int Enemy::getDirection()
{
    for(int direction = 0;direction < 8;++direction){
        if (VelX == dx[direction] && VelY == dy[direction]){
            return direction;
        }
    }
    return UP;
}

SDL_Point Enemy::getCurrentTile(int direction)
{
    return {(direction == RIGHT ? (enemy->getX()) : (enemy->getX() + TILE_SIZE - 1)) / TILE_SIZE,(direction == UP ? (enemy->getY() + TILE_SIZE - 1) : (enemy->getY()))/ TILE_SIZE};
}

void Enemy::Move()
{
    if (!isDead){
        enemy->setX(enemy->getX() + VelX);
        enemy->setY(enemy->getY() + VelY);
    }

}

bool Enemy::checkEnd()
{
    if (enemy->getX() == TILE_END_X && enemy->getY() == TILE_END_Y){
        // isDead = true;
        return true;
    }
    return false;
}

bool Enemy::checkDead()
{
    return isDead;
}

int Enemy::getDamage()
{
    return damage;
}

void Enemy::takeDamage(int Damage)
{
    if (!isDead){
        HP -= Damage;
            // printf("HP remaining of enemy: %d\n",HP);
            if (HP <= 0){
                isDead = true;
            }
    }
    
}

int Enemy::getX()
{
    return enemy->getX();
}

int Enemy::getY()
{
    return enemy->getY();
}

int Enemy::getPrize()
{
    return prize;
}