#include <iostream>
#include <cstdlib>
#include "MenuDactylochute.h"
#include <filesystem>
#include "Jeu.h"
#include "graphmot.h"
#include "Interface.h"
using namespace std::filesystem;


MenuDactylochute::MenuDactylochute() : Menu("Dactylochute")
{
	ajouterOption("aide", "Afficher de l'aide");
	ajouterOption("play", "Lancer une partie");
	ajouterOption("quitter", "Sortir de l'application");
}

void MenuDactylochute::executerOption(const string& nom, bool& fin)
{
	if (nom == "play") play();
	else Menu::executerOption(nom, fin);
}

void MenuDactylochute::play()
{
	Jeu j = Jeu(loadfile(),choosedifficulty());
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

			if (!fenetre.testBarre(*motatester, j.getdifficulty()) && mot.size() < 2) {
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
		system("cls");
		cout << "Voici votre score : " << j.getscore() << endl;
		system("pause");
	}
}

string MenuDactylochute::loadfile()
{
	int path;
	std::vector<string> files;
	int i = 0;bool fin = false;
	while (true) {
		for (const auto& entry : directory_iterator("./Mots/")) {
			
			files.push_back(entry.path().relative_path().filename().string());
			std::cout << i << " : " << files.back() << std::endl;
			i++;
		}
		cout << "choisir un numéro de fichier : ";
		cin >> path;
		if (path > i-1 || path < 0) { i = 0; cout << "Veuillez choisir un numero valide" << endl; }
		else return files[path];
	}
	return "";
}

int MenuDactylochute::choosedifficulty()
{
	int dif;
	cout<<" Choisir une difficulté : (1-2-3)" <<endl; 
	cin >> dif;
	return dif;
}
 

