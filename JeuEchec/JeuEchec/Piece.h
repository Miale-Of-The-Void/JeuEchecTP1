#pragma once
#include <SDL.h>
#include <SDL_image.h>


class Piece
{
public:
	Piece(int i,int j);
	~Piece();

	SDL_Rect rect;
	SDL_Surface* pieceTexture;

	virtual void Render(SDL_Surface* gScreenSurface);
	virtual void Move(SDL_Event e);
};

