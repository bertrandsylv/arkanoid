#ifndef __WALL_H__
#define __WALL_H__

#include <Arduboy2.h>

#define WALL_WIDTH 11
#define WALL_HEIGHT 6
#define BRICK_WIDTH 8
#define BRICK_HEIGHT 4

class Wall {
	
	public:
		int _nbOfBricksLeft;
		int _nbOfBricks;
		int _brickType[WALL_HEIGHT][WALL_WIDTH]; // 0: no brick, 1:empty brick, etc..
	
		Wall();
		void draw(Arduboy2 arduboy);
		void initToLevel(const char* level);
};


#endif
