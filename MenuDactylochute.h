#ifndef DACTYLO
#define DACTYLO

#include "menu.h"

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
