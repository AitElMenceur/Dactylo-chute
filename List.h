#ifndef List
#include <list>
#include <fstream>
#include "Mot.h"
using namespace std;

class List {
	list<Mot*> list_;
	int size_;
public:
	Mot* getlast();
	List(int difficulty = 0);
	int getsize();
	~List();
	void display();
	void motsuivant();
};

#endif 
