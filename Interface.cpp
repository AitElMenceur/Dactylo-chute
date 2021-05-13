#include "Interface.h"

Interface::Interface()
{
	sf::RenderWindow window_(sf::VideoMode(1024, 500), "Interface");
	window_.setVerticalSyncEnabled(true);
}
void Interface::draw(graphMot& mot)
{
	int taille = mot.getmot().size();
	for (int i = 0; i < taille; i++) {
		sf::Text lettre = mot.getText(i);
		window_.draw(lettre);
	}
}

void Interface::display()
{
	window_.display();
}

void Interface::remove()
{
	window_.clear();
}

void Interface::move(graphMot mot)
{
	int taille = mot.getmot().size();
	for (int i = 0; i < taille; i++) {
		mot.getText(i).move(0.f, 1.f);
	}
}