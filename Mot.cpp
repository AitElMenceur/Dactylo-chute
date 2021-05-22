#include "Mot.h"

Mot::Mot(string mot, int size)
{
	mot_ = mot;
	size_ = size;
}

Mot::~Mot()
{
}

bool Mot::TestLettre(int position, string lettre)
{
	return mot_.substr(position, 1) == lettre;
}

bool Mot::TestMot(string mot)
{
	return mot == mot_;
}

int Mot::getsize()
{
	return size_;
}

string Mot::getmot()
{
	return mot_;
}
