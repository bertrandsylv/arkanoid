#ifndef __BALL_H__
#define __BALL_H__

#include <Arduboy2.h>

enum ballType{NORMAL_BALL, DOUBLE_BALL};

class Ball {
  public:
    int16_t _x;
    int16_t _y;
    int16_t _vx;
    int16_t _vy;
    int16_t _r;
    ballType _type;

    Ball();
    void move();
    void draw(Arduboy2 arduboy);
    void reset();
};


#endif
