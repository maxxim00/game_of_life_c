#include "core.h"

void init_sdl(SDL_Window **window, SDL_Renderer **renderer) {
  if(SDL_Init(SDL_INIT_VIDEO)) {
    fprintf(stderr, "SDL_Init error %s\n", SDL_GetError());
    exit(1);
  }
  
  *window = SDL_CreateWindow("main", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W_WIDTH, W_HEIGHT, SDL_WINDOW_SHOWN);
  if(window == NULL) {
    fprintf(stderr, "SDL_Init error %s\n", SDL_GetError());
    SDL_Quit();
    exit(1);
  }
  
  *renderer= SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
  if(renderer == NULL) {
    fprintf(stderr, "SDL_Init error %s\n", SDL_GetError());
    SDL_DestroyWindow(*window);
    SDL_Quit();
    exit(1);
  }
}
