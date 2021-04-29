#ifndef ObjetGrapphique

#include "Mot.h"

class ObjetGrapphique {
public:
	virtual void draw() = 0;
	virtual void remove() = 0;
	virtual void move() = 0;
};


#endif
/*
void setspeed(int speed) { speed_ = speed; }
int getposition() { return position_ };
*/