#ifndef __PARTICLE__H__
#define __PARTICLE__H__
#include "SDL.h"
#include <iostream>
#include "Screen.h"

namespace dgs
{
  double randomNum(double min, double max)
  {
    return (((double)rand() / RAND_MAX) * max) + min;
  }

  double randPosNeg(double num)
  {
    double randomNo = (double)rand() / RAND_MAX;
    return (randomNo < 0.5) ? -num : num;
  }

  double checkColorI(double colorI, double color)
  {
    double icol = colorI;
    if ((int)color < 5 || (int)color > 250)
    {
      icol = -icol;
    }
    return icol;
  }

  struct Particle
  {
    int x;
    int y;
    double speedX;
    double speedY;
    int blockSize;

    Particle(int iX, int iY, double iSpeedX, double iSpeedY, double iColorSpeed, int iBlockSize);
    Particle();
    void update();

    double green;
    double red;
    double blue;

  private:
    double colorIG;
    double colorIR;
    double colorIB;
    void setColor();
    void setPos();
  };

  Particle::Particle() {}
  Particle::Particle(int iX, int iY, double iSpeedX, double iSpeedY, double iColorSpeed, int iBlockSize)
  {
    this->x = iX;
    this->y = iY;
    this->speedX = iSpeedX;
    this->speedY = iSpeedY;
    this->green = randomNum(iColorSpeed, 255 - iColorSpeed);
    this->blue = randomNum(iColorSpeed, 255 - iColorSpeed);
    this->red = randomNum(iColorSpeed, 255 - iColorSpeed);
    this->colorIG = randPosNeg(randomNum(2, iColorSpeed));
    this->colorIR = randPosNeg(randomNum(2, iColorSpeed));
    this->colorIB = randPosNeg(randomNum(2, iColorSpeed));
    this->blockSize = iBlockSize;
  }

  void Particle::update()
  {
    this->setColor();
    this->setPos();
  }

  void Particle::setColor()
  {
    this->colorIG = checkColorI(this->colorIG, this->green);
    this->colorIR = checkColorI(this->colorIR, this->red);
    this->colorIB = checkColorI(this->colorIB, this->blue);
    this->green += (double)this->colorIG;
    this->red += (double)this->colorIR;
    this->blue += (double)this->colorIB;
  }

  void Particle::setPos()
  {
    if (this->x < 5 || this->x > Screen::WIDTH - this->blockSize)
    {
      this->speedX = -this->speedX;
    }

    if (this->y < 5 || this->y > Screen::HEIGHT - this->blockSize)
    {
      this->speedY = -this->speedY;
    }

    this->x += (int)this->speedX;
    this->y += (int)this->speedY;
  }
} // namespace dgs
#endif //!__PARTICLE__H__