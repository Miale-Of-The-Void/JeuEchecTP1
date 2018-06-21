#pragma once
#include "Piece.h"
class Bishop :
	public Piece
{
public:
	Bishop(int i, int j, bool black);
	~Bishop();

	void Render(SDL_Surface* gScreenSurface);
};

