#include "wall.h"

// ---------------------------------------------------
Wall::Wall(){
// ---------------------------------------------------
	_nbOfBricksLeft = WALL_WIDTH * WALL_HEIGHT;
	_nbOfBricks = WALL_WIDTH * WALL_HEIGHT;
	for (int iRow=0; iRow<WALL_HEIGHT; iRow++ ){
	  for (int jCol=0; jCol<WALL_WIDTH; jCol++){
		  if (iRow==WALL_HEIGHT-1){
		    _brickType[iRow][jCol] = 1;
		  } else {
        _brickType[iRow][jCol] = 2;
		  }
        _brickType[3][6] = 0;
     
	  }  
  }
}

// ---------------------------------------------------
void Wall::draw(Arduboy2 arduboy){
// ---------------------------------------------------
  int xTLBrick = 0;
  int yTLBrick = 0;
  
  for (int iRow=0; iRow<WALL_HEIGHT; iRow++ ){
    for (int jCol=0; jCol<WALL_WIDTH; jCol++){

      // for activated bricks only
      if (_brickType[iRow][jCol]>0){ 
         
        // compute brick Top Left coordinates
        xTLBrick = 5 + jCol*(int(BRICK_WIDTH)+3);
        yTLBrick = 2 + iRow*(int(BRICK_HEIGHT)+2);



        // draw brick
        switch(_brickType[iRow][jCol]){

          /*
          case 1:{ // empty rectangle with round corners
            arduboy.drawRect(xTLBrick, yTLBrick, BRICK_WIDTH, BRICK_HEIGHT); 
            arduboy.drawPixel(xTLBrick, yTLBrick, BLACK);
            arduboy.drawPixel(xTLBrick+BRICK_WIDTH-1, yTLBrick, BLACK);
            arduboy.drawPixel(xTLBrick, yTLBrick+BRICK_HEIGHT-1, BLACK);
            arduboy.drawPixel(xTLBrick+BRICK_WIDTH-1, yTLBrick+BRICK_HEIGHT-1, BLACK);
            break;
          }
          */

          case 1:{ // empty rectangle
            arduboy.drawRect(xTLBrick, yTLBrick, BRICK_WIDTH, BRICK_HEIGHT); 
            break;
          }
          
          case 2:{ // filled rectangle
            arduboy.fillRect(xTLBrick, yTLBrick, BRICK_WIDTH, BRICK_HEIGHT, WHITE);
            arduboy.drawLine(xTLBrick+1, yTLBrick+1, xTLBrick+3, yTLBrick+1, BLACK);
            arduboy.drawPixel(xTLBrick+1, yTLBrick+2, BLACK);
            break;
          }

          case 3:{ // letter
            arduboy.drawRect(xTLBrick, yTLBrick, BRICK_WIDTH, BRICK_HEIGHT); // borders
            arduboy.drawPixel(xTLBrick+1, yTLBrick+2, WHITE);
            arduboy.drawPixel(xTLBrick+BRICK_WIDTH-2, yTLBrick+2, WHITE);
            arduboy.drawLine(xTLBrick+2, yTLBrick+1, xTLBrick+BRICK_WIDTH-3, yTLBrick+1);
            break;
          }

          case 4:{ // eyes
            arduboy.fillRect(xTLBrick, yTLBrick, BRICK_WIDTH, BRICK_HEIGHT); // filled
            arduboy.drawLine(xTLBrick+2, yTLBrick+1, xTLBrick+2, yTLBrick+2, BLACK);
            arduboy.drawLine(xTLBrick+5, yTLBrick+1, xTLBrick+5, yTLBrick+2, BLACK);
            break;
          }

          case 5:{ // stroked filled rectangle
            arduboy.fillRect(xTLBrick, yTLBrick, BRICK_WIDTH, BRICK_HEIGHT, WHITE);
            arduboy.drawLine(xTLBrick+1, yTLBrick+BRICK_HEIGHT-1, xTLBrick+4, yTLBrick, BLACK);
            //arduboy.drawLine(xTLBrick+2, yTLBrick+BRICK_HEIGHT-1, xTLBrick+5, yTLBrick, BLACK);
            arduboy.drawLine(xTLBrick+3, yTLBrick+BRICK_HEIGHT-1, xTLBrick+6, yTLBrick, BLACK);
            break;
          }

          case 6:{ // filled rectangle with white hat
            arduboy.fillRect(xTLBrick, yTLBrick, BRICK_WIDTH, BRICK_HEIGHT, WHITE);
            arduboy.drawLine(xTLBrick+2, yTLBrick+1, xTLBrick+5, yTLBrick+1, BLACK);
            arduboy.drawLine(xTLBrick+1, yTLBrick+2, xTLBrick+6, yTLBrick+2, BLACK);
            arduboy.drawPixel(xTLBrick, yTLBrick, BLACK);
            arduboy.drawPixel(xTLBrick+BRICK_WIDTH-1, yTLBrick, BLACK);
            break;
          }


          case 7:{ // flash in fillled rectangle
            arduboy.fillRect(xTLBrick, yTLBrick, BRICK_WIDTH, BRICK_HEIGHT, WHITE);
            arduboy.drawLine(xTLBrick+1, yTLBrick+BRICK_HEIGHT-1-1, xTLBrick+4, yTLBrick+1, BLACK);
            arduboy.drawLine(xTLBrick+2, yTLBrick+BRICK_HEIGHT-1-1, xTLBrick+5, yTLBrick+1, BLACK);
            arduboy.drawLine(xTLBrick+3, yTLBrick+BRICK_HEIGHT-1-1, xTLBrick+6, yTLBrick+1, BLACK);
            break;
          }

          case 8:{ // grey
            arduboy.drawRect(xTLBrick, yTLBrick, BRICK_WIDTH, BRICK_HEIGHT); // borders
            arduboy.drawPixel(xTLBrick+1, yTLBrick+1);
            arduboy.drawPixel(xTLBrick+3, yTLBrick+1);
            arduboy.drawPixel(xTLBrick+5, yTLBrick+1);
            arduboy.drawPixel(xTLBrick+2, yTLBrick+2);
            arduboy.drawPixel(xTLBrick+4, yTLBrick+2);
            arduboy.drawPixel(xTLBrick+6, yTLBrick+2);
            break;
          }

          case 9:{
            arduboy.fillRect(xTLBrick, yTLBrick, BRICK_WIDTH, BRICK_HEIGHT, WHITE);
            arduboy.drawLine(xTLBrick+1, yTLBrick+1, xTLBrick+3, yTLBrick+1, BLACK);
            arduboy.drawPixel(xTLBrick+1, yTLBrick+2, BLACK);
            arduboy.drawLine(xTLBrick+3, yTLBrick+BRICK_HEIGHT-1, xTLBrick+6, yTLBrick, BLACK);
            arduboy.drawLine(xTLBrick+4, yTLBrick+BRICK_HEIGHT-1, xTLBrick+7, yTLBrick, BLACK);
            break;
          }

          default:{ // empty rectangle
            arduboy.drawRect(xTLBrick, yTLBrick, BRICK_WIDTH, BRICK_HEIGHT);
            break;    
          }
          
        }

       
      }
    }  
  }
  
}


// ---------------------------------------------------
void Wall::initToLevel(const char* level){
// ---------------------------------------------------
  int iLevel = 0;
  _nbOfBricks = 0;
  
  for (int iRow=0; iRow<WALL_HEIGHT; iRow++ ){
    for (int jCol=0; jCol<WALL_WIDTH; jCol++){
        _brickType[iRow][jCol] = int(level[iLevel] - '0');
        if (int(level[iLevel]- '0')>0) {
          _nbOfBricks++;
        }
        iLevel++;
    }  
  }
  _nbOfBricksLeft = _nbOfBricks;
}


