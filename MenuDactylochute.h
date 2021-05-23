#ifndef DACTYLO
#define DACTYLO

#include "menu.h"

class MenuDactylochute : public Menu
{
  public:
      MenuDactylochute(); // redéfinition constructeur parent
    void executerOption(const string &nom,bool &fin); // méthode redéfinie
    void play(); //nouvelle méthode
    
    string loadfile();
    int choosedifficulty();
};
#endif
