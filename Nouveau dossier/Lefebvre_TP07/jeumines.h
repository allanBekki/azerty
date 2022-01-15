#ifndef JEUMINES_H
#define JEUMINES_H
#include "terrainmines.h"

class JeuMines
{
public:
    JeuMines();
    void presentationJeu();
    void affichePlateauJeu();
    void jouerJeuMines();
    void afficheInfoJoueur();
    void afficheNbCoups();
private:
    //Attributs :
                int nbMines;
                int nbCoups;
                int posX;
                int posY;
                TerrainMines champMines;
};

#endif // JEUMINES_H
