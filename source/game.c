#include "game.h"

/* global variables */
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *tex;
uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
uint32_t images[TEX_COUNT][TEX_HEIGHT][TEX_WIDTH];
Ver2F_t pos;
Ver2F_t dir;
Ver2F_t plane;
double time;

/**
 * main - entry point of the game
 * @argc: number of command line arguments
 * @argv: the command line arguemnts array
 * Return: 0 on success, otherwise 1
*/

int main(int argc, char *argv[])
{
	int *maze;
	char *map_name;
	int textured;

	pos.x = 1;
	pos.y = 12;
	dir.x = 1;
	dir.y = -0.66;
	plane.x = 0;
	plane.y = 0.66;
	time = 0;

	map_name = "\0";
	textured = 1;

	if (argc == 3)
	{
		if (strcmp(argv[2], "no_tex") == 0)
			textured = 0;
		map_name = argv[1];
	}
	else if (argc == 2)
	{
		if (strcmp(argv[1], "no_tex") == 0)
		{
			map_name = "maps/map_0";
			textured = 0;
		}
		else
			map_name = argv[1];
	}
	else if (argc == 1)
		map_name = "maps/map_0";
	
	if (init_game())
		return (1);
	
	maze = NULL;
	maze = parse_map(map_name, maze);
	if (maze == NULL)
		return (1);
	if (textured)
		load_textures(map_name);
	game_loop(textured, maze);
	close_game();
	free(maze);
	return (0);
}
