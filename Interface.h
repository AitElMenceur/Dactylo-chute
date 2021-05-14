#pragma once
#include "graphmot.h"

class Interface {
	sf::RenderWindow window_;
public:
	Interface();
	void draw(graphMot &mot);
	void display();
	void remove();
	void move(graphMot mot);
};