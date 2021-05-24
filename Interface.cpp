#include "Interface.h"

Interface::Interface() : sf::RenderWindow(sf::VideoMode(1024, 500), "Interface")
{
	this->create(sf::VideoMode(1024, 500), "Interface");
	this->setVerticalSyncEnabled(true);
	this->setKeyRepeatEnabled(false);
}
Interface::~Interface()
{
	for (auto g : mot_) {
		delete(g);
	}
}
int Interface::size()
{
	return mot_.size();
}
void Interface::push_back(graphMot* mot)
{
	mot_.push_back(mot);
}
graphMot* Interface::front()
{
	return mot_.front();
}
void Interface::pop_front()
{
	mot_.pop_front();
}
void Interface::drawMot(graphMot& mot)
{
	int taille = mot.getmot().size();
	for (int i = 0; i < taille; i++) {
		sf::RenderWindow::draw(mot.getText(i));
	}
}

void Interface::drawlist()
{
	for (graphMot* g : mot_) {
		drawMot(*g);
		g->moveMot(g->getspeed());
	}
}

bool Interface::testEcran(graphMot& mot) //renvoie vrai si le mot est dans l'écran
{
	return mot.get_y() < this->getSize().y - 20;
}

bool Interface::testBarre(graphMot& mot, double difficulte) {
	return mot.get_y() < (this->getSize().y / difficulte);
}

string Interface::Keystroke(sf::Event& keyevent)
{
	if (keyevent.type == sf::Event::KeyPressed) {
		switch (keyevent.key.code) {
		case sf::Keyboard::A:
			return("A");
			break;
		case sf::Keyboard::B:
			return("B");
			break;
		case sf::Keyboard::C:
			return("C");
			break;
		case sf::Keyboard::D:
			return("D");
			break;
		case sf::Keyboard::E:
			return("E");
			break;
		case sf::Keyboard::F:
			return("F");
			break;
		case sf::Keyboard::G:
			return("G");
			break;
		case sf::Keyboard::H:
			return("H");
			break;
		case sf::Keyboard::I:
			return("I");
			break;
		case sf::Keyboard::J:
			return("J");
			break;
		case sf::Keyboard::K:
			return("K");
			break;
		case sf::Keyboard::L:
			return("L");
			break;
		case sf::Keyboard::M:
			return("M");
			break;
		case sf::Keyboard::N:
			return("N");
			break;
		case sf::Keyboard::O:
			return("O");
			break;
		case sf::Keyboard::P:
			return("P");
			break;
		case sf::Keyboard::Q:
			return("Q");
			break;
		case sf::Keyboard::R:
			return("R");
			break;
		case sf::Keyboard::S:
			return("S");
			break;
		case sf::Keyboard::T:
			return("T");
			break;
		case sf::Keyboard::U:
			return("U");
			break;
		case sf::Keyboard::V:
			return("V");
			break;
		case sf::Keyboard::W:
			return("W");
			break;
		case sf::Keyboard::X:
			return("X");
			break;
		case sf::Keyboard::Y:
			return("Y");
			break;
		case sf::Keyboard::Z:
			return("Z");
			break;
		case sf::Keyboard::Space:
			return("pause");
			break;
		}
	}
	return string();
}

bool Interface::pause()
{
	string lettre;
	graphMot motpause("pause", 5);
	motpause.set_x(512);
	motpause.moveMot(250);
	sf::Event event;
	while (this->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->close();

		lettre = this->Keystroke(event);
		if (lettre == "pause") return false;
	}
	this->drawMot(motpause);
	this->display();
	this->clear();
	return(true);
}

