#ifndef LIST
#define LIST
#include <list>
#include <fstream>
// Ait Elmenceur Ilyès
#include "Mot.h"
using namespace std;

static string PATH_ = "./Mots/";

class List {
	list<Mot*> list_;
	int size_;
public:
	/**
	 * @brief Constructeur, utilise les fichiers difficulty_*.txt (*= un chiffre)
	 * @param difficulty 
	*/
	List(int difficulty = 0);
	/**
	 * @brief Constructeur de la classe List, charge un fichier du repertoire ./Mots/
	 * @param file 
	*/
	List(string file = "difficulty_0.txt");
	
	~List();
	/**
	 * @brief Renvoie la taille de la liste
	 * @return 
	*/
	int getsize();
	/**
	 * @brief Affiche les elements de la liste
	*/
	void display();
	/**
	 * @brief Enleve le dernier mot de la liste
	 * @return
	*/
	void motsuivant();
	/**
	 * @brief Renvoie le dernier mot de la liste
	 * @return
	*/
	Mot* getlast();
};
#endif 
