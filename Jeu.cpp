#include "Jeu.h"

Jeu::Jeu(int score,int wpm)
{
	score_ = score;
	list_ = new List(difficulty_);
	difficulty_ = list_->getlast()->getmot().size() / 4;
}

Jeu::Jeu(string file,int difficulty)
{
	score_ = 0;
	list_ = new List(file);
	setdifficulty(difficulty);
}

Jeu::~Jeu()
{
	delete(list_);
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

void Jeu::resumetimer() 
{
	time_[0] = time_[0] + (clock() - time_[1]);
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
	if (difficulty > 3) difficulty_ = 3;
	if (difficulty<1) difficulty_ = 1;
	else difficulty_ = difficulty;
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

bool Jeu::Plusdemots() //vrai si vide
{
	return list_->getsize() == 0;
}

void Jeu::MotSuivant()
{
	stoptimer();
	computewpm();
	list_->motsuivant();
}

Mot* Jeu::Getlast()
{
	return list_->getlast();
}




