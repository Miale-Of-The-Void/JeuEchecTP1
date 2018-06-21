#pragma once
#include "Piece.h"
class WhitePawn :
	public Piece
{
public:
	WhitePawn(int i, int j);
	~WhitePawn();

	SDL_Surface* pieceTexture;
	void Render(SDL_Surface* gScreenSurface);
};

