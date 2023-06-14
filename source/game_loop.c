#include "game.h"

void game_loop(int textured, int *maze)
{
	while (!quit())
	{
		if (!textured)
			render_flat_background();
		raycasting(maze, textured);
		input(maze);
	}
	close_game();
	free(maze);
}
