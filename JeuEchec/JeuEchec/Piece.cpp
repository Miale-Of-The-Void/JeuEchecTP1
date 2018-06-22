#include "Piece.h"

Piece::Piece(int i, int j)
{
	pieceTexture = IMG_Load("Images/WhiteBishop.png");
	rect = { i * 125, j * 125, 125, 125 };
}


Piece::~Piece()
{
}

void Piece::Render(SDL_Surface* gScreenSurface)
{
	SDL_BlitSurface(pieceTexture, NULL, gScreenSurface, &rect);
}

void Piece::Move(SDL_Event e)
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

			if (mi == rect.x && mj == rect.y)
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