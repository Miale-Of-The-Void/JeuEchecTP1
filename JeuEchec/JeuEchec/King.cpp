#include "King.h"



King::King(int i, int j, bool black)
	:Piece(i, j)
{
	if (black != true)
		pieceTexture = IMG_Load("Images/WhiteKing.png");
	else
		pieceTexture = IMG_Load("Images/BlackKing.png");
}


King::~King()
{
}

void King::Render(SDL_Surface* gScreenSurface)
{
	SDL_BlitSurface(pieceTexture, NULL, gScreenSurface, &rect);
}