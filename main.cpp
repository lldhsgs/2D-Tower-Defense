#include "Game.hpp"

Game* game = nullptr;
int main(int argc,char* argv[])
{
    // const int FPS = 150;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init("Tower Defense 2D",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,false);

    while (game->running()){
        frameStart = SDL_GetTicks();

        if (game->checkEndRound()){
            if (game->checkVictory()){
                printf("You win!\n");
            }
            else if (game->checkDefeat()){
                printf("You lose\n");
            }
            else game->newRound();
        }

        game->handleEvents();
        game->update();
        game->render();

        
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
    game->clean();

    return 0;
}