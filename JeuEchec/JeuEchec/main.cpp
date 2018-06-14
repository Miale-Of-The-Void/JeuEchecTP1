/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>


//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* WhiteCase = NULL;
SDL_Surface* WhitePawn = NULL;
SDL_Surface* WhiteKing = NULL;
SDL_Surface* WhiteQueen = NULL;
SDL_Surface* WhiteRook = NULL;
SDL_Surface* WhiteKnight = NULL;
SDL_Surface* WhiteBishop = NULL;
SDL_Surface* BlackCase = NULL;
SDL_Surface* BlackPawn = NULL;
SDL_Surface* BlackKing = NULL;
SDL_Surface* BlackQueen = NULL;
SDL_Surface* BlackKnight = NULL;
SDL_Surface* BlackRook = NULL;
SDL_Surface* BlackBishop = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	WhiteCase = IMG_Load("Images/WhiteCase.png");
	WhitePawn = IMG_Load("Images/WhitePawn.png");
	WhiteKing = IMG_Load("Images/WhiteKing.png");
	WhiteQueen = IMG_Load("Images/WhiteQueen.png");
	WhiteRook = IMG_Load("Images/WhiteRook.png");
	WhiteKnight = IMG_Load("Images/WhiteKnight.png");
	WhiteBishop = IMG_Load("Images/WhiteBishop.png");


	BlackCase = IMG_Load("Images/BlackCase.png");
	BlackPawn = IMG_Load("Images/BlackPawn.png");
	BlackKing = IMG_Load("Images/BlackKing.png");
	BlackQueen = IMG_Load("Images/BlackQueen.png");
	BlackRook = IMG_Load("Images/BlackRook.png");
	BlackKnight = IMG_Load("Images/BlackKnight.png");
	BlackBishop = IMG_Load("Images/BlackBishop.png");

	if (WhiteCase == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		success = false;
	}

	if (BlackCase == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(WhiteCase);
	WhiteCase = NULL;
	SDL_FreeSurface(WhitePawn);
	WhitePawn = NULL;
	SDL_FreeSurface(WhiteKing);
	WhiteKing = NULL;
	SDL_FreeSurface(WhiteQueen);
	WhiteQueen = NULL;
	SDL_FreeSurface(WhiteRook);
	WhiteRook = NULL;
	SDL_FreeSurface(WhiteKnight);
	WhiteKnight = NULL;
	SDL_FreeSurface(WhiteBishop);
	WhiteBishop = NULL;

	SDL_FreeSurface(BlackCase);
	WhiteCase = NULL;
	SDL_FreeSurface(BlackPawn);
	BlackPawn = NULL;
	SDL_FreeSurface(BlackKing);
	BlackKing = NULL;
	SDL_FreeSurface(BlackQueen);
	BlackQueen = NULL;
	SDL_FreeSurface(BlackRook);
	BlackRook = NULL;
	SDL_FreeSurface(BlackKnight);
	BlackKnight = NULL;
	SDL_FreeSurface(BlackBishop);
	BlackBishop = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{

					if ((i+j)% 2 == 0)
					{
						SDL_Rect rect = { i * 125, j * 125, 125, 125 };
						//Apply the image
						SDL_BlitSurface(WhiteCase, NULL, gScreenSurface, &rect);
					}
					else
					{
						SDL_Rect rect = { i * 125, j * 125, 125, 125 };
						//Apply the image
						SDL_BlitSurface(BlackCase, NULL, gScreenSurface, &rect);
					}
					//Update the surface
					SDL_UpdateWindowSurface(gWindow);
				}
			}
			//Update the surface
			SDL_UpdateWindowSurface(gWindow);

			//Wait two seconds
			SDL_Delay(2000);
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}