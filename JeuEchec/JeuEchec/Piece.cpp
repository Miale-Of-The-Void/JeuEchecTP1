#include "Piece.h"

Piece::Piece(int i, int j)
{
	rect = { i * 125, j * 125, 125, 125 };
}


Piece::~Piece()
{
}

void Piece::Render(SDL_Surface* gScreenSurface)
{
	SDL_BlitSurface(pieceTexture, NULL, gScreenSurface, &rect);
}
