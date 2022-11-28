//
// Created by mathi on 23/11/2022.
//

#include "header.h"


char ** genererPlateau(int hauteur, int largeur) {
    char **plateau = malloc(sizeof(char*) * hauteur);
    for (int i = 0 ; i < hauteur ; i++)
    {
        plateau[i] = malloc(sizeof(char) * largeur);
        for (int j = 0 ; j < largeur ; j++)
            plateau[i][j] = ' ';
    }
    return plateau;
}


void freePlateau(char ** plateau, int hauteur) {
    for (int i = 0; i < hauteur; i++)
    {
        free(plateau[i]);
    }
    free(plateau);
}


void affichagePlateau(char ** plateau, int x_initial, int y_initial) {
    if (plateau == NULL)
        return;

    gotoligcol(x_initial, y_initial);

    for (int i = 0; i < HAUTEUR_SQUELETTE; i++)
    {
        gotoligcol(x_initial + i, y_initial);
        if (IS_PAIR(i) && i != 0)
        {
            printf("%c", GET_LETTER(i));
        }
        else if (i != 0)
        {
            printf("%c", BAR_H);
        }
        for (int j = 0; j < LARGEUR_SQUELETTE; j++)
        {
            if (i+j == 0)
                printf(" ");
            if (i == 0 && j != 0)
            {
                if (IS_PAIR(j))
                {
                    printf(" %d", GET_NUMBER(j));
                    if (IS_1_DIGIT(GET_NUMBER(j)))
                        printf(" ");
                } else
                {
                    printf("%c", BAR_V);
                }
            } else if (IS_PAIR(i) && IS_PAIR(j)) //si i et j pair
            {
                printf(" %c ", GET_CELL(plateau, i, j));  // afficher cellule
            } else //sinon, afficher squelette
            {
                if (IS_IMPAIR(j) && IS_IMPAIR(i)) //si i et j impair
                {
                    printf("%c", CROIX);
                } else if (IS_IMPAIR(j))
                {
                    printf("%c", BAR_V);
                } else if (IS_IMPAIR(i))
                {
                    printf("%c%c%c", BAR_H, BAR_H, BAR_H);
                }
            }
        } printf("\n");
    }
}





