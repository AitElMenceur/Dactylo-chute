#ifndef Jeu

#include"List.h"
#include <ctime>
#include <iostream>
#include <thread>
#include <future>
#include <vector>
using namespace std;

class Jeu {
	int score_;
	int difficulty_;
	list<double> wpm_;
	List *list_;
public:
	Jeu(int score = 0, int difficulty = 0, int wpm = 0);
	int getscore();
	void setscore(int score);
	void computescore();
	void setdifficulty(int difficulty);
	int getdifficulty();  
	double computewpm();
	bool worldisonscreen();
};
#endif 

