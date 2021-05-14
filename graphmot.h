#pragma once
#include "Mot.h"
#include <SFML/Graphics.hpp>
#include <vector>

class graphMot : public Mot {
	int position_;
	int speed_;
	sf::Font font_;
	vector<sf::Text> texte_;

public:
	graphMot(string mot, int size);
	~graphMot();
	sf::Text getText(int position);
	void changeColor(bool test, int position);
	void setspeed(int speed);
	int getposition();
};
