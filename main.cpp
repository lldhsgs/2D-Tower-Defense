#include "constants.h"
#include "Enemy.h"
#include "utils.h"
#include "utils.cpp"
#include "Enemy.cpp"
LTexture gBackgroundTexture,gTowerTexture;
bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}
bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprites
	if( !gBackgroundTexture.loadFromFile(gRenderer,"Picture/background.png") )
	{
		printf( "Failed to load background!\n" );
		success = false;
	}
	if (!gTowerTexture.loadFromFile(gRenderer,"Picture/laser_cannon.png")){
		printf("Failed to load tower\n");
		success = false;
	}
	return success;
}

void close()
{
	//Free loaded images
	gBackgroundTexture.free();
	gTowerTexture.free();
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int WinMain(int argc,char* argv[])
{
	if (!init()){
		printf("Failed to initialize\n");
	}
	else{

		if (!loadMedia()){
			printf("Failed to load media\n");
		}
		
		else {
			bool quit = false;
			SDL_Event e;
			int w,h;
			SDL_GetWindowSize(gWindow,&w,&h);
			printf("%d %d\n",w,h);
			while (!quit){
				while (SDL_PollEvent(&e)){
					if (e.type == SDL_QUIT){
						quit = true;
					}
					// else if (e.type == SDL_MOUSEBUTTONDOWN){
					// 	int x,y;
					// 	SDL_GetMouseState(&x,&y);
					// 	printf ("%d %d\n",x,y);
					// }
				}

				SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
				SDL_RenderClear(gRenderer);

				gBackgroundTexture.render(gRenderer,0,0);
				gTowerTexture.render(gRenderer,SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2);
				Enemy temp;
				temp.render(0,0,0);
				SDL_RenderPresent(gRenderer);
			}
		}
	}
	close();
	return 0;
}