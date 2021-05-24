#ifndef GRAPHMOT
#define GRAPHMOT
// Moutta Abd'Allah 

#include "Mot.h"
#include <SFML/Graphics.hpp>
#include <vector>

class graphMot : public Mot {
	int speed_;
	sf::Font font_;
	vector<sf::Text> texte_;

public:
	/**
	 * @brief Constructeur de la classe graphmot
	 * @param mot 
	 * @param size 
	*/
	graphMot(string mot, int size);
	/**
	 * @brief Constructeur de la classe graphmot, permettant la conversion de mot à graphmot
	 * @param mot 
	*/
	graphMot(Mot& mot);
	~graphMot();
	/**
	 * @brief Renvoie une Lettre sfml
	 * @param position 
	 * @return 
	*/
	sf::Text getText(int position);
	/**
	 * @brief Change la couleur d'une lettre
	 * @param test 
	 * @param position 
	*/
	void changeColor(bool test, int position);
	/**
	 * @brief Modifie la vitesse de défilement
	 * @param speed 
	*/
	void setspeed(int speed);
	/**
	 * @brief Deplace un objet
	*/
	void moveMot();
	/**
	 * @brief Renvoie la position en abscisse
	 * @return 
	*/
	int get_y();
};

#endif
