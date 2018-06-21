#pragma once
#include "Piece.h"
class King :
	public Piece
{
public:
	King(int i, int j, bool black);
	~King();

	void Render(SDL_Surface* gScreenSurface);
};

