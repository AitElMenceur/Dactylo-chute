#include "Test.h"
#include "graphmot.h"
#include "Interface.h"
#include <filesystem>
using namespace std::filesystem;


void testinterjeu() {
	std::string path;
	for (const auto& entry : directory_iterator("./Mots/")) {
		std::cout << entry.path().relative_path().filename() << std::endl;
	}

	cout << "choisir un fichier: ";
	cin >> path;

	Jeu j = Jeu(path);
	list<graphMot*> mot;
	mot.push_back(new graphMot(*j.Getlast()));
	Interface fenetre;
	string lettre;
	int position = 0;

	while (fenetre.isOpen())
	{
		j.starttimer();
		while (mot.size() != 0)
		{
			graphMot* motatester = mot.front();
			sf::Event event;
			while (fenetre.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					fenetre.close();
				lettre = fenetre.Keystroke(event);
				if (lettre != "") {
					motatester->changeColor(motatester->TestLettre(position, lettre), position);
					if (motatester->TestLettre(position, lettre)) {
						position++;
						if (position == motatester->getsize()) {
							j.computewpm();
							mot.pop_front();
							j.starttimer();
							position = 0;
						}
						if (position == motatester->getsize() - 2) {
							if (!j.Plusdemots()) j.MotSuivant();
							if (!j.Plusdemots()) {
								mot.push_back(new graphMot(*j.Getlast()));
							}
						}
					}
				}
			}
			for (graphMot* g : mot) {
				fenetre.drawMot(*g);
				g->moveMot();
			}
			fenetre.display();
			fenetre.clear();

			if (!fenetre.testBarre(*motatester, 3) && mot.size() < 2) {
				if (!j.Plusdemots()) j.MotSuivant();
				if (!j.Plusdemots()) {
					mot.push_back(new graphMot(*j.Getlast()));
				}
			}

			if (!fenetre.testEcran(*motatester)) {
				j.starttimer();
				mot.pop_front();
				if (!j.Plusdemots()) j.MotSuivant();
				if (!j.Plusdemots()) {
					mot.push_back(new graphMot(*j.Getlast()));
				}
				j.starttimer();
				position = 0;
			}
		}
		j.computescore();
		fenetre.close();
		cout << j.getscore() << endl;
	}
}