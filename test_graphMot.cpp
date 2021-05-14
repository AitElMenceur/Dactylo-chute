#include "graphmot.h"
#include "Interface.h"
#include "Test.h"

int test_graphMot() {
	graphMot mot("Hello", 5);
	Interface fenetre;
	fenetre.draw(mot);
	fenetre.display();
	system("pause");
	return 0;
}