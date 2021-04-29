#ifndef List
#include <list>
#include <fstream>
#include "Mot.h"
using namespace std;

class List{
	list<Mot*> list_;
	int size_;

public:
	List(int difficulty);
	~List();
	void display();
};

#endif 
