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
	List* list_;
	clock_t time_[2] = { 0 };
public:
	Jeu(int score = 0, int difficulty = 0, int wpm = 0);


	void starttimer();
	void stoptimer();

	void computescore();
	int getscore();

	void setdifficulty(int difficulty);
	int getdifficulty();

	void computewpm();

	bool Motcorrect(string input);
	vector<bool> Lettrecorrectes(string input);
	bool Plusdemots();
	bool worldisonscreen();

	void MotSuivant();
};
#endif 

