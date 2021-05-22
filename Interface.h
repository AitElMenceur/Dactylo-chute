#pragma once
#include "graphmot.h"
#include <SFML/Window/Keyboard.hpp>

class Interface : public sf::RenderWindow {
public:
	Interface();
	void drawMot(graphMot &mot);
	bool testEcran(graphMot &mot);
	bool testBarre(graphMot& mot, double difficulté);
	string Keystroke(sf::Event & keyevent);
};