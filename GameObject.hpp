#pragma once

#include "Game.hpp"

class GameObject
{
public:
    GameObject(const char*,int,int);
    ~GameObject();
    void Update();
    void Render();
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    void Render(int,int);
    void RenderCenter();
    void free();
    SDL_Texture* getTexture();


private:
    int xPos;
    int yPos;
    SDL_Texture* objectTexture;
    SDL_Rect srcRect,destRect;


};