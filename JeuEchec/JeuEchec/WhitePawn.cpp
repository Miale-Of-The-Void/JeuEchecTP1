#include "WhitePawn.h"

WhitePawn::WhitePawn(int i, int j)
{
	rect = { i * 125, j * 125, 125, 125 };
	pieceTexture = IMG_Load("Images/WhitePawn.png");
}

WhitePawn::~WhitePawn()
{
}

void WhitePawn::Render(SDL_Surface* gScreenSurface) 
{
	SDL_BlitSurface(pieceTexture, NULL, gScreenSurface, &rect);
}