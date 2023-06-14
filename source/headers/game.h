#ifndef __GAME_HEADER__
#define __GAME_HEADER__

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define TEX_COUNT 6
#define TEX_WIDTH 64
#define TEX_HEIGHT 64
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define MAP_CHAR_COUNT 1275

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "global.h"

int *parse_map(char *filename, int *map);
void load_textures(char *map_name);

int init_game(void);
void update_renderer(int textured);
void close_game(void);

void input(int *maze);
int quit(void);
void game_loop(int textured, int *maze);

void raycasting(int *maze, int textured);
void render_walls(int *maze, SDL_Point map, Ver2F_t rayPos, Ver2F_t rayDir, double distToWall, int x, int side, int textured);
void render_flat_background(void);
void render_background_texture(SDL_Point map, Ver2F_t ray_dir, double dist_to_wall, double wallX, int draw_end, int x, int side);

#endif