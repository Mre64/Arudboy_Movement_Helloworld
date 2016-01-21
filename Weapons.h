#include "Arduboy.h"
#ifndef WEAPONS_H
#define WEAPONS_H

class Weapons {
  public:
    Weapons();
    //void enableBullets(unsigned long *pre,unsigned long *cur);
    uint8_t pressInterval = 250;
    unsigned long pressCurMillis;
    unsigned long pressPreMillis;
    uint8_t ammoInterval = 2;
    unsigned long ammoCurMillis;
    unsigned long ammoPreMillis;
    uint8_t x = 0;
    uint8_t y = 0;
    bool shoot = 0;

  private:

};
#endif
