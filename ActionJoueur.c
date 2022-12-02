//
// Created by mathi on 21/11/2022.
//

#include "header.h"

void aide(){
    int i;

    Couleur(rougeFonce, CouleurFond);
    gotoligcol(2, 67);
    printf("AIDE");
    Couleur(CouleurTexte, CouleurFond);

    ///Affichage cadre Aide
    ///Ligne horizontales
    gotoligcol(1, 66);
    for (i = 0; i < 6; i++)
    {
        printf("%c", 0xC4);
    }
    gotoligcol(3, 66);
    for (i = 0; i < 6; i++)
    {
        printf("%c", 0xC4);
    }

    ///Lignes verticales
    for (i = 2; i < 3; i++)
    {
        gotoligcol(i, 66);
        printf("%c", 0xB3);
    }
    for (i = 2; i < 3; i++)
    {
        gotoligcol(i, 71);
        printf("%c", 0xB3);
    }

    ///Affichage angles
    gotoligcol(1, 66);
    printf("%c", 0xDA); //angle haut gauche
    gotoligcol(1, 71);
    printf("%c", 0xBF); //angle haut droite
    gotoligcol(3, 66);
    printf("%c", 0xC0); //angle bas droite
    gotoligcol(3, 71);
    printf("%c", 0xD9); //angle bas gauche


    ///Affichage cadre règles + commandes
    ///Affichage lignes horizontales
    gotoligcol(7, 3);
    for (i = 0; i < 135; i++)
    {
        printf("%c", 0xC4);
    }
    gotoligcol(30, 3);
    for (i = 0; i < 135; i++)
    {
        printf("%c", 0xC4);
    }

    ///Affichage lignes verticales
    for (i = 8; i < 30; i++)
    {
        gotoligcol(i, 2);
        printf("%c", 0xB3);
    }
    for (i = 8; i < 30; i++)
    {
        gotoligcol(i, 138);
        printf("%c", 0xB3);
    }
    for (i = 8; i < 30; i++)
    {
        gotoligcol(i, 68);
        printf("%c", 0xB3);
    }
    gotoligcol(7, 68);
    printf("%c", 194);
    gotoligcol(30, 68);
    printf("%c", 193);


    ///Affichage angles
    gotoligcol(7, 2);
    printf("%c", 0xDA); //angle haut gauche
    gotoligcol(7, 138);
    printf("%c", 0xBF); //angle haut droite
    gotoligcol(30, 2);
    printf("%c", 0xC0); //angle bas gauche
    gotoligcol(30, 138);
    printf("%c", 0xD9); //angle bas droite



    gotoligcol(8, 30);
    printf("REGLES DU JEU");
    gotoligcol(9, 29);
    for (i = 0; i < 15; i++)
    {
        printf("%c", 0xC4);
    }
    gotoligcol(8, 95);
    printf("COMMANDES GENERALES");
    gotoligcol(9, 94);
    for (i = 0; i < 21; i++)
    {
        printf("%c", 0xC4);
    }

    gotoligcol(33, 62);
    printf("Bonne Partie !");
    Couleur(rougeFonce, CouleurFond);
    gotoligcol(38, 60);
    printf("ESC - Retour Menu");
    Couleur(CouleurTexte, CouleurFond);
}
