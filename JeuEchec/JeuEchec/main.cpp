/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include "Case.h"
#include "Piece.h"
#include "WhitePawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include <vector>
#include <iostream>


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

//Vecteurs pour creer le board
std::vector<std::vector<Case>> Board = std::vector<std::vector<Case>>();
std::vector<std::vector<Piece*>> pieceBoard = std::vector<std::vector<Piece*>>();

Piece* selectedPiece = nullptr;

int CaseX;
int CaseY;

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

	return success;
}

void close()
{
	//Deallocate surface
	/*SDL_FreeSurface(WhiteCase);
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
	BlackBishop = NULL;*/

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
				Board.push_back(std::vector<Case>());
				pieceBoard.push_back(std::vector<Piece*>());
				for (int j = 0; j < 8; j++)
				{
					Board[i].push_back(Case(i, j));
					if (j == 0 && i == 0)
						pieceBoard[i].push_back(new Rook(i, j,true));
					else if (j == 0 && i == 1)
						pieceBoard[i].push_back(new Knight(i, j, true));
					else if (j == 0 && i == 2)
						pieceBoard[i].push_back(new Bishop(i, j, true));
					else if (j == 0 && i == 3)
						pieceBoard[i].push_back(new Queen(i, j, true));
					else if (j == 0 && i == 4)
						pieceBoard[i].push_back(new King(i, j, true));
					else if (j == 0 && i == 5)
						pieceBoard[i].push_back(new Bishop(i, j, true));
					else if (j == 0 && i == 6)
						pieceBoard[i].push_back(new Knight(i, j, true));
					else if (j == 0 && i == 7)
						pieceBoard[i].push_back(new Rook(i, j, true));
					else if (j == 1)
						pieceBoard[i].push_back(new WhitePawn(i, j, true));
					else if (j == 7 && i == 0)
						pieceBoard[i].push_back(new Rook(i, j, false));
					else if (j == 7 && i == 1)
						pieceBoard[i].push_back(new Knight(i, j, false));
					else if (j == 7 && i == 2)
						pieceBoard[i].push_back(new Bishop(i, j, false));
					else if (j == 7 && i == 3)
						pieceBoard[i].push_back(new Queen(i, j, false));
					else if (j == 7 && i == 4)
						pieceBoard[i].push_back(new King(i, j, false));
					else if (j == 7 && i == 5)
						pieceBoard[i].push_back(new Bishop(i, j, false));
					else if (j == 7 && i == 6)
						pieceBoard[i].push_back(new Knight(i, j, false));
					else if (j == 7 && i == 7)
						pieceBoard[i].push_back(new Rook(i, j, false));
					else
						pieceBoard[i].push_back(new WhitePawn(i, j, false));
				}
			}
			SDL_Event e;
			while (true)
			{
				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						Board[i][j].Render(gScreenSurface);
					}
				}

				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (j == 0 || j == 1 || j == 6 || j == 7)
						{
							pieceBoard[i][j]->Render(gScreenSurface);
						}
					}
				}

				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					bool selected = false;
					if (e.type == SDL_MOUSEBUTTONDOWN)
					{
						int x, y;
						SDL_GetMouseState(&y, &x);

						CaseY = y / 125;
						CaseX = x / 125;

						if (pieceBoard[CaseY][CaseX] != nullptr)
						{
							selectedPiece = pieceBoard[CaseY][CaseX];
						}
						

					}

					if (e.type == SDL_MOUSEMOTION)
					{
						int x, y;
						SDL_GetMouseState(&y, &x);

						if (selectedPiece != nullptr)
						{
							selectedPiece->rect.x = y;
							selectedPiece->rect.y = x;
						}

					}

					if (e.type == SDL_MOUSEBUTTONUP)
					{
						int x, y;
						SDL_GetMouseState(&y, &x);

						int i = x / 125;
						int j = y / 125;
						int mi = ((y / 125) * 125);
						int mj = ((x / 125) * 125);

						if (selectedPiece != nullptr)
						{
							selectedPiece->rect.x = mi;
							selectedPiece->rect.y = mj;
							pieceBoard[i][j] = selectedPiece;

							pieceBoard[CaseY][CaseX] = NULL;
							selectedPiece = nullptr;
						}
					}
				}
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}