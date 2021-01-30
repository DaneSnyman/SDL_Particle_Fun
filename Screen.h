#ifndef __SCREEN__H__
#define __SCREEN__H__
#include <iostream>
#include "SDL.h"

struct Screen
{
  static const int WIDTH = 1024;
  static const int HEIGHT = 768;
  const int blockSize;
  Screen(const char *iTitle, int iBlockSize);
  bool checkPoll();
  void close();
  void setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 0xFF, bool texture2 = false);
  void update();

private:
  const char *title;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  // SDL_Texture *texture2;
  Uint32 *buffer;
  // Uint32 *buffer2;
  bool checkInit();
  void createWindow();
  void createRenderer();
  void createTexture();
};

#endif //!__SCREEN__H__