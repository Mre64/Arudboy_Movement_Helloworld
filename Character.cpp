#include "Character.h"
#include <stdio.h>

//Character::Character(){
//}
Character::Character(char cc, uint8_t s, bool d, uint8_t dX, uint8_t dY, uint8_t dH, uint8_t dW, uint8_t inter) {
  characterClass = cc;
  strength = s;
  destructable = d;
  dimX = dX;
  dimY = dY;
  dimH = dH;
  dimW = dW;
  interval = inter;
}

void Character::enableMovement(uint8_t *x, uint8_t *y, unsigned long *pre, unsigned long *cur, uint8_t inter, uint8_t zB, uint8_t xB, uint8_t yB,  Arduboy *d, const unsigned char a[]) {

  d->drawBitmap(*y, *x, a, 8, 8, WHITE);
  if (d->pressed(UP_BUTTON) && (*x > zB)) {
    *cur = millis();
    if (*cur - *pre > inter) {
      *x = *x - 1;
      *pre = *cur;
    }
  } else if (d->pressed(DOWN_BUTTON) && (*x < yB)) {
    *cur = millis();

    if (*cur - *pre > inter) {
      *pre = *cur;
      *x = *x + 1;
    }
  } else if (d->pressed(LEFT_BUTTON) && (*y > zB)) {
    *cur = millis();
    if (*cur - *pre > inter) {
      *pre = *cur;
      *y = *y - 1;
    }
  } else if (d->pressed(RIGHT_BUTTON) && (*y < xB)) {
    *cur = millis();

    if (*cur - *pre > inter) {
      *pre = *cur;
      *y = *y + 1;
    }
  }
}

void Character::activateWeapons(uint8_t *x, uint8_t *y, unsigned long *pressPre, unsigned long *pressCur, uint8_t pressInter, unsigned long *ammoPre, unsigned long *ammoCur, uint8_t ammoInter, uint8_t zB, uint8_t xB, uint8_t yB, Arduboy *d, bool * shoot) {

  if (*shoot) {
    *ammoCur = millis();
    if (*ammoCur - *ammoPre > ammoInter) {
      *ammoPre = *ammoCur;
      if (*x < 1) {
        *x = 0;
        shoot = 0;
      } else {
        *x = *x - 1;
        d->drawPixel(*y, *x, WHITE);
      }
    }
  }
  if (d->pressed(A_BUTTON)) {
    *pressCur = millis();
    if (*pressCur - *pressPre > pressInter) {
      *pressPre = *pressCur;
      *x = dimX + 4;
      *y = dimY + 4;
      *shoot = 1;
    }
  }
}
