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

void Jeu::starttimer()
{
	time_[0] = clock();
}

void Jeu::stoptimer()
{
	time_[1] = clock();
}

void Jeu::computescore()
{
	for (double x : wpm_) {
		score_ += x;
	}
	score_ *= (difficulty_ + 1);

}

void Jeu::setdifficulty(int difficulty)
{
	difficulty_ = difficulty;
}

int Jeu::getdifficulty()
{
	return difficulty_;
}

void Jeu::computewpm()
{
	wpm_.push_back(double(time_[1] - time_[0]) / CLOCKS_PER_SEC);
}

bool Jeu::Motcorrect(string input) {
	return list_->getlast()->TestMot(input);
}

vector<bool> Jeu::Lettrecorrectes(string input)
{
	vector<bool> b;
	for (int i = 0;i < input.size();i++) {
		if (list_->getlast()->TestLettre(i, input.substr(i, 1))) {
			b.push_back(true);

		}
		else {
			b.push_back(false);
		}
	}
	return b;
}

bool Jeu::Plusdemots()
{
	return list_->getsize() == 0;
}

void Jeu::MotSuivant()
{
	stoptimer();
	computewpm();
	list_->motsuivant();
}



