#ifndef INTERFACE
#define INTERFACE
// Moutaa Abd'Allah 

#include "graphmot.h"
#include <list>
#include <SFML/Window/Keyboard.hpp>

class Interface : public sf::RenderWindow {
protected:
	list<graphMot*> mot_;
public:
	/**
	 * @brief Constructeur de la classe Interface
	*/
	Interface();
	~Interface();
	/**
	* @brief Redefinitiond de methode de manipulation de la liste mot_
	* @return
	*/
	int size();
	/**
	 * @brief Redefinition demethode de manipulation de la liste mot_
	 * @return
	*/
	void push_back(graphMot* mot);
	/**
	 * @brief Redefinition de methode de manipulation de la liste mot_
	 * @return
	*/
	graphMot* front();
	/**
	 * @brief Redefinition de methode de manipulation de la liste mot_
	 * @return
	*/
	void pop_front();
	/**
	 * @brief Affiche un mot
	 * @param mot
	*/
	/**
	 * @brief Affiche un mot
	 * @param mot
	*/
	void drawMot(graphMot& mot);
	/**
	 * @brief affiche l'ensemble des mots
	*/
	void drawlist();
	/**
	 * @brief Test si un mot est toujours � l'ecran
	 * @param mot
	 * @return
	*/
	bool testEcran(graphMot& mot);
	/**
	 * @brief Test si un mot depasse un certain seuil, defini par le niveau de difficult�
	 * @param mot
	 * @param difficult�
	 * @return
	*/
	bool testBarre(graphMot& mot, double difficult�);
	/**
	 * @brief Renvoie la lettre frapp�e
	 * @param keyevent
	 * @return
	*/
	string Keystroke(sf::Event& keyevent);
	/**
	* @brief Affiche un �cran pause
	*/
	bool pause();
};

#endif