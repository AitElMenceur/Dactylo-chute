#ifndef Jeu
#define JEU

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
	Jeu(int score = 0, int wpm = 0);
	Jeu(string file,int score = 0,int wpm = 0);
	~Jeu();


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

	void MotSuivant();
};
#endif 

