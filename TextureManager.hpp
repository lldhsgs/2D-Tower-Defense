#pragma once

#include "Game.hpp"

class TextureManager
{
public:
    static SDL_Texture* loadTexture(const char* path);
    static void draw(SDL_Texture *tex,SDL_Rect srcRect,SDL_Rect destRect);
};