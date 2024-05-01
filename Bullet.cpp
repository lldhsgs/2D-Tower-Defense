
#include "Bullet.hpp"

std::string bullets[] = {"Picture/normal_bullet.png","Picture/green_bullet.png","Picture/blue_bullet.png"};
int velocity;
Bullet::Bullet(int type,int x,int y)
{
    switch (type){
        case NORMAL_BULLET:
            Damage = 1;
            velocity = 2;
            break;
        case POISON_BULLET:
            Damage = 2;
            velocity = 3;
            break;
        case LASER_BULLET:
            Damage = 5;
            velocity = 1;
            break;
    }
    bulletType = type;
    bullet = new GameObject(bullets[type].c_str(),x,y);
    Collided = false;
}

Bullet::~Bullet()
{
    bullet->free();
}

void Bullet::Collide(Enemy* enemy)
{
    SDL_Point tmpTile = enemy->getCurrentTile(enemy->getDirection());
    if (bullet->getX() >= tmpTile.x * TILE_SIZE && bullet->getX() <= tmpTile.x * TILE_SIZE + TILE_SIZE && bullet->getY() >= tmpTile.y * TILE_SIZE && bullet->getY() <= tmpTile.y * TILE_SIZE + TILE_SIZE){
        enemy->takeDamage(Damage);
        Collided = true;
    }
}

void Bullet::Move()
{
    bullet->setX(bullet->getX() + VelX * velocity);
    bullet->setY(bullet->getY() + VelY * velocity);
}

void Bullet::Render()
{
    bullet->Render();
}

bool Bullet::isCollided()
{
    return Collided;
}

void Bullet::setDirection(int direction)
{
    VelX = dx[direction];
    VelY = dy[direction];
}

int Bullet::getType()
{
    return bulletType;
}

void Bullet::setX(int x)
{
    bullet->setX(x);
}

void Bullet::setY(int y)
{
    bullet->setY(y);
}

void Bullet::setCollision()
{
    Collided = false;
}