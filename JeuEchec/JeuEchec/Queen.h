#pragma once
#include "Piece.h"
class Queen :
	public Piece
{
public:
	Queen(int i, int j, bool black);
	~Queen();

	void Render(SDL_Surface* gScreenSurface);
};

