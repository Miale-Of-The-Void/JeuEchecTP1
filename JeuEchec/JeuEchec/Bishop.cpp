#include "Bishop.h"

Bishop::Bishop(int i, int j, bool black)
	:Piece(i, j)
{
	if (black != true)
		pieceTexture = IMG_Load("Images/WhiteBishop.png");
	else
		pieceTexture = IMG_Load("Images/BlackBishop.png");
}


Bishop::~Bishop()
{
}

void Bishop::Render(SDL_Surface* gScreenSurface)
{
	SDL_BlitSurface(pieceTexture, NULL, gScreenSurface, &rect);
}