#include "Jeu.h"

Jeu::Jeu(int score, int difficulty, int wpm)
{
	score_ = score;
	difficulty_ = difficulty;
	list_ = new List(difficulty_);
}

int Jeu::getscore()
{
	return score_;
}

void Jeu::setscore(int score)
{
	score_ = score;
}

void Jeu::setdifficulty(int difficulty)
{
	difficulty_ = difficulty;
}

int Jeu::getdifficulty()
{
	return difficulty_;
}

double Jeu::computewpm()
{
	string input = "";
	clock_t begin = clock();
	list_->display();
	while (!list_->getlast()->TestMot(input)) {
		future<string> f = async(std::launch::async, [] {
			auto s = ""s;
			if (cin >> s) return s;
			});

			input = f.get();	
	}
	clock_t end = clock();
	double wpm = double(end - begin) / CLOCKS_PER_SEC;
	wpm_.push_back(wpm);
	return wpm;
}
