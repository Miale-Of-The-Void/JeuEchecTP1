#pragma once
#include "Piece.h"
class Knight :
	public Piece
{
public:
	Knight(int i, int j, bool black);
	~Knight();

	void Render(SDL_Surface* gScreenSurface);

};

