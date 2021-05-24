#ifndef MOT
#define MOT
#include <string>
#include <iostream>
// Ait Elmenceur Ily�s
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
	 * @brief Test si une lettre design�e par une position correpond au paramettre lettre
	 * @param position 
	 * @param lettre 
	 * @return 
	*/
	bool TestLettre(int position, string lettre);
	/**
	 * @brief Test de la validit� d'une proposition
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

