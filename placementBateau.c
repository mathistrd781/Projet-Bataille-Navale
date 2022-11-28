//
// Created by mathi on 23/11/2022.
//

#include "header.h"

//Sebastien
/*unsigned int getSizeBateau(e_type_bateau type) {
    switch (type) {
        case SOUS_MARIN:
            return SIZE_SOUS_MARIN;

        case PORTE_AVION:
            return SIZE_PORTE_AVION;

        case DESTROYER:
            return SIZE_DESTROYER;

        case CROISEUR:
            return SIZE_CROISEUR;
    }
}

int iterPosDirection(e_direction direction, t_coord *pos) {
    switch(direction)  {
        case HAUT:
            if (pos->y < 0)
                return -1;
            pos->y--;
            break;

        case BAS:
            if (pos->x >= SIZE_TAB)
                return -1;
            pos->y++;
            break;

        case GAUCHE:
            if (pos->x < 0)
                return -1;
            pos->x --;
            break;

        case DROITE:
            if (pos->x >= SIZE_TAB)
                return -1;
            pos->x ++ ;
            break;
    }
    return 0;
}

#define EMPTY_CELL ' '

void placementBateau(char **tableau_bateau, e_type_bateau type_bateau) {
    unsigned int size_bateau = getSizeBateau(type_bateau);
    bool mal_placer = false;

    do {

        t_coord bateau_pos;
        do {
            // Générer aléatoirement position bateau
            bateau_pos.x = rand() % SIZE_TAB;
            bateau_pos.y = rand() % SIZE_TAB;
        } while (tableau_bateau[bateau_pos.x][bateau_pos.y] != EMPTY_CELL);
        e_direction direction = rand() % N_DIR;

        bool collide_frontiere = false;
        // Vérification pour chaque cellule du bateau si:
        for (int i = 0; i < size_bateau; i++) {
            // Hors limite carte
            if (iterPosDirection(direction, &bateau_pos) == -1)
                mal_placer = true;
            // Ou Sur une cellule non libre
            if (tableau_bateau[bateau_pos.x][bateau_pos.y] != EMPTY_CELL)
                mal_placer = true;
        }
    } while(mal_placer);
    // FIN LOOP
}
*/






