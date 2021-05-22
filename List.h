#ifndef LIST
#define LIST
#include <list>
#include <fstream>

#include "Mot.h"
using namespace std;

static string PATH_ = "./Mots/";

class List {
	list<Mot*> list_;
	int size_;
public:
	Mot* getlast();
	List(int difficulty = 0);
	List(string file = "difficulty_0.txt");
	int getsize();
	~List();
	void display();
	void motsuivant();
};
#endif 
