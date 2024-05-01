
#include "TextureManager.hpp"

SDL_Texture* TextureManager::loadTexture(const char* texture)
{
    SDL_Surface* tmpSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return tex;
}
void TextureManager::draw(SDL_Texture *tex,SDL_Rect srcRect,SDL_Rect destRect)
{
    SDL_RenderCopy(Game::renderer,tex,&srcRect,&destRect);
}

SDL_Texture* TextureManager::loadTexturefromText(std::string textureText,SDL_Color textColor)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(Game::gFont,textureText.c_str(),textColor);
    if (textSurface == NULL){
        printf ("cac\n");
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer,textSurface);
    SDL_FreeSurface(textSurface);

    return tex;
}