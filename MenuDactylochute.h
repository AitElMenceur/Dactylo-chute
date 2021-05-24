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
     * @brief Charge le nom d'un fichier texte à partir du repertoire ./Mots
     * @return 
    */
    string loadfile();
    /**
     * @brief Renvoie la difficulté selectionnée
     * @return 
    */
    int choosedifficulty();
};
#endif
