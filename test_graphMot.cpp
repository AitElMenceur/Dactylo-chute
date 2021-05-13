#include "graphmot.h"
#include "Interface.h"

int test_graphMot() {
	graphMot mot("Hello", 5);
	Interface fenetre;
	fenetre.draw(mot);
	return 0;
}