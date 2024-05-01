#include "constants.h"
#include "Enemy.h"
#include "utils.h"



int main(int argc,char* argv[])
{
	if (!init()){
		printf("Failed to initialize\n");
	}
	else{
			bool quit = false;
			SDL_Event e;
			Enemy temp(Red);
			LTexture texture;
			int X,Y;
			int velocityX = 10,velocityY = 10;
			printf("%d\n",temp.getWidth());
			if (!texture.loadFromFile("Picture/red_enemy.png")){
				printf("Failed to load texture from file!\n");
			}
			else {
				while (!quit){
						while (SDL_PollEvent(&e) != 0){
						if (e.type == SDL_QUIT){
							quit = true;
						}
					}
					runSDL();
					X = texture.getX() + velocityX;
					Y = texture.getY() + velocityY;
					if (X + texture.getWidth() > SCREEN_WIDTH || X < 0){
						X -= velocityX;
						velocityX *= -1;
					} 
					if (Y + texture.getHeight() > SCREEN_HEIGHT || Y < 0){
						Y -= velocityY;
						velocityY *= -1;
					}
					texture.setPosition(X,Y);
					// texture.render(texture.getX(),texture.getY());
					// temp.render();
				}
			}
			
		}

	close();
	return 0;
}