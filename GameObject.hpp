#pragma once

#include "Game.hpp"

class GameObject
{
public:
    GameObject(const char* textureSheet,int,int);
    ~GameObject();

    void Update();
    void Render();
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    void Render(int,int);
    void RenderCenter();
private:
    int xPos;
    int yPos;

    SDL_Texture* objectTexture;
    SDL_Rect srcRect,destRect;


};