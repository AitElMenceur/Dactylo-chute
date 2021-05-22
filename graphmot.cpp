#include "graphMot.h"

graphMot::graphMot(string mot, int size)
	: Mot(mot, size)
{
	speed_ = 0;
	font_.loadFromFile("OpenSans-Bold.ttf");
	if (!font_.loadFromFile("OpenSans-Bold.ttf"))
	{
		std::cout << "ERROR: Cannot load font" << std::endl;
	}
	int x = rand() % 1024; // largeur de l'interface 1024 pixels
	for (int i = 0; i < size; i++) {
		texte_.push_back(sf::Text());
		texte_.back().setString(mot.substr(i, 1));
		texte_.back().setFont(font_);
		texte_.back().setCharacterSize(20);
		texte_.back().setFillColor(sf::Color::White);
		texte_.back().setOutlineColor(sf::Color::White);
		texte_.back().setPosition(0.f + 10 * i + x, 0.f);
	}
}

graphMot::graphMot(Mot& mot) : Mot(mot) {
	int size = mot.getsize();
	speed_ = 0;
	font_.loadFromFile("OpenSans-Bold.ttf");
	if (!font_.loadFromFile("OpenSans-Bold.ttf"))
	{
		std::cout << "ERROR: Cannot load font" << std::endl;
	}
	int x = rand() % 1024 - size; // largeur de l'interface 1024 pixels
	for (int i = 0; i < size; i++) {
		texte_.push_back(sf::Text());
		texte_.back().setString(mot.getmot().substr(i, 1));
		texte_.back().setFont(font_);
		texte_.back().setCharacterSize(20);
		texte_.back().setFillColor(sf::Color::White);
		texte_.back().setOutlineColor(sf::Color::White);
		texte_.back().setPosition(0.f + 10 * i + x, 0.f);
	}
}

void graphMot::changeColor(bool test, int position) {
	if (test) {
		texte_[position].setFillColor(sf::Color::Green);
		texte_[position].setOutlineColor(sf::Color::Green);
	}
	else {
		texte_[position].setFillColor(sf::Color::Red);
		texte_[position].setOutlineColor(sf::Color::Red);
	}
}

graphMot::~graphMot() {
}

sf::Text graphMot::getText(int position)
{
	return texte_[position];
}

void graphMot::setspeed(int speed)
{
	speed_ = speed;
}

void graphMot::moveMot()
{
	for (int i = 0; i < getsize(); i++) {
		texte_[i].move(0.f, 1.f);
	}
}

int graphMot::get_y()
{
	return(texte_[0].getPosition().y);
}
