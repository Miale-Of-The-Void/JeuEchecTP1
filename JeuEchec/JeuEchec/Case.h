#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Case
{
public:
	Case(int i, int j);
	~Case();

	SDL_Rect rect;
	SDL_Surface* caseTexture;

	void Render(SDL_Surface* gScreenSurface);

};

