#ifndef __PAD_H__
#define __PAD_H__

#include <Arduboy2.h>

#define PAD_EDGES_WIDTH 10
//4
#define PAD_NORMAL_WIDTH 40
//20


enum padType{NORMAL, DOUBLE};



class Pad {
	
	public:
		int _xTL; //Top Left coordinate of rectangle
		int _yTL; //Top Left coordinate of rectangle
		int _width;
    int _height;
		int _type;

    Pad();
		void draw(Arduboy2 arduboy);
    void reset();
};


#endif
