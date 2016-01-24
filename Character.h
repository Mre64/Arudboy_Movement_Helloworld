#include "Arduboy.h"
#include "physics.h"
#include "Weapons.h"
#include <math.h>
#ifndef CHARACTER_H
#define CHARACTER_H

#define MIN 25
#define MAX 65
#define M_PI 3.14159

class Character {
  public:
    Character(Rect r);
    void enableMovement(Character *c, Arduboy *d, const unsigned char a[]);
    void activateWeapons(Arduboy *d, const unsigned char b[]);
    void addAi( Character *c, Arduboy *d, const unsigned char g[], bool *boolGS);
    void aiAttackFormation(Character *c, Arduboy *d, const unsigned char s[], bool *boolGS);

    char characterClass;
    uint8_t strength;
    bool  destructable;
    uint8_t x;
    uint8_t y;
    uint8_t h;
    uint8_t w;
    bool lifeState = 1;
    bool moveState = 1;
    uint8_t killCount;
    float sinX = 0;
    float sinY;
    Weapons wep;  
    uint8_t randO = 0;
    bool randState = 1;
  private:

  int getrand(int min, int max);

    Point dim;
    Physics phy;

//    float sinX = -3.14159;
//    float sinY;

};
#endif
