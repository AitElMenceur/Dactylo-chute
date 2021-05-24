#include "MenuDactylochute.h"



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
	Jeu j = Jeu(loadfile(), choosedifficulty());
	Interface fenetre;
	fenetre.push_back(new graphMot(*j.Getlast()));
	string lettre;
	int position = 0;
	bool pause = false;

	while (fenetre.isOpen())
	{
		j.starttimer();
		while (fenetre.size() != 0)
		{
			graphMot* motatester = fenetre.front();
			sf::Event event;
			if (pause) {
				pause = fenetre.pause();
			}
			else {
				while (fenetre.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						fenetre.close();

					lettre = fenetre.Keystroke(event);
					if (lettre == "pause") pause = !pause;
					else if (lettre != "") {
						motatester->changeColor(motatester->TestLettre(position, lettre), position);
						if (motatester->TestLettre(position, lettre)) {
							position++;
							if (position == motatester->getsize()) {
								j.computewpm();
								fenetre.pop_front();
								j.starttimer();
								position = 0;
							}
							if (position == motatester->getsize() - 2) {
								if (!j.Plusdemots()) j.MotSuivant();
								if (!j.Plusdemots()) {
									fenetre.push_back(new graphMot(*j.Getlast()));
								}
							}
						}
					}
				}
				fenetre.drawlist();
				fenetre.display();
				fenetre.clear();
			}

			if (!fenetre.testBarre(*motatester, j.getdifficulty()) && fenetre.size() < 2) {
				if (!j.Plusdemots()) j.MotSuivant();
				if (!j.Plusdemots()) {
					fenetre.push_back(new graphMot(*j.Getlast()));
				}
			}

			if (!fenetre.testEcran(*motatester)) {
				j.starttimer();
				fenetre.pop_front();
				if (!j.Plusdemots()) j.MotSuivant();
				if (!j.Plusdemots()) {
					fenetre.push_back(new graphMot(*j.Getlast()));
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
	int i = 0; bool fin = false;
	while (true) {
		for (const auto& entry : directory_iterator("./Mots/")) {

			files.push_back(entry.path().relative_path().filename().string());
			std::cout << i << " : " << files.back() << std::endl;
			i++;
		}
		cout << "choisir un numéro de fichier : ";
		cin >> path;
		if (path > i - 1 || path < 0) { i = 0; cout << "Veuillez choisir un numero valide" << endl; }
		else return files[path];
	}
	return "";
}

int MenuDactylochute::choosedifficulty()
{
	int dif;
	cout << " Choisir une difficulté : (1-2-3)" << endl;
	cin >> dif;
	return dif;
}


