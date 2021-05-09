#include "Test.h"
#include "Jeu.h"
#include <string>
#include <iostream>
#include <filesystem>
using namespace std::filesystem;

void TestJeu() {

	std::string path;
	for (const auto& entry : directory_iterator("./Mots/")) {
		std::cout << entry.path().relative_path().filename() << std::endl;
	}

	cout << "choisir un fichier: ";
	cin >> path;

	Jeu j = Jeu(path);
	string input;
	while (!j.Plusdemots())
	{
		j.starttimer();
		while (!j.Motcorrect(input)) {
			future<string> f = async(std::launch::async, [] {
				auto s = ""s;
				if (cin >> s) return s;
				});
			input = f.get();
			vector<bool> b = j.Lettrecorrectes(input);
			for (int i = 0;i < b.size();i++) {
				if (b.at(i)) {
					cout << input.substr(i, 1);
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}
		j.MotSuivant();

	}
	j.computescore();
	cout << j.getscore() << endl;
}