#ifndef MOT
#define MOT
#include <string>
#include <iostream>
// Ait Elmenceur Ilyès
using namespace std;

class Mot {
	string mot_;
	int size_;
public:
	/**
	 * @brief Constructeur de la classe Mot
	 * @param mot 
	 * @param size 
	*/
	Mot(string mot, int size);
	/**
	 * @brief Test si une lettre designée par une position correpond au paramettre lettre
	 * @param position 
	 * @param lettre 
	 * @return 
	*/
	bool TestLettre(int position, string lettre);
	/**
	 * @brief Test de la validité d'une proposition
	 * @param mot 
	 * @return 
	*/
	bool TestMot(string mot);
	/**
	 * @brief Renvoie la taille d'un mot
	 * @return 
	*/
	int getsize();
	/**
	 * @brief Renvoie le mot
	 * @return 
	*/
	string getmot();
};
#endif // !Mot

