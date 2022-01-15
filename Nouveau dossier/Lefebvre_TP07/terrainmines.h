#ifndef TERRAINMINES_H
#define TERRAINMINES_H
#include "consoleJR.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

class TerrainMines
{
public:
    TerrainMines();
    void initTerrain(int nbMines=10);
    void afficheTerrain();
    void afficheEmplacementMines();
    void afficheCaseTerrain( int x, int y);
    //Attributs :
                int taille;
                int terrain[20][20];

};

#endif // TERRAINMINES_H
