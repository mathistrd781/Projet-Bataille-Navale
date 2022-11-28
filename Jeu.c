//
// Created by mathi on 14/11/2022.
//

#include "header.h"

void jeu(){

    char ** plateauBateau = genererPlateau(HAUTEUR, LARGEUR);
    char ** plateauTirs = genererPlateau(HAUTEUR, LARGEUR);
    char ** plateauEnnemi = genererPlateau(HAUTEUR, LARGEUR);

    gotoligcol(1, 7);
    printf("Vos Bateaux :");
    affichagePlateau(plateauBateau, 3, 2);

    gotoligcol(1, 85);
    printf("Vos tirs :");
    affichagePlateau(plateauTirs, 3, 80);




    freePlateau(plateauBateau, HAUTEUR);
    freePlateau(plateauTirs, HAUTEUR);
    freePlateau(plateauEnnemi, HAUTEUR);
}