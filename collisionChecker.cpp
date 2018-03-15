#include "collisionChecker.h"

// ---------------------------------------------------
collisionType checkBallCollisionWithPad(Ball ball, Pad pad){
// ---------------------------------------------------

  collisionType returnVal = NONE;

  if ( (ball._y+ball._r) >= pad._yTL){

    // left edge of pad
    if ( ( (ball._x+ball._r) >= pad._xTL) && ( (ball._x+ball._r) <= (pad._xTL + PAD_EDGES_WIDTH))  ){
      returnVal = FROM_LEFT;
    }
    
    // right edge of pad
    if ( ( (ball._x-ball._r) <= pad._xTL+pad._width) && ( (ball._x-ball._r) >= (pad._xTL + pad._width - PAD_EDGES_WIDTH))  ){
      returnVal = FROM_RIGHT;
    }
    
    // center of pad
    if (  ((ball._x+ball._r)< (pad._xTL+ pad._width - PAD_EDGES_WIDTH)) && ((ball._x-ball._r)> (pad._xTL + PAD_EDGES_WIDTH))  ){
      returnVal = FROM_TOP;
    }  
    
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

  } else {
      return false;
  }

}



// ---------------------------------------------------
collisionType checkBallCollisionWithBrick(Ball ball, Wall wall, int iRow, int jCol){
// ---------------------------------------------------

  collisionType returnVal = NONE;

  // pixel coordinates from index of brick
  int xTLBrick = 5 + jCol*(int(BRICK_WIDTH)+3);
  int yTLBrick = 2 + iRow*(int(BRICK_HEIGHT)+2);

  // bounds of collision surface
  bool down = ( (ball._y-ball._r)<=(yTLBrick+BRICK_HEIGHT-1) ) ;
  bool up = ( (ball._y+ball._r)>=(yTLBrick) );
  bool left = ( (ball._x+ball._r)>=xTLBrick );
  bool right = ( (ball._x-ball._r)<=(xTLBrick+BRICK_WIDTH-1) );


  // lines for definition of angular sectors (Top/Bottome - Left/Right) (brick diagonals)
  bool BL_TR = true;  // TO DO  evaluate line equation from ball coordinates do decide angular sector
  bool TL_BR = true;

  // if ball inside collision surface
  if (down && up && left && right){
    returnVal = BRICK;

    // TO DO : perform tests to decide angular sector and assign returnVal
    
  }


  return returnVal;


}



