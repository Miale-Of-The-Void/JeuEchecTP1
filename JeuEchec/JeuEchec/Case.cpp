#include "Case.h"



Case::Case(int i,int j)
{
	rect = { i * 125, j * 125, 125, 125 };
	if ((i + j) % 2 == 0)
	{
		caseTexture = IMG_Load("Images/WhiteCase.png");
	}
	else
	{
		caseTexture = IMG_Load("Images/BlackCase.png");
	}
}


Case::~Case()
{
}

void Case::Render(SDL_Surface* gScreenSurface)
{
	SDL_BlitSurface(caseTexture, NULL, gScreenSurface, &rect);
}
