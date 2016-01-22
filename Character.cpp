#include "Character.h"
#include <stdio.h>

//Character::Character(){
//}
Character::Character(char cc, uint8_t s, bool d, uint8_t inter, Rect r) {
  characterClass = cc;
  strength = s;
  destructable = d;
  x = r.x;
  y = r.y;
  h = r.height;
  w = r.width;
  interval = inter;
}
//Physics phy;

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

void Character::activateWeapons(Weapons *w, Arduboy *d, const unsigned char a[]) {
  
  Point dim{w->y,w->x}; 

  if (w->shootBullet) {
    d->drawPixel(w->y, w->x, WHITE);
    w->ammoCurMillis = millis();
    if (w->ammoCurMillis - w->ammoPreMillis > w->ammoInterval) {
      w->ammoPreMillis = w->ammoCurMillis;
      if (phy.collide(dim, TOP_EDGE)) {
        w->x = 0;
        w->shootBullet = 0;
        w->shooting = 0;
      } else {
        w->x = w->x - 1;
        w->shooting = 1;
       // d->drawPixel(w->y, w->x, WHITE);
      }
    }
  }
  if (w->shootBomb) {
    d->drawBitmap(w->y, w->x, a, 8, 8, WHITE);
    w->ammoCurMillis = millis();
    if (w->ammoCurMillis - w->ammoPreMillis > w->ammoInterval) {
      w->ammoPreMillis = w->ammoCurMillis;
      if (phy.collide(dim, TOP_EDGE)) {
        w->x = 0;
        w->shootBomb = 0;
        w->shooting = 0;
      } else {
        w->x = w->x - 1;
        w->shooting = 1;
      }
    }
  }
  
  if (d->pressed(A_BUTTON) && !w->shooting) {
    w->pressCurMillis = millis();
    if (w->pressCurMillis - w->pressPreMillis > w->pressInterval) {
      w->pressPreMillis = w->pressCurMillis;
      w->x = x + 4;
      w->y = y + 4;
      w->shootBullet = 1;
    }
  }
    if (d->pressed(B_BUTTON) && !w->shooting) {
    w->pressCurMillis = millis();
    if (w->pressCurMillis - w->pressPreMillis > w->pressInterval) {
      w->pressPreMillis = w->pressCurMillis;
      w->x = x;
      w->y = y;
      w->shootBomb = 1;
    }
  }
}

void Character::addAi(Weapons *w, Character *c, Arduboy *d, const unsigned char a[], bool *boolGS) {

Rect mainC = {c->y, c->x, c->h, c->w};
Rect bel = {w->y, w->x, 1, 1};
Rect ai = {y,x,8,8};

  if(lifeState){
    d->drawBitmap(y, x, a, 8, 8, WHITE);
        curM = millis();
    if (curM - preM > interval) {
      preM = curM;
      if(x < 2 || x > 55){
        moveState = !moveState;
      }
      if(moveState){
        x = x + 1;
      }else{
        x = x - 1;
      }
    }
  }
  
  if(phy.collide(ai, bel)){
    lifeState = 0;
  }
    if(phy.collide(ai, mainC)){
    *boolGS = 0;
  }
}


