#include "Arduboy.h"
#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
  public:
    //Character();
    Character(char cc, uint8_t s, bool d, uint8_t dX, uint8_t dY, uint8_t dH, uint8_t dW, uint8_t inter);
    void enableMovement(uint8_t *x, uint8_t *y, unsigned long *pre, unsigned long *cur, uint8_t inter, uint8_t zB, uint8_t xB, uint8_t yB,  Arduboy *d, const unsigned char a[]);
    void activateWeapons(uint8_t *x, uint8_t *y, unsigned long *pressPre, unsigned long *pressCur, uint8_t pressInter, unsigned long *ammoPre, unsigned long *ammoCur, uint8_t ammoInter, uint8_t zB, uint8_t xB, uint8_t yB, Arduboy *d, bool * shoot);
    char characterClass;
    uint8_t strength;
    bool  destructable;
    uint8_t dimX;
    uint8_t dimY;
    uint8_t dimH;
    uint8_t dimW;
    unsigned long curMillis;
    unsigned long preMillis;
    uint8_t interval;
    const uint8_t xBound = 120;
    const uint8_t yBound = 56;
    const uint8_t zBound = 0;

  private:

};
#endif
