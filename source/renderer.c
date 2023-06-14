#include "game.h"

void render_walls(int *maze, SDL_Point map, Ver2F_t ray_position, Ver2F_t ray_direction, double dist_to_wall, int x, int side, int textured)
{
	int slice_height, draw_start, draw_end, tile_idx, width, height, y;
	double wallX;
	SDL_Point texture_point;
	uint32_t color;

	if (!textured)
	{
		SDL_GetWindowSize(window, &width, &height);
		slice_height = (int)(height / dist_to_wall);
		draw_start = -slice_height / 2 + height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = slice_height / 2 + height / 2;
		if (draw_end >= height)
			draw_end = height - 1;
		if (side == 0)
			SDL_SetRenderDrawColor(renderer, 0xF7, 0xF7, 0xF7, 0xFF);
		else if (side == 1)
			SDL_SetRenderDrawColor(renderer, 0xDE, 0xDE, 0xDE, 0xFF);
		SDL_RenderDrawLine(renderer, x, draw_start, x, draw_end);
	}
	else
	{
		slice_height = (int)(SCREEN_HEIGHT / dist_to_wall);

		draw_start = -slice_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = slice_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;
		
		wallX = 0;
		if (side == 0)
			wallX = ray_position.y + dist_to_wall * ray_direction.y;
		else if (side == 1)
			wallX = ray_position.x + dist_to_wall * ray_direction.x;

		tile_idx = *((int *)maze + map.x * MAP_WIDTH + map.y) - 1;

		wallX -= floor(wallX);

		texture_point.x = (int)(wallX * (double)TEX_WIDTH);
		if (side == 0 && ray_direction.x > 0)
			texture_point.x = TEX_WIDTH - texture_point.x - 1;
		if (side == 1 && ray_direction.y < 0)
			texture_point.x = TEX_WIDTH - texture_point.x - 1;
		
		for (y = draw_start; y < draw_end; y++)
		{
			texture_point.y = ((((y << 1) - SCREEN_HEIGHT + slice_height) <<
				  (int)log2(TEX_HEIGHT)) / slice_height) >> 1;
			color = images[tile_idx][texture_point.x][texture_point.y];
			if (side == 1)
				color = (color >> 1) & 8355711;
			buffer[y][x] = color;
		}
		render_background_texture(map, ray_direction, dist_to_wall, wallX, draw_end, x, side);
	}
}

void render_background_texture(SDL_Point map, Ver2F_t ray_dir, double dist_to_wall, double wallX, int draw_end, int x, int side)
{
	Ver2F_t floor_wall, current_floor;
	SDL_Point floor_tex;
	double weight, current_dist;
	int y;

	if (side == 0 && ray_dir.x > 0)
	{
		floor_wall.x = map.x;
		floor_wall.y = map.y + wallX;
	}
	else if (side == 0 && ray_dir.x < 0)
	{
		floor_wall.x = map.x + 1.0;
		floor_wall.y = map.y + wallX;
	}
	else if (side == 1 && ray_dir.y > 0)
	{
		floor_wall.x = map.x + wallX;
		floor_wall.y = map.y;
	}
	else
	{
		floor_wall.x = map.x + wallX;
		floor_wall.y = map.y + 1.0;
	}

	if (draw_end < 0)
		draw_end = SCREEN_HEIGHT;
	
	for (y = draw_end + 1; y < SCREEN_HEIGHT; y++)
	{
		current_dist = SCREEN_HEIGHT / (2.0 * y - SCREEN_HEIGHT);
		weight = current_dist / dist_to_wall;

		current_floor.x = weight * floor_wall.x + (1.0 - weight) * pos.x;
		current_floor.y = weight * floor_wall.y + (1.0 - weight) * pos.y;

		floor_tex.x = (int)(current_floor.x * TEX_WIDTH) % TEX_WIDTH;
		floor_tex.y = (int)(current_floor.y * TEX_HEIGHT) % TEX_HEIGHT;

		buffer[y][x] = images[5][floor_tex.y][floor_tex.x];
		buffer[SCREEN_HEIGHT - y][x] = images[2][floor_tex.y][floor_tex.x];
	}
}

void render_flat_background(void)
{
	SDL_Rect ceiling, floor;
	int width, height;

	SDL_GetWindowSize(window, &width, &height);

	ceiling.x = 0;
	ceiling.y = 0;
	ceiling.w = width;
	ceiling.h = height / 2;

	floor.x = 0;
	floor.y = height / 2;
	floor.w = width;
	floor.h = height / 2;

	SDL_SetRenderDrawColor(renderer, 0x59, 0x85, 0x94, 0xFF);
	SDL_RenderFillRect(renderer, &ceiling);

	SDL_SetRenderDrawColor(renderer, 0x1E, 0x29, 0x34, 0xFF);
	SDL_RenderFillRect(renderer, &floor);
}
