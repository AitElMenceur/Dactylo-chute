#ifndef DACTYLO
#define DACTYLO

#include "menu.h"
// Ait Elmenceur Ilyès
class MenuDactylochute : public Menu
{
  public:
      MenuDactylochute(); 
    void executerOption(const string &nom,bool &fin); 
    /**
     * @brief Lance une partie du jeu
    */
    void play(); 
    /**
     * @brief Charge le nom d'un fichier texte à partir du repertoire ./Mots
     * @return 
    */
    string loadfile();
    /**
     * @brief Renvoie la difficulté selectionnée
     * @return 
    */
    int choosedifficulty();
};
#endif

#ifndef JEU
#define JEU
// Ait Elmenceur Ilyès
#include <ctime>
#include <iostream>
#include <thread>
#include <future>
#include <vector>

#include"List.h"
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
#ifndef INTERFACE
#define INTERFACE
// Moutta Abd'Allah 

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
	void drawMot(graphMot& mot);
	void drawlist();
	/**
	 * @brief Test si un mot est toujours à l'ecran
	 * @param mot
	 * @return
	*/
	bool testEcran(graphMot& mot);
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
	string Keystroke(sf::Event& keyevent);
};

#endif




