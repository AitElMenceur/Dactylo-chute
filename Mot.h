#ifndef Mot
#define MOT

#include <string>
#include <iostream>
using namespace std;

class Mot {
	string mot_;
	int size_;
public:
	Mot(string mot, int size);

	bool TestLettre(int position, string lettre);
	bool TestMot(string mot);
	string getmot();
};
#endif // !Mot

