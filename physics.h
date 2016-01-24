#ifndef PHYSICS_H
#define PHYSICS_H

#include <Arduino.h>

// left edge is 1 pixel left offscreen
#define LEFT_EDGE (Rect){ 0, 0, 2, 64}
// right edit is 1 pixel right offscreen
#define RIGHT_EDGE (Rect){ 120, 0, 2, 64}
// top edge is 1 pixel offscreen below top
#define TOP_EDGE (Rect) {0, 0, 128, 2}
// bottom edge is 1 pixel offscreen below bottom
#define BOTTOM_EDGE (Rect){ 0, 56, 128, 2}

struct Rect
{
public:
    uint8_t x;
    uint8_t y;
    uint8_t width;
    uint8_t height;
};

struct Point
{
public:
    int8_t x;
    int8_t y;
};

class Physics
{
  public:
    bool static collide(Point point, Rect rect);
    bool static collide(Rect rect, Rect rect2);
    //Point bgStars[16] = {{0,-6} , {8,-47} , {16,0} , {32,0} , {40,0} , {48,0} , {56,0} , {64,0} , {72,0} , {80,0} , {88,0} , {96,0} , {104,0} , {112,0} , {120,0} , {128,0}};

};
#endif
