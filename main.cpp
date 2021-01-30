#include <iostream>
#include "SDL.h"
#include "Screen.h"
#include "Background.h"
#include "Swarm.h"
#undef main

using namespace std;

int main()
{
  srand((unsigned int)time(NULL)); // Set random seed

  // * Constants
  const char *TITLE = "Particle Fun";
  static const int swarmSize = 5;
  static const int blockSize = 50;

  Screen screen(TITLE, blockSize);
  dgs::Swarm swarm(swarmSize, blockSize);
  dgs::Background background;

  // * Animation Loop
  bool quit = false;
  while (!quit)
  {
    background.update(screen);
    swarm.update(screen);
    screen.update();
    quit = screen.checkPoll();
  }

  // * Exit program
  swarm.close();
  screen.close();
  return 0;
}
