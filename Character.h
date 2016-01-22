#include "Arduboy.h"
#include "physics.h"
#include "Weapons.h"
#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
  public:
    //Character();
    Character(char cc, uint8_t s, bool d, uint8_t inter, Rect r);
    void enableMovement(Character *c, Arduboy *d, const unsigned char a[]);
    void activateWeapons(Weapons *w, Arduboy *d, const unsigned char a[]);
    void addAi(Weapons *w, Character *c, Arduboy *d, const unsigned char a[], bool *boolGS);
    char characterClass;
    uint8_t strength;
    bool  destructable;
    uint8_t x;
    uint8_t y;
    uint8_t h;
    uint8_t w;
    unsigned long curMillis;
    unsigned long preMillis;
    uint8_t interval;

        unsigned long curM;
    unsigned long preM;
  
    
    const uint8_t xBound = 120;
    const uint8_t yBound = 56;
    const uint8_t zBound = 0;
    bool lifeState = 1;
    bool moveState = 1;

  private:
  Physics phy;

};
#endif
