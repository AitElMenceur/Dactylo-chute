#ifndef ObjetGrapphique

#include "Mot.h"

class ObjetGrapphique : public Mot {
public:
	void draw() ;
	void remove();
	void move();
};


#endif
/*
void setspeed(int speed) { speed_ = speed; }
int getposition() { return position_ };
*/