#pragma once
#include "Piece.h"
class WhitePawn :
	public Piece
{
public:
	WhitePawn(int i, int j, bool black);
	~WhitePawn();

	void Render(SDL_Surface* gScreenSurface);
	void Move();
};

