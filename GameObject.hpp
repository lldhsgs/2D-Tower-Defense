#pragma once

#include "Game.hpp"

class GameObject
{
public:
    GameObject(const char* textureSheet,int,int);
    ~GameObject();

    void Update();
    void Render();

private:
    int xPos;
    int yPos;

    SDL_Texture* objectTexture;
    SDL_Rect srcRect,destRect;


};