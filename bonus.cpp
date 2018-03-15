#include "bonus.h"
#include "wall.h"
#include <Arduboy2.h>

// ---------------------------------------------------
Bonus::Bonus() {
// ---------------------------------------------------
  _x = WIDTH/2;
  _y = HEIGHT/2;
  _type = DPAD;
  _activated = false;
  _falling = false;
  _nbOfReboundsLefts = 4;
}

// ---------------------------------------------------
void Bonus::move() {
// ---------------------------------------------------
  _y ++;

    // (should be avoided by handling ball out)
  if (_y + 2 >= HEIGHT) {
    _y = HEIGHT - 2;
    _falling = false;
  }

}


// ---------------------------------------------------
void Bonus::draw(Arduboy2 arduboy) {
// ---------------------------------------------------
  if (_falling){
    arduboy.drawPixel(_x-1, _y-1);
    arduboy.drawPixel(_x-1, _y+1);
    arduboy.drawPixel(_x+1, _y-1);
    arduboy.drawPixel(_x+1, _y+1);
    arduboy.drawPixel(_x, _y-2);
    arduboy.drawPixel(_x, _y+2);
    arduboy.drawPixel(_x-2, _y);
    arduboy.drawPixel(_x+2, _y);
  }
}

// ---------------------------------------------------
void Bonus::initNew(int iRow, int jCol, bool rnd=true){
// ---------------------------------------------------
  int x = 5 + jCol*(int(BRICK_WIDTH)+3) + BRICK_WIDTH/2;
  int y = 2 + iRow*(int(BRICK_HEIGHT)+2) + BRICK_HEIGHT/2;
  
  _x = x;
  _y = y;


  _activated = false;
  _falling = true;
  _nbOfReboundsLefts = 4;

  int no = 0;
  if (rnd){
    no = int(random(NB_OF_BONUS));
  }
  
  switch(no){
    case 0:{
      _type = DPAD;
      break;
    }
    case 1:{
      _type = DBALL;
      break;
    }
    default:{
      _type = DPAD;
      break;
    }
  }

}
