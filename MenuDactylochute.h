#ifndef DACTYLO
#define DACTYLO

#include "menu.h"

class MenuDactylochute : public Menu
{
  public:
      MenuDactylochute(); // red�finition constructeur parent
    void executerOption(const string &nom,bool &fin); // m�thode red�finie
    void play(); //nouvelle m�thode
    
    string loadfile();
    int choosedifficulty();
};
#endif
