#pragma once
#include "Piece.h"
class Rook :
	public Piece
{
public:
	Rook(int i, int j, bool black);
	~Rook();

	void Render(SDL_Surface* gScreenSurface);
};

