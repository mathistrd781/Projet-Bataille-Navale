//
// Created by mathi on 14/11/2022.
//

#include "header.h"

void presentation()
{
    gotoligcol(18,50);
    Sleep(150);
    Couleur(bleuFonce,CouleurFond);
    printf("B  ");

    Couleur(vertFonce,CouleurFond);
    Sleep(150);
    printf("A  ");

    Sleep(150);
    Couleur(bleuClair,CouleurFond);
    printf("T  ");

    Sleep(150);
    Couleur(rougeFonce,CouleurFond);
    printf("A  ");

    Sleep(150);
    Couleur(violet,CouleurFond);
    printf("I  ");

    Sleep(150);
    Couleur(vertCacadoie,CouleurFond);
    printf("L  ");

    Sleep(150);
    Couleur(turquoise,CouleurFond);
    printf("L  ");

    Sleep(150);
    Couleur(grisFonce,CouleurFond);
    printf("E    ");

    Sleep(150);
    Couleur(jaune,CouleurFond);
    printf("N  ");

    Sleep(150);
    Couleur(blanc,CouleurFond);
    printf("A  ");

    Sleep(150);
    Couleur(rougeFluo,CouleurFond);
    printf("V  ");

    Sleep(150);
    Couleur(bleuFluo,CouleurFond);
    printf("A  ");

    Sleep(150);
    Couleur(vertFluo,CouleurFond);
    printf("L  ");

    Sleep(150);
    Couleur(grisClair,CouleurFond);
    printf("E");

    Sleep(50);
    gotoligcol(19,47);
    Couleur(CouleurTexte,CouleurFond);
    printf("_______________________________________________");


    Sleep(500);
    gotoligcol(29, 61);
    for (int i = 0; i < 19; i++){
        printf("%c", BAR_H);
    }
    gotoligcol(36, 61);
    for (int i = 0; i < 19; i++){
        printf("%c", BAR_H);
    }
    for (int i = 0; i < 6; i++){
        gotoligcol(30+i, 61);
        printf("%c", BAR_V);
    }
    for (int i = 0; i < 6; i++){
        gotoligcol(30+i, 80);
        printf("%c", BAR_V);
    }
    gotoligcol(29, 61);
    printf("%c", ANGLE_HG);
    gotoligcol(29, 80);
    printf("%c", ANGLE_HD);
    gotoligcol(36, 61);
    printf("%c", ANGLE_BG);
    gotoligcol(36, 80);
    printf("%c", ANGLE_BD);

    Couleur(rougeFonce, CouleurFond);
    gotoligcol(30, 70);
    printf("BY");
    Couleur(CouleurTexte, CouleurFond);
    gotoligcol(32, 62);
    printf("Sebastien BARANGER");
    gotoligcol(33, 65);
    printf("Mathis TRIDON");
    gotoligcol(34, 66);
    printf("Jules PINTE");
    gotoligcol(35, 66);
    printf("Ergun YAMAN");

    Sleep(3000);
    system("cls");
}
