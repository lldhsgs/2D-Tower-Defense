
#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet,int x,int y)
{
    objectTexture = TextureManager::loadTexture(textureSheet);

    xPos = x;
    yPos = y;
}

void GameObject::Update()
{
    xPos++;
    yPos++;

 //   SDL_QueryTexture(objectTexture,NULL,NULL,&srcRect.w,&srcRect.h);
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}

void GameObject::Render()
{
    SDL_QueryTexture(objectTexture,NULL,NULL,&srcRect.w,&srcRect.h);
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
    SDL_RenderCopy(Game::renderer,objectTexture,&srcRect,&destRect);
}

void GameObject::RenderCenter()
{
    SDL_QueryTexture(objectTexture,NULL,NULL,&srcRect.w,&srcRect.h);
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xPos + (TILE_SIZE - srcRect.w) / 2;
    destRect.y = yPos + (TILE_SIZE - srcRect.h) / 2;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
    // printf("%x %x\n",this,Game::renderer);
//    printf("%d %d %d %d\n",destRect.x,destRect.y,destRect.w,destRect.h);
    SDL_RenderCopy(Game::renderer,objectTexture,&srcRect,&destRect);
}

void GameObject::Render(int w,int h)
{
    SDL_QueryTexture(objectTexture,NULL,NULL,&srcRect.w,&srcRect.h);
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = w;
    destRect.h = h;
    SDL_RenderCopy(Game::renderer,objectTexture,&srcRect,&destRect);
}

int GameObject::getX()
{
    return xPos;
}
int GameObject::getWidth()
{
    return srcRect.w;
}