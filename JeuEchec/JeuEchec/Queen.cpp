#include "Queen.h"



Queen::Queen(int i, int j, bool black)
	:Piece(i, j)
{
	if (black != true)
		pieceTexture = IMG_Load("Images/WhiteQueen.png");
	else
		pieceTexture = IMG_Load("Images/BlackQueen.png");
}


Queen::~Queen()
{
}

void Queen::Render(SDL_Surface* gScreenSurface)
{
	SDL_BlitSurface(pieceTexture, NULL, gScreenSurface, &rect);
}
