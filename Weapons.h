#include "Arduboy.h"
#ifndef WEAPONS_H
#define WEAPONS_H

class Weapons {
  public:
    Weapons();
    uint8_t x = 1;
    uint8_t y = 70;
    bool shootBullet = 0;
    bool shootBomb = 0;
    bool shooting = 0;  
    unsigned long countFrames;
  private:
};
#endif
