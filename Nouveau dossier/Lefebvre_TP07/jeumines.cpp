#include "jeumines.h"

JeuMines::JeuMines()
{

}





void JeuMines::jouerJeuMines()
{
    cout<<"Je suis ici";
    champMines.initTerrain(20);
    champMines.afficheTerrain();
    getch();
    champMines.afficheEmplacementMines();
    getch();
}






/*void JeuMines::jouerJeuMines()
{
    do
    {
        clavier=getch();
        nbCoups++;
        if()
    }
}*/
