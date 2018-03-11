#ifndef __COLLISION_CHECKER_H__
#define __COLLISION_CHECKER_H__

#include <Arduboy2.h>
#include "ball.h"
#include "pad.h"
#include "wall.h"

enum collisionType{NONE, FROM_LEFT, FROM_RIGHT, FROM_TOP, FROM_BOTTOM, ERR};

collisionType checkBallCollisionWithPad(Ball ball, Pad pad);
collisionType checkBallCollisionWithBorders(Ball ball);
bool checkBallOut(Ball ball, Pad pad);
collisionType checkBallCollisionWithBrick(Ball ball, Wall wall, int iRow, int jCol);

#endif
