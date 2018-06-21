#include "Rook.h"



Rook::Rook(int i, int j, bool black)
	:Piece(i,j)
{
	if (black != true)
		pieceTexture = IMG_Load("Images/WhiteRook.png");
	else
		pieceTexture = IMG_Load("Images/BlackRook.png");
}


Rook::~Rook()
{
}

void Rook::Render(SDL_Surface* gScreenSurface)
{
	SDL_BlitSurface(pieceTexture, NULL, gScreenSurface, &rect);
}
