
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "sprite.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h" 
#include "simple_logger.h"
#include "init.h"
#include"graphics.h"


//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The window renderer
SDL_Renderer* gRenderer = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;
SDL_Event g_e;
int done = 0;
const Uint8* keys;
int main(int argc, char* args[])
{

	Vector2D Init_car_position;
	Init_car_position.x = 0;
	Init_car_position.y = 0;

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	Sprite_M* balls = spriteLoad("m7_map.png", 512, 512);

	// the main game loop
	//do
	//{
	SDL_RenderClear(gRenderer);
	spriteDraw(balls, gRenderer, 0, Init_car_position);






	//Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			//User presses a key
			else if (e.type == SDL_KEYDOWN)
			{
				//Select surfaces based on key press
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					slog("up");
					break;

				case SDLK_DOWN:
					slog("down");

					break;

				case SDLK_LEFT:
					slog("left");

					break;

				case SDLK_RIGHT:
					slog("right");

					break;

				default:
					break;
				}
			}
		}


	
	NextFrame();

    }

//	} while (!done);

//FREE UP EVERYTHING HERE
	//Free resources and close SDL
	close();

	return 0;
}