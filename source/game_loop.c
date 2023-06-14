#include "game.h"

/**
 * game_loop - this will be the main game loop which
 * will run the game and check if the game 
 * is still opening or closed
 * @textured: integer represeting if the game should have 
 * image textures or not
 * @maze: an array of numbers represting walls on the maze
*/

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
