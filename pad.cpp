#include "pad.h"

// ---------------------------------------------------
Pad::Pad(){
// ---------------------------------------------------
  _type ==0;
  _width=PAD_NORMAL_WIDTH;
  _height = 4;
  _xTL = int(WIDTH- _width)/2;
  _yTL = HEIGHT - _height;
}
  
  
// ---------------------------------------------------
void Pad::draw(Arduboy2 arduboy){
// ---------------------------------------------------
  arduboy.drawRoundRect(_xTL, _yTL, _width, _height, 2); 
  arduboy.drawLine(_xTL+PAD_EDGES_WIDTH, _yTL, _xTL+PAD_EDGES_WIDTH, _yTL+_height);
  arduboy.drawLine(_xTL+_width-PAD_EDGES_WIDTH-1, _yTL, _xTL+_width-PAD_EDGES_WIDTH-1, _yTL+_height); 
}
