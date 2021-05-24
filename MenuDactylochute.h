#ifndef DACTYLO
#define DACTYLO

#include "menu.h"
#include <iostream>
#include <cstdlib>
#include <filesystem>
#include "Jeu.h"
#include "graphmot.h"
#include "Interface.h"
using namespace std::filesystem;
// Ait Elmenceur Ily�s
class MenuDactylochute : public Menu
{
  public:
      MenuDactylochute(); 
    void executerOption(const string &nom,bool &fin); 
    /**
     * @brief Lance une partie du jeu
    */
    void play(); 
    /**
     * @brief Charge le nom d'un fichier texte � partir du repertoire ./Mots
     * @return 
    */
    string loadfile();
    /**
     * @brief Renvoie la difficult� selectionn�e
     * @return 
    */
    int choosedifficulty();
};
#endif
