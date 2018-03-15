//Sylvain BERTRAND

#include <Arduboy2.h>
#include <Tinyfont.h>
#include "ball.h"
#include "pad.h"
#include "wall.h"
#include "levels.h"
#include "bonus.h"
#include "collisionChecker.h"

// flag to display debug data on screen
#define DEBUG_DISP false


Arduboy2 arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());
Ball ball;
Pad pad;
Wall wall;
Bonus bonus;
int levelNo = 0;


// ************ fonctions haut niveau jeu ou utilitaires à déplacer dans un fichier gameUtils.cpp  **********************

// --------------------------------------------
void waitForAnyKeyPressed(Arduboy2 arduboy) {
// --------------------------------------------
  while(1){
    arduboy.pollButtons();
    if (arduboy.justPressed(RIGHT_BUTTON) || arduboy.justPressed(LEFT_BUTTON) || arduboy.justPressed(UP_BUTTON) || arduboy.justPressed(DOWN_BUTTON) ||  arduboy.justPressed(A_BUTTON) || arduboy.justPressed(B_BUTTON)){
      break;
    }
  }

}


// ***********************************************************************************************************************


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

/*
  // cheat mode: enlarge ball
  if (arduboy.justPressed(B_BUTTON)){
    if (ball._type==NORMAL_BALL){
      ball._r = 2*ball._r;
      ball._type = DOUBLE_BALL;
    } else {
      ball._r = int(ball._r/2);
      ball._type = NORMAL_BALL;
    }
  }
*/

  if (arduboy.justPressed(B_BUTTON)){
    bonus.initNew(5, 5);
  }
  
  // cheat mode: enlarge pad
  if (arduboy.justPressed(A_BUTTON)){
    if (pad._type==DOUBLE){
      pad._width=PAD_NORMAL_WIDTH;
      pad._xTL += int(PAD_NORMAL_WIDTH/2);
      pad._type = NORMAL;
    } else {
      pad._width=2*PAD_NORMAL_WIDTH;
      pad._xTL -= int(PAD_NORMAL_WIDTH/2);
      if (pad._xTL<0) {pad._xTL = 0;}
      if (pad._xTL + pad._width > WIDTH) {pad._xTL = WIDTH - pad._width; }
      pad._type = DOUBLE;
    }
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
    if (DEBUG_DISP){
      tinyfont.setCursor(10,2);
      tinyfont.print("OUT");
    }
    ball._vy = 0;
    delay(1000);
    ball.reset();
    pad.reset();
    waitForAnyKeyPressed(arduboy);
  } else {
    if (DEBUG_DISP){
      tinyfont.setCursor(115,2);
      tinyfont.print("IN ");
    }
  }

  // check for collision of ball with pad
  // ------------------------------------------------------------
  collisionType colPad = checkBallCollisionWithPad(ball, pad);
  if (DEBUG_DISP){
    tinyfont.setCursor(70,2);
    tinyfont.print("PAD:");
  }
  switch(colPad){
    /*case ERR:{
      if (DEBUG_DISP){tinyfont.print("ERR");}
      break;
    }*/
    case FROM_LEFT:{
      if (DEBUG_DISP){tinyfont.print("L");}
      ball._vy = -1*abs(ball._vy); // abs to prevent from rebounds inside pad
      ball._vx--;
      break;
    }
    case FROM_RIGHT:{
      if (DEBUG_DISP){tinyfont.print("R");}
      ball._vy = -1*abs(ball._vy);
      ball._vx++;
      break;
    }
    case FROM_TOP:{
      if (DEBUG_DISP){tinyfont.print("T");}
      ball._vy = -1*abs(ball._vy);
      break;
    }

    
  }


  // check for collision with brick
  // ------------------------------------------------------------
  if (DEBUG_DISP){
    tinyfont.setCursor(50,2);
    tinyfont.print("BR:");
    tinyfont.print(wall._nbOfBricksLeft);
  }
  
  for (int iRow=0; iRow<WALL_HEIGHT; iRow++ ){
    for (int jCol=0; jCol<WALL_WIDTH; jCol++){

      // for activated bricks only
      if (wall._brickType[iRow][jCol]>0){ 

          collisionType colBrick = checkBallCollisionWithBrick(ball, wall, iRow, jCol);
          
          //if (checkBallCollisionWithBrick(ball, wall, iRow, jCol)){
          if (colBrick!=NONE){
            
            // remove brick
            wall._brickType[iRow][jCol]=0;
            wall._nbOfBricksLeft--;   

            // level finished 
            if (wall._nbOfBricksLeft==0){
              delay(2000);
              levelNo++;
              if (levelNo>=NB_OF_LEVELS) {
                levelNo = 0;
              }
              wall.initToLevel(levels[levelNo]); 
              pad.reset();
              ball.reset();
              waitForAnyKeyPressed(arduboy);
            } /*else {
              // level not finished: rebound of ball
              if ((colB == FROM_TOP)||(colB == FROM_BOTTOM)){ ball._vy = -1*abs(ball._vy); }
              if ((colB == FROM_LEFT)||(colB == FROM_RIGHT)){ ball._vx = -1*abs(ball._vx); }
            }*/
           
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
  if (bonus._falling){
    bonus.draw(arduboy);
  }


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
