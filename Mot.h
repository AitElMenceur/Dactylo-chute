#ifndef Mot

#include <string>
#include <iostream>
using namespace std;


class Mot {
	string mot_;
	int size_;
public:
	Mot(string mot, int size);
	~Mot();

	bool TestLettre(int position, string lettre);
	bool TestMot(string mot);
	int getsize();
	string getmot();

};
#endif // !Mot

