#include "Test.h"
#include "Jeu.h"


void TestJeu() {
	Jeu j = Jeu();
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