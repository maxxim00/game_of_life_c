#include "core.h"

void clear_screen(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
  SDL_RenderClear(renderer);
}
