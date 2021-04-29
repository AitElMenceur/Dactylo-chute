#include"Test.h"
#include "Mot.h"
#include <cassert>

void Testclassmot() {
	Mot mot = Mot("maison", 6);
	assert(mot.TestLettre(1, "a"));
	assert(mot.TestMot("maison"));
	cout<<mot.getmot()<<endl;
}

