#include "collisionChecker.h"

// ---------------------------------------------------
collisionType checkBallCollisionWithPad(Ball ball, Pad pad){
// ---------------------------------------------------

  collisionType returnVal = ERR;

  if ( (ball._y+ball._r) >= pad._yTL){

    if ( ( (ball._x+ball._r) >= pad._xTL) && ( (ball._x+ball._r) <= (pad._xTL + PAD_EDGES_WIDTH))  ){
      returnVal = FROM_LEFT;
    }
    if ( ( (ball._x-ball._r) <= pad._xTL+pad._width) && ( (ball._x-ball._r) >= (pad._xTL + pad._width - PAD_EDGES_WIDTH))  ){
      returnVal = FROM_RIGHT;
    }
    if (  ((ball._x+ball._r)< (pad._xTL+ pad._width - PAD_EDGES_WIDTH)) && ((ball._x-ball._r)> (pad._xTL + PAD_EDGES_WIDTH))  ){
      returnVal = FROM_TOP;
    }  
  } else {
    returnVal = NONE;
  }

  return returnVal;

}



// ---------------------------------------------------
bool checkBallOut(Ball ball, Pad pad){
// ---------------------------------------------------  
  
  if ( (ball._y+ball._r) >= HEIGHT){ 

    if ( ( (ball._x+ball._r) < pad._xTL) || (ball._x-ball._r > (pad._xTL + pad._width))  ){
      return true; // ball out
    } else {
      return false; // ball not out -> collision with pad
    }

  }

}


// ---------------------------------------------------
collisionType checkBallCollisionWithBorders(Ball ball){
// ---------------------------------------------------

  return NONE;
}


// ---------------------------------------------------
collisionType checkBallCollisionWithBrick(Ball ball, Wall wall, int iRow, int jCol){
// ---------------------------------------------------

  return NONE;
}



