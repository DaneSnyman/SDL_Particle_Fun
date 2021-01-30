#include "Screen.h"

Screen::Screen(const char *iTitle, int iBlockSize) : title(iTitle), blockSize(iBlockSize)
{
  this->checkInit();
  this->createWindow();
  this->createRenderer();
  // SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND);
  this->createTexture();
  SDL_SetTextureBlendMode(this->texture, SDL_BLENDMODE_BLEND);
  // SDL_SetTextureBlendMode(this->texture2, SDL_BLENDMODE_BLEND);
  this->buffer = new Uint32[this->WIDTH * this->HEIGHT];
  // this->buffer2 = new Uint32[this->WIDTH * this->HEIGHT];
}

bool Screen::checkInit()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cout << "SDL init failed!\n";
    return false;
  }
  return true;
}

void Screen::createWindow()
{
  this->window = SDL_CreateWindow(this->title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->WIDTH, this->HEIGHT, SDL_WINDOW_SHOWN);

  if (this->window == NULL)
  {
    std::cout << "Error creating window: " << SDL_GetError() << std::endl;
    SDL_Quit();
  }
}

void Screen::createRenderer()
{
  this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_PRESENTVSYNC);

  if (this->renderer == NULL)
  {
    std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(this->window);
    SDL_Quit();
  }
}

void Screen::createTexture()
{
  this->texture = SDL_CreateTexture(this->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, this->WIDTH, this->HEIGHT);
  // this->texture2 = SDL_CreateTexture(this->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, this->WIDTH, this->HEIGHT);

  if (this->texture == NULL)
  {
    std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(this->window);
    SDL_Quit();
  }
}

bool Screen::checkPoll()
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_QUIT)
    {
      return true;
    }
    return false;
  }
  return false;
}

void Screen::update()
{

  SDL_UpdateTexture(this->texture, NULL, this->buffer, this->WIDTH * sizeof(Uint32));
  // SDL_UpdateTexture(this->texture2, NULL, this->buffer2, this->WIDTH * sizeof(Uint32));

  SDL_RenderClear(this->renderer);
  SDL_RenderCopy(this->renderer, this->texture, NULL, NULL);
  // SDL_RenderCopy(this->renderer, this->texture2, NULL, NULL);
  SDL_RenderPresent(this->renderer);
}

void Screen::setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool texture2)
{
  if (x > 0 || x < this->WIDTH || y > 0 || y < this->HEIGHT)
  {
    Uint32 color = 0;
    color += r;
    color <<= 8;
    color += g;
    color <<= 8;
    color += b;
    color <<= 8;
    color += a;

    if (texture2)
    {
      // this->buffer2[y * this->WIDTH + x] = color;
    }
    else
    {
      this->buffer[y * this->WIDTH + x] = color;
    }
  }
}

void Screen::close()
{
  delete[] this->buffer;
  SDL_DestroyTexture(this->texture);
  // SDL_DestroyTexture(this->texture2);
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);
  SDL_Quit();
}