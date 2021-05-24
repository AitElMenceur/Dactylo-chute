#ifndef JEU
#define JEU
// Ait Elmenceur Ilyès
#include <ctime>
#include <iostream>
#include <thread>
#include <future>
#include <vector>

#include"List.h"
#include "graphmot.h"
using namespace std;

class Jeu {
	int score_;
	double difficulty_;
	list<double> wpm_;
	List* list_;
	clock_t time_[2] = { 0 };
public:
	/**
	 * @brief Constructeur de la classe Jeu
	 * @param score 
	 * @param wpm 
	*/
	Jeu(int score = 0, int wpm = 0);
	/**
	 * @brief Construcuteur de la classe Jeu, permet de charger un fichier text
	 * @param file 
	 * @param dificulty 
	*/
	Jeu(string file,int dificulty = 0);
	~Jeu();

	/**
	 * @brief Demarrage d'un timer pour le calcul de score
	*/
	void starttimer();
	/**
	 * @brief Arret d'un timer pour le calcul de score
	*/
	void stoptimer();

	/**
	 * @brief Calcul le score final en fin de Jeu
	*/
	void computescore();
	/**
	 * @brief Retourne le score de Jeu
	 * @return 
	*/
	int getscore();
	/**
	 * @brief Modifie le paramettre difficulty
	 * @param difficulty 
	*/
	void setdifficulty(int difficulty);
	/**
	 * @brief Retourne le paramettre difficulty de Jeu 
	 * @return 
	*/
	int getdifficulty();

	/**
	 * @brief Calcul de la vitesse de frappe
	*/
	void computewpm();
	/**
	 * @brief Verifie si un mot correspond au dernier mots de la liste 
	 * @param input 
	 * @return 
	*/
	bool Motcorrect(string input);
	/**
	 * @brief Verifie si un mot correspond au dernier mots de la liste 
	 * @param input 
	 * @return 
	*/
	vector<bool> Lettrecorrectes(string input);
	/**
	 * @brief Verifie si il reste des mots dans liste 
	 * @return 
	*/
	bool Plusdemots();
	/**
	 * @brief Enleve le dernier mot de la liste
	*/
	void MotSuivant();
	/**
	 * @brief Renvoie le dernier mot de la liste
	 * @return 
	*/
	Mot* Getlast();
};
#endif 

