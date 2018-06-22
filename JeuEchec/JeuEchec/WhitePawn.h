#pragma once
#include "Piece.h"
class WhitePawn :
	public Piece
{
public:
	WhitePawn(int i, int j, bool black);
	~WhitePawn();

	virtual void Render(SDL_Surface* gScreenSurface);
	virtual void Move(SDL_Event e);
};

