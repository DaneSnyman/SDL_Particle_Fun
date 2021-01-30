#ifndef __BACKGROUND__H__
#define __BACKGROUND__H__
#include "Screen.h"
#include "Particle.h"

namespace dgs
{
  struct Background
  {
    double green = randomNum(5, 250);
    double red = randomNum(5, 250);
    double blue = randomNum(5, 250);
    void update(Screen screen);

  private:
    double colorIG = randPosNeg(randomNum(0, 1));
    double colorIR = randPosNeg(randomNum(0, 1));
    double colorIB = randPosNeg(randomNum(0, 1));
    void setColor();
  };

  void Background::setColor()
  {
    this->colorIG = checkColorI(this->colorIG, this->green);
    this->colorIR = checkColorI(this->colorIR, this->red);
    this->colorIB = checkColorI(this->colorIB, this->blue);
    this->green += (double)this->colorIG;
    this->red += (double)this->colorIR;
    this->blue += (double)this->colorIB;
  }

  void Background::update(Screen screen)
  {
    this->setColor();

    for (int y = 0; y < screen.HEIGHT; y++)
    {
      for (int x = 0; x < screen.WIDTH; x++)
      {
        screen.setPixel(x, y, (int)this->red, (int)this->green, (int)this->blue);
        // screen.setPixel(x, y, 0, 0, 0, 0, true);
      }
    }
  }

} // namespace dgs

#endif //!__BACKGROUND__H__