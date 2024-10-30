#ifndef CORE_H
#define  CORE_H

#include <SDL2/SDL.h>

#define W_WIDTH 1280
#define W_HEIGHT 720

#define FRAME_DURATION_MS 16.666666

/*Initielizez sdl*/
void init_sdl(SDL_Window **window, SDL_Renderer **renderer);

/*Main loop*/
void main_loop(SDL_Renderer *renderer);

/*Draw functions*/
void clear_screen(SDL_Renderer *renderer); 

#endif
