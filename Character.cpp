#include "Character.h"
#include <stdio.h>

//Character::Character(){
//}
Character::Character(char cc, uint8_t s, bool d, uint8_t dX, uint8_t dY, uint8_t dH, uint8_t dW, uint8_t inter) {
  characterClass = cc;
  strength = s;
  destructable = d;
  x = dX;
  y = dY;
  h = dH;
  w = dW;
  interval = inter;
}
Physics phy;
void Character::enableMovement(Character *c, Arduboy *d, const unsigned char a[]) {
 Point dim; 
 Physics phy;
 
  d->drawBitmap(c->y, c->x, a, 8, 8, WHITE);
  dim.x = c->y;
  dim.y = c->x;
  if (d->pressed(UP_BUTTON) && (!phy.collide(dim, TOP_EDGE))) {
    c->curMillis = millis();
    if (c->curMillis - preMillis > c->interval) {
      c->x = c->x - 1;
      preMillis = c->curMillis;
    }
  } else if (d->pressed(DOWN_BUTTON) && (!phy.collide(dim, BOTTOM_EDGE))) {
    c->curMillis = millis();
    if (c->curMillis - preMillis > c->interval) {
      preMillis = c->curMillis;
      c->x = c->x + 1;
    }
  } else if (d->pressed(LEFT_BUTTON) && (!phy.collide(dim, LEFT_EDGE))) {
    c->curMillis = millis();
    if (c->curMillis - preMillis > c->interval) {
      preMillis = c->curMillis;
      c->y = c->y - 1;
    }
  } else if (d->pressed(RIGHT_BUTTON) && (!phy.collide(dim, RIGHT_EDGE))) {
    c->curMillis = millis();
    if (c->curMillis - preMillis > c->interval) {
      preMillis = c->curMillis;
      c->y = c->y + 1;
    }
  }
}

void Character::activateWeapons(Weapons *w, Arduboy *d) {
  Point dim; 

  dim.x = w->y;
  dim.y = w->x;

  if (w->shoot) {
    w->ammoCurMillis = millis();
    if (w->ammoCurMillis - w->ammoPreMillis > w->ammoInterval) {
      w->ammoPreMillis = w->ammoCurMillis;
      if (phy.collide(dim, TOP_EDGE)) {
        w->x = 0;
        w->shoot = 0;
      } else {
        w->x = w->x - 1;
        d->drawPixel(w->y, w->x, WHITE);
      }
    }
  }
  if (d->pressed(A_BUTTON)) {
    w->pressCurMillis = millis();
    if (w->pressCurMillis - w->pressPreMillis > w->pressInterval) {
      w->pressPreMillis = w->pressCurMillis;
      w->x = x + 4;
      w->y = y + 4;
      w->shoot = 1;
    }
  }
}
