#include "core.h"

/*local*/
static void handle_events(SDL_Event event, Uint8 *is_running);

void main_loop(SDL_Renderer *renderer) {
  SDL_Event event;
  
  Uint64 start; 
  Uint64 end; 
  Uint64 frequency = SDL_GetPerformanceFrequency();
  double elapsed;
  
  Uint8 is_running = 1;
  
  /*Start of the loop*/
  while(is_running) {
    start = SDL_GetPerformanceCounter();

    /*Update*/
    handle_events(event, &is_running);

    /*Draw*/
    clear_screen(renderer);
    SDL_RenderPresent(renderer);

    
    /*FPS limit calculations and delay*/
    end = SDL_GetPerformanceCounter();
    elapsed = (end - start) / (double)frequency * 1000.f;
    if(elapsed < FRAME_DURATION_MS - elapsed) {
      SDL_Delay((Uint32)(FRAME_DURATION_MS - elapsed));
    }
  }
}

static void handle_events(SDL_Event event, Uint8 *is_running) {
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_KEYDOWN:
        if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
          *is_running = 0;
        }
        break;
      case SDL_QUIT:
        *is_running = 0;
        break;
    }
  }
}

