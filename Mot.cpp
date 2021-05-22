#include "Mot.h"
#include <algorithm>

Mot::Mot(string mot, int size)
{
	mot_ = mot;
	size_ = size;
}

bool Mot::TestLettre(int position, string lettre)
{
	string m = mot_.substr(position, 1);
	transform(m.begin(), m.end(), m.begin(), ::tolower);
	transform(lettre.begin(), lettre.end(), lettre.begin(), ::tolower);
	return m == lettre;
}

bool Mot::TestMot(string mot)
{
	return mot_ == mot;
}

int Mot::getsize()
{
	return size_;
}

string Mot::getmot()
{
	return mot_;
}
