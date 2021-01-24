#include <iostream>
#include "SDL.h"
#undef main

using namespace std;

int checkInit()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    cout << "SDL init failed!\n";
    return 1;
  }
  return 0;
}

void animationLoop()
{
  bool quit = false;
  SDL_Event event;

  while (!quit)
  {
    // *Animate shit here...

    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        quit = true;
      }
    }
  }
}

SDL_Window *createWindow(const char *title, int screenWidth, int screenHeight, Uint32 flags)
{
  SDL_Window *window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, flags);
  if (window == NULL)
  {
    cout << "Could not create window:\n"
         << SDL_GetError() << endl;
    SDL_Quit();
    return NULL;
  }
  return window;
}

int main()
{
  // * Constants
  const char *TITLE = "SDL2 Template";
  const int WIDTH = 800;
  const int HEIGHT = 600;
  const Uint32 WINDOWFLAGS = SDL_WINDOW_SHOWN;

  // * Create window
  checkInit(); // Check if SDL init
  SDL_Window *window = createWindow(TITLE, WIDTH, HEIGHT, WINDOWFLAGS);

  // * Animation Loop
  animationLoop();

  // * Exit program
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
