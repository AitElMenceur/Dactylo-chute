#include "graphmot.h"
#include "Interface.h"
#include "Test.h"

int test_graphMot() {
	string s = "Hello world ses grands morts";
	Mot ot(s, s.size());
	graphMot mot = graphMot(ot);
	Interface fenetre;
	string lettre;
	int position=0;
	/*
	fenetre.drawMot(mot);
	fenetre.display();
	mot.changeColor(false, 0);
	mot.changeColor(true, 1);
	fenetre.drawMot(mot);
	fenetre.display();
	fenetre.clear();
	*/
	while (fenetre.isOpen())
	{
		sf::Event event;
		while (fenetre.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				fenetre.close();
			lettre = fenetre.Keystroke(event);
			if (lettre!="") {
				mot.changeColor(mot.TestLettre(position, lettre), position);
				if (mot.TestLettre(position, lettre)) {
					position++;
				}
			}
		}
		
		fenetre.drawMot(mot);
		fenetre.display();
		fenetre.clear();
		mot.moveMot();
		
		}
	return 0;
}