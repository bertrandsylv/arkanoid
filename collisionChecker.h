#ifndef __COLLISION_CHECKER_H__
#define __COLLISION_CHECKER_H__

#include <Arduboy2.h>
#include "ball.h"
#include "pad.h"
#include "wall.h"
#include "bonus.h"

enum collisionType{NONE, FROM_LEFT, FROM_RIGHT, FROM_TOP, FROM_BOTTOM, BRICK, FROM_TOPLEFT, FROM_TOPRIGHT, FROM_BOTTOMLEFT, FROM_BOTTOMRIGHT};

collisionType checkBallCollisionWithPad(Ball ball, Pad pad);
bool checkBallOut(Ball ball, Pad pad);
collisionType checkBallCollisionWithBrick(Ball ball, Wall wall, int iRow, int jCol);
bool checkBonusCollisionWithPad(Pad pad, Bonus bonus);




#endif
