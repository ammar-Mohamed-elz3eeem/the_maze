#include "game.h"

int init_game(void)
{
	int fail = 0;

	window = NULL;
	renderer = NULL;

	// Check if engine can initialize videos or not
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n",
		       SDL_GetError());
		fail = 1;
	}

	// Try to create window
	window = SDL_CreateWindow("The Maze", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		fprintf(stderr, "SDL could not create window! SDL_Error: %s\n",
		       SDL_GetError());
		fail = 1;
	}

	// Try to create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		fprintf(stderr, "SDL could not create Renderer! SDL_Error: %s\n",
		       SDL_GetError());
		fail = 1;
	}

	// Try to create texture
	tex = SDL_CreateTexture(renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		SCREEN_WIDTH, SCREEN_HEIGHT);
	if (tex == NULL)
	{
		fprintf(stderr, "SDL could not create texture! SDL_Error: %s\n",
		       SDL_GetError());
		fail = 1;
	}
	return fail;
}

void update_renderer(int textured)
{
	int x, y;

	if (textured)
	{
		SDL_UpdateTexture(tex, NULL, buffer, SCREEN_WIDTH * 4);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, tex, NULL, NULL);

		for (x = 0; x < SCREEN_WIDTH; x++)
		{
			for (y = 0; y < SCREEN_HEIGHT; y++)
			{
				buffer[y][x] = 0;
			}
		}
	}

	SDL_RenderPresent(renderer);
}

void close_game(void)
{
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
