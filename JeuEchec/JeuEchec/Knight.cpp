#include "Knight.h"



Knight::Knight(int i, int j, bool black)
	:Piece(i, j)
{
	if (black != true)
		pieceTexture = IMG_Load("Images/WhiteKnight.png");
	else
		pieceTexture = IMG_Load("Images/BlackKnight.png");
}


Knight::~Knight()
{
}

void Knight::Render(SDL_Surface* gScreenSurface)
{
	SDL_BlitSurface(pieceTexture, NULL, gScreenSurface, &rect);
}