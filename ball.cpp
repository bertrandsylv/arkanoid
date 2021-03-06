#include "ball.h"
#include <Arduboy2.h>

// ---------------------------------------------------
Ball::Ball() {
// ---------------------------------------------------
  _x = WIDTH/2;
  _y = HEIGHT - 10;
  _vx = 1;
  _vy = -2;
  _r = 2;
  _type = NORMAL_BALL;
}

// ---------------------------------------------------
void Ball::move() {
// ---------------------------------------------------
  _x += _vx;
  _y += _vy;

  // collision with borders
  
  if (_x + _r >= WIDTH) {
    _x = WIDTH - _r;
    _vx = -1 * _vx;
  }

  if (_x <= _r) {
    _x = _r;
    _vx = -1 * _vx;
  }

  // (should be avoided by handling ball out)
  if (_y + _r >= HEIGHT) {
    _y = HEIGHT - _r;
    _vy = -1 * _vy;
  }

  if (_y <= _r) {
    _y = _r;
    _vy = -1 * _vy;
  }
}


// ---------------------------------------------------
void Ball::draw(Arduboy2 arduboy) {
// ---------------------------------------------------
  arduboy.fillCircle(_x, _y, _r);
  if (_type == NORMAL_BALL){
    arduboy.drawPixel(_x-1, _y-1, BLACK);
    arduboy.drawPixel(_x, _y-1, BLACK);
    arduboy.drawPixel(_x-1, _y, BLACK);
  } else {
    arduboy.drawPixel(_x-2, _y-2, BLACK);
    arduboy.drawPixel(_x-1, _y-2, BLACK);
    arduboy.drawPixel(_x, _y-2, BLACK);
    arduboy.drawPixel(_x-2, _y, BLACK);
    arduboy.drawPixel(_x-2, _y-1, BLACK);
  }
  
}

// ---------------------------------------------------
void Ball::reset(){
// ---------------------------------------------------
  _x = WIDTH/2;
  _y = HEIGHT - 10;
  _vx = 1;
  _vy = -2;
  _r = 2;
  _type = NORMAL_BALL;
}
