#ifndef __BONUS_H__
#define __BONUS_H__

#include <Arduboy2.h>

#define NB_OF_BONUS 2
enum bonusType{DPAD, DBALL};

class Bonus {
  public:
    int16_t _x;
    int16_t _y;
    bonusType _type;
	  bool _activated;
	  bool _falling;
	  unsigned int _nbOfReboundsLefts;

    Bonus();
    void move();
    void draw(Arduboy2 arduboy);
    void initNew(int iRow, int jCol, bool rnd=true);
	
};


#endif
