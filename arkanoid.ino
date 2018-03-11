//Sylvain BERTRAND

#include <Arduboy2.h>
#include <Tinyfont.h>
#include "ball.h"
#include "pad.h"
#include "wall.h"
#include "levels.h"
#include "collisionChecker.h"


Arduboy2 arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());
Ball ball;
Pad pad;
Wall wall;
int levelNo = 0;

// --------------------------------------------
void setup() {
// --------------------------------------------
  arduboy.begin();
  arduboy.setFrameRate(30);
  arduboy.clear();
  //arduboy.pollButtons();
  wall.initToLevel(levels[levelNo]);
}


// --------------------------------------------
void loop() {
// --------------------------------------------
  
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  // Reset buttons
  arduboy.pollButtons();

  // Clear
  arduboy.clear();


  // Button handlig
  // ------------------------------------------------------------

  // move pad to right
  if (arduboy.pressed(RIGHT_BUTTON)) {
    pad._xTL += 2;
    if (pad._xTL + pad._width > WIDTH) {pad._xTL = WIDTH - pad._width; }
  }

  // move pad to left
  if (arduboy.pressed(LEFT_BUTTON)) {
    pad._xTL -= 2;
    if (pad._xTL<0) {pad._xTL = 0;}
  }

  // cheat mode: enlarge pad
  if (arduboy.justPressed(B_BUTTON) && (pad._type==NORMAL)){
    pad._width=2*PAD_NORMAL_WIDTH;
    pad._xTL -= int(PAD_NORMAL_WIDTH/2);
    if (pad._xTL<0) {pad._xTL = 0;}
    if (pad._xTL + pad._width > WIDTH) {pad._xTL = WIDTH - pad._width; }
    pad._type = DOUBLE;
  }
  
  if (arduboy.justPressed(A_BUTTON) && (pad._type==DOUBLE)){
    pad._width=PAD_NORMAL_WIDTH;
    pad._xTL += int(PAD_NORMAL_WIDTH/2);
    pad._type = NORMAL;
  }

  // change level
  if (arduboy.justPressed(UP_BUTTON)){
    levelNo++;
    if (levelNo>=NB_OF_LEVELS) {
      levelNo = 0; 
    }
    wall.initToLevel(levels[levelNo]);    
  }

  // check for ball out
  // ------------------------------------------------------------
  if (checkBallOut(ball, pad)){
    tinyfont.setCursor(10,2);
    tinyfont.print("OUT");
    ball._vy = 0;
    delay(1000);
    ball.reset();
    pad.reset();
  } else {
    tinyfont.setCursor(115,2);
    tinyfont.print("IN ");
  }

  // check for collision of ball with pad
  // ------------------------------------------------------------
  collisionType col = checkBallCollisionWithPad(ball, pad);
  tinyfont.setCursor(70,2);
  tinyfont.print("PAD:");
  switch(col){
    case ERR:{
      tinyfont.print("ERR");
      break;
    }
    case FROM_LEFT:{
      tinyfont.print("L");
      ball._vy = -1*abs(ball._vy); // abs to prevent from rebounds inside pad
      ball._vx--;
      break;
    }
    case FROM_RIGHT:{
      tinyfont.print("R");
      ball._vy = -1*abs(ball._vy);
      ball._vx++;
      break;
    }
    case FROM_TOP:{
      tinyfont.print("T");
      ball._vy = -1*abs(ball._vy);
      break;
    }

    
  }


  // check for collision with brick
  // ------------------------------------------------------------
  for (int iRow=0; iRow<WALL_HEIGHT; iRow++ ){
    for (int jCol=0; jCol<WALL_WIDTH; jCol++){

      // for activated bricks only
      if (wall._brickType[iRow][jCol]>0){ 
          
          if (checkBallCollisionWithBrick(ball, wall, iRow, jCol)){
            wall._brickType[iRow][jCol]=0;
            wall._nbOfBricksLeft--;            
          }
          
      }
    }
  }


  // draw borders of screen
  // ------------------------------------------------------------
  arduboy.drawLine(0,0,WIDTH-1,0,1);
  arduboy.drawLine(0,0,0,HEIGHT-1,1);
  arduboy.drawLine(WIDTH-1,0,WIDTH-1,HEIGHT-1,1);

  // draw other objects
  // ------------------------------------------------------------
  ball.draw(arduboy);
  pad.draw(arduboy);
  wall.draw(arduboy);


  // display
  // ------------------------------------------------------------
  arduboy.display();



  // pause mode
  // ------------------------------------------------------------
  if (arduboy.justPressed(DOWN_BUTTON)){
    // print pause message
    
    /*
    arduboy.clear();
    tinyfont.setCursor(int(WIDTH/2)- 20, int(HEIGHT/2));
    tinyfont.print("~ PAUSE ~");
    arduboy.display();
    */

    // *** for debug ***
    tinyfont.setCursor(2, 2);
    tinyfont.print("PAUSE");
    arduboy.display();
    // ****
    
    // wait for down button to be pressed again
    while(1){
      arduboy.pollButtons();
      if (arduboy.justPressed(DOWN_BUTTON)){break;}
    }
  }


  // update ball position for next iteration
  // ------------------------------------------------------------
  ball.move();



}
