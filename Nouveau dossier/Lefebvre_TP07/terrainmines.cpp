#include "terrainmines.h"

TerrainMines::TerrainMines()
{

}
//*************************************************************************************************************************************************
void TerrainMines::initTerrain(int nbMines)
/*
Algorithme : algorithme initTerrain(nbMines) de la classe TerrainMines qui consiste a initialiser le tableau a 0, placer des mines aléatoirement en fonction de nbMines, et qui
             détermine la valeur de chaque case en fonction de l'emplacement des mines.
Auteur : LEFEBVRE Quentin
Date : 12 janvier 2022

Variables de classes : terrain(20)(20) = tableau d'entier

Variables : valCase, cptX, cptY, nbX, nbY = entier

Début
    effacer écran
    valCase <- 0
    pour cptX allant de 0 à 19
        pour cptY allant de 0 à 19
            terrain(cptX)(cptY) <- 0

    pour cptX allant de 0 à nbMines
        nbX <- fonction rand() modulo 20
        nbY <- fonction rand() modulo 20
        si (terrain(nbX)(nbY)=9)
            alors cptX <- cptX-1
        sinon terrain(nbX)(nbY) <- 9

    pour cptX allant de 0 à 19
        pour cptY allant de 0 à 19
            si (terrain(cptX)(cptY) <> 9)
                alors {
                    si ( terrain(cptX)(cptY+1) = 9)
                        alors valCase <- valCase+1
                    si ( terrain(cptX)(cptY-1) = 9)
                        alors valCase <- valCase+1
                    si ( terrain(cptX+1)(cptY) = 9)
                        alors valCase <- valCase+1
                    si ( terrain(cptX-1)(cptY) = 9)
                        alors valCase <- valCase+1
                    si ( terrain(cptX+1)(cptY+1) = 9)
                        alors valCase <- valCase+1
                    si ( terrain(cptX-1)(cptY-1) = 9)
                        alors valCase <- valCase+1
                    si ( terrain(cptX+1)(cptY-1) = 9)
                        alors valCase <- valCase+1
                    si ( terrain(cptX-1)(cptY+1) = 9)
                        alors valCase <- valCase+1
                    terrain(cptX)(cptY) <- valCase
                      }
    afficher "Votre tableau a bien ete initialise."
Fin
*/
{
    system("cls");
    cout<<"Combien de mines voulez vous: ";
    cin>>nbMines;

    int cptX, cptY, nbX, nbY, valCase;
    valCase=0;
    srand(time(0));
    //MISE A 0
    for (cptX=0; cptX<=19; cptX=cptX+1)
    {
        for(cptY=0; cptY<=19; cptY+=1)
            {
                terrain[cptX][cptY]=0;
            }
    //MISE DES BOMBES SUR LE TERRAIN
    for (cptX=0; cptX<nbMines; cptX++)                    //pb de 25 mines si on demande pas le nb de mines, et qui en ajoute 5

        {
            nbX = rand()%20;
            nbY = rand()%20;
            cout<<nbMines<<" nb\n ";
            if (terrain[nbX][nbY]==9)
                cptX=cptX-1;
            else terrain[nbX][nbY]=9;
        }
    //VALEUR DES CASES
    for (cptX=0; cptX<=19; cptX=cptX+1)
        {
            for (cptY=0; cptY<=19; cptY=cptY+1)
                {
                    if(terrain[cptX][cptY] != 0)
                        {
                            if(terrain[cptX][cptY+1]==9)
                                valCase= valCase+1;
                            if(terrain[cptX][cptY-1]==9)
                                valCase=valCase+1;
                            if(terrain[cptX+1][cptY]==9)
                                valCase=valCase+1;
                            if(terrain[cptX-1][cptY]==9)
                                valCase=valCase+1;
                            if(terrain[cptX+1][cptY+1]==9)
                                valCase=valCase+1;
                            if(terrain[cptX-1][cptY-1]==9)
                                valCase=valCase+1;
                            if(terrain[cptX+1][cptY-1]==9)
                                valCase=valCase+1;
                            if(terrain[cptX-1][cptY+1]==9)
                                valCase=valCase+1;
                        }
                }
        }
    }
    cout<<"Votre tableau a bien ete initialise"<<endl<<endl;
    system("pause");
}
//*************************************************************************************************************************************************


void TerrainMines::afficheTerrain()
{   /*Algo: Algorithme afficheTerrain de la classe TerrainMines qui permet d'afficher (les cases avec un caractere) du terrain sur l'ecran console avec
indication de la case de debut et de fin.
      Auteur: Bekki Allan
      Date : 14 Jan 2022

      Variables de classes:

      Variable:  i,j =entier


      Debut
        effacer ecran systeme
        pour i allant de 0 à 20
            pour j allant de 0 à 20
            aller en x=20+i et y=20+j
                afficher "."
        aller en x=17 et y=39
        afficher "D->"
        aller en x=42 et y=20
        afficher "<-A"



        pause
      Fin
      */

    system("cls");
    int i,j;
    for (i=0; i<20; i++)
    {
        for(j=0; j<20;j++)
        {
            gotoxy(20+i,20+j);
            cout<<".";
        }
    }
    gotoxy(17,39);    //je me deplace en x= 17 pour y placer a cote 3 caracteres
    cout<<"D->";
    gotoxy(42,20);    // pareil, je me deplace en Y =42 pour y placer 3 caractere
    cout<<"<-A";
    system("pause");




}


void TerrainMines::afficheEmplacementMines()
{
    /*Algo: algorithme de afficheEmplacementMines() de la classe TerrainMines qui permet d'afficher le terrain avec les mines disposé dessus.
      Auteur: Bekki Allan
      Date: 14 Jan 2022

      Variables de classe: terrain(20)(20)= tableau d'entiers

      Variables :

      Debut
        effacer ecran systeme
        pour i allant de 0 à 20
            pour j allant de 0 à 20
            aller en x=20+i et y=20+j
            si (terrain (i)(j)<>9)
                afficher "."
                sinon afficher "*"
        aller en x=17 et y=39
        afficher "D->"
        aller en x=42 et y=20
        afficher "<-A"





      Fin
    */
    system("cls");
    int i,j;
    for (i=0; i<20; i++)
    {
        for(j=0; j<20;j++)
        {
            gotoxy(20+i,20+j);
            if(terrain[i][j]!=9)
                cout<<".";
            else cout<<"*";


        }
    }

     gotoxy(17,39);
     cout<<"D->";
     gotoxy(42,20);
     cout<<"<-A";
     system("pause");

}













