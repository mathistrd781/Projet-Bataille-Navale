#include "header.h"

void finPartie()
{
    int i;

    system("cls");

    hide_cursor(0);

    ///LIGNES HORIZONTALES
    for (i = 65; i < 77; i++)
    {
        gotoligcol(19,i);
        printf("%c", BAR_H);

        gotoligcol(21,i);
        printf("%c", BAR_H);
    }

    ///LIGNES VERTICALES
    for (i = 19; i < 21; i++)
    {
        gotoligcol(i,65);
        printf("%c", BAR_V);

        gotoligcol(i,76);
        printf("%c", BAR_V);
    }

    ///AFFICHAGE ANGLES
    gotoligcol(19,65);
    printf("%c", ANGLE_HG);
    gotoligcol(19,76);
    printf("%c", ANGLE_HD);
    gotoligcol(21, 65);
    printf("%c", ANGLE_BG);
    gotoligcol(21, 76);
    printf("%c", ANGLE_BD);

    gotoligcol(20,66);
    Couleur(rougeFonce,CouleurFond);
    printf("FIN DU JEU");

    Sleep(3000);
}
