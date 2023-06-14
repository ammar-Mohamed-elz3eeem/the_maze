#ifndef __GAME_VARS__
#define __GAME_VARS__

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *tex;
extern uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH]; 
extern uint32_t images[TEX_COUNT][TEX_HEIGHT][TEX_WIDTH];
extern Ver2F_t pos;
extern Ver2F_t dir;
extern Ver2F_t plane;
extern double time;

#endif