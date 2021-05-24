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
	 * @param speed
	*/
	graphMot(string mot,int size, int speed = 1);
	/**
	 * @brief Constructeur de la classe graphmot, permettant la conversion de mot � graphmot
	 * @param mot 
	 * @param speed
	*/
	graphMot(Mot& mot, int speed = 1);
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
	 * @brief Renvoie la vitesse de d�filement
	*/
	int getspeed();
	/**
	 * @brief Modifie la vitesse de d�filement
	 * @param speed 
	*/
	void setspeed(int speed);
	/**
	 * @brief Deplace un objet de y pixel en ordonn�es
	*/
	void moveMot(int y);
	/**
	 * @brief Renvoie la position en ordonn�es
	 * @return 
	*/
	int get_y();
	/**
	* @brief Set la position en abscisses
	* @param x
	*/
	void set_x(float x);
};

#endif