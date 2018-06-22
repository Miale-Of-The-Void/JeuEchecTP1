#include "WhitePawn.h"

WhitePawn::WhitePawn(int i, int j, bool black)
	:Piece(i ,j)
{
	if (black != true)
		pieceTexture = IMG_Load("Images/WhitePawn.png");
	else
		pieceTexture = IMG_Load("Images/BlackPawn.png");
}

WhitePawn::~WhitePawn()
{
}

void WhitePawn::Render(SDL_Surface* gScreenSurface) 
{
	SDL_BlitSurface(pieceTexture, NULL, gScreenSurface, &rect);
}

void WhitePawn::Move(SDL_Event e)
{
	while (SDL_PollEvent(&e) != 0)
	{
		bool selected = false;
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			int x, y;
			SDL_GetMouseState(&y, &x);

			int mi = x / 125;
			int mj = y / 125;

			if (mi == (rect.x / 125) && mj == (rect.y / 125))
			{
				selected = true;
			}

		}

		if (e.type == SDL_MOUSEMOTION)
		{
			int x, y;
			SDL_GetMouseState(&y, &x);
			int mi = x / 125;
			int mj = y / 125;

			if (selected == true)
			{
				rect.x = x;
				rect.y = y;
			}

		}

		if (e.type == SDL_MOUSEBUTTONUP)
		{
			int x, y;
			SDL_GetMouseState(&y, &x);
			int mi = x / 125;
			int mj = y / 125;

			selected = false;
		}
	}
}