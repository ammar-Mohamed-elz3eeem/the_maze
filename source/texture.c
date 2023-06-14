#include "game.h"

void load_textures(char *map_name)
{
	SDL_Surface *tex_surfaces[TEX_COUNT];
	uint8_t *pixel;
	int i, j, k;

	if (strcmp(map_name, "maps/map_0") == 0)
	{
		tex_surfaces[0] = IMG_Load("images/graystone.png");
		tex_surfaces[1] = IMG_Load("images/graystone.png");
		tex_surfaces[2] = IMG_Load("images/sky.png");
		tex_surfaces[3] = IMG_Load("images/wood.png");
		tex_surfaces[4] = IMG_Load("images/wood.png");
		tex_surfaces[5] = IMG_Load("images/grass.png");
	}
	else
	{
		tex_surfaces[0] = IMG_Load("images/hedge1.png");
		tex_surfaces[1] = IMG_Load("images/hedge2.png");
		tex_surfaces[2] = IMG_Load("images/gate.png");
		tex_surfaces[3] = IMG_Load("images/hedge1.png");
		tex_surfaces[4] = IMG_Load("images/sky.png");
		tex_surfaces[5] = IMG_Load("images/grass.png");
	}


	for (i = 0; i < TEX_COUNT; i++)
	{
		for (j = 0; j < TEX_HEIGHT; j++)
		{
			for (k = 0; k < TEX_WIDTH; k++)
			{
				pixel = (uint8_t *)tex_surfaces[i]->pixels
					+ k * tex_surfaces[i]->pitch + j *
					tex_surfaces[i]->format->BytesPerPixel;

				images[i][j][k] = pixel[0] | pixel[1] << 8
					| pixel[2] << 16;
			}
		}
	}

	for (i = 0; i < TEX_COUNT; i++)
	{
		SDL_FreeSurface(tex_surfaces[i]);
		tex_surfaces[i] = NULL;
	}
}
