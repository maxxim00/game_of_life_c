#include "core.h"

int main() {
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  init_sdl(&window, &renderer);
  main_loop(renderer);

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();  
  return 0;
}
