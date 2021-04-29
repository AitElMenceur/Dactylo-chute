#ifndef Jeu
#include"List.h"
class Jeu {
	int score_;
	int difficulty_;
	int wpm_;
	List list_;
public:
	Jeu(int score = 0, int difficulty = 0, int wpm = 0);
	int getscore();
	void setscore(int score);
	void computescore();
	void setdifficulty(int difficulty);
	int getdifficulty();
	void setwpm(int difficulty);
	int getwpm();
	int computewpm();
	bool worldisonscreen();
};
#endif 

