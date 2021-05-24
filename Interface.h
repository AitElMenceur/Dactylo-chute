#ifndef INTERFACE
#define INTERFACE


#include "graphmot.h"
#include <SFML/Window/Keyboard.hpp>

class Interface : public sf::RenderWindow {
public:
	/**
	 * @brief Constructeur de la classe Interface
	*/
	Interface();
	/**
	 * @brief Affiche un mot
	 * @param mot 
	*/
	void drawMot(graphMot &mot);
	/**
	 * @brief Test si un mot est toujours à l'ecran
	 * @param mot 
	 * @return 
	*/
	bool testEcran(graphMot &mot);
	/**
	 * @brief Test si un mot depasse un certain seuil, defini par le niveau de difficulté
	 * @param mot 
	 * @param difficulté 
	 * @return 
	*/
	bool testBarre(graphMot& mot, double difficulté);
	/**
	 * @brief Renvoie la lettre frappée
	 * @param keyevent 
	 * @return 
	*/
	string Keystroke(sf::Event & keyevent);
};

#endif