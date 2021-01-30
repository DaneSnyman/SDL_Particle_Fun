#ifndef __SWARM__H__
#define __SWARM__H__
#include "Particle.h"
namespace dgs
{

  struct Swarm
  {
    const int nParticles;
    const int blockSize;
    Particle *particles;
    Swarm(int particles, int iBlockSize);
    void close();
    void update(Screen screen);
  };

  Swarm::Swarm(int particles, int iBlockSize) : nParticles(particles), blockSize(iBlockSize)
  {
    this->particles = new Particle[nParticles];

    for (int i = 0; i < nParticles; i++)
    {
      int x = (int)randomNum(this->blockSize, Screen::WIDTH - this->blockSize * 2);
      int y = (int)randomNum(this->blockSize, Screen::HEIGHT - this->blockSize * 2);
      double speedX = randPosNeg(randomNum(1, 3));
      double speedY = randPosNeg(randomNum(1, 3));
      this->particles[i] = Particle(x, y, speedX, speedY, 2, this->blockSize);
    }
  };

  void Swarm::update(Screen screen)
  {
    const Uint8 a = 255;
    for (int k = 0; k < this->nParticles; k++)
    {
      this->particles[k].update();

      for (int i = 0; i < this->blockSize; i++)
      {
        for (int j = 0; j < this->blockSize; j++)
        {
          if (particles[k].x + i < Screen::WIDTH && particles[k].y + j < Screen::HEIGHT)
            screen.setPixel(particles[k].x + i, particles[k].y + j, (int)particles[k].red, (int)particles[k].green, (int)particles[k].blue, a);
        }
      }
    }
  }

  void Swarm::close()
  {
    delete[] this->particles;
  }
} // namespace dgs

#endif //!__SWARM__H__