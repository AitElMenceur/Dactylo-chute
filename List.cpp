#include "List.h"



using namespace std;
Mot* List::getlast()
{
	return list_.back();
}

List::List(int difficulty)
{
	string path = string("./Mots/difficulty_" + to_string(difficulty) + ".txt");
	ifstream in(path.c_str());
	if (in.is_open()) {
		string line;
		while (getline(in, line)) {
			list_.push_back(new Mot(line, line.size()));
		}
	}
	size_ = list_.size();
}

int List::getsize()
{
	return size_;
}

List::~List()
{
	for (Mot* x : list_) {
		delete(x);
	}
}

void List::display()
{
	for (Mot* x : list_) {
		cout << x->getmot() << endl;
	}
}

void List::motsuivant()
{
	list_.pop_back();
	size_ -= 1;
}

