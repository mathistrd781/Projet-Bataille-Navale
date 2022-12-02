#include "header.h"

unsigned int getSizeBateau(e_type_bateau type) {
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
            if (pos->x <= 0)
                return -1;
            pos->x--;
            break;

        case BAS:
            if (pos->x >= SIZE_TAB-1)
                return -1;
            pos->x++;
            break;

        case GAUCHE:
            if (pos->y <= 0)
                return -1;
            pos->y --;
            break;

        case DROITE:
            if (pos->y >= SIZE_TAB-1)
                return -1;
            pos->y ++ ;
            break;
    }
    return 0;
}


char getRepresentationBateau(e_type_bateau type) {
    switch (type) {
        case SOUS_MARIN:
            return 'S';

        case PORTE_AVION:
            return 'P';

        case DESTROYER:
            return 'D';

        case CROISEUR:
            return 'C';
    }
}

void placerSurGrille(char **tableau_bateau, e_type_bateau type, e_direction direction, t_coord pos) {
    int size = getSizeBateau(type);
    for (int i = 0 ; i < size ; i++) {
        tableau_bateau[pos.x][pos.y] = getRepresentationBateau(type);
        iterPosDirection(direction, &pos);
    }
}

void printCoord(t_coord pos) {
    printf("(%d, %d)\n", pos.x, pos.y);
}

void printDirection(e_direction dir) {
    switch(dir) {
        case HAUT:
            printf("HAUT\n");
            break;
        case DROITE:
            printf("DROITE\n");
            break;
        case GAUCHE:
            printf("GAUCHE\n");
            break;
        case BAS:
            printf("BAS\n");
            break;
    }
}

void placementBateau(char **tableau_bateau, e_type_bateau type_bateau) {
    unsigned int size_bateau = getSizeBateau(type_bateau);
    bool mal_placer = false;

    t_coord bateau_pos;
    e_direction direction;
    do {

        do {
            // Générer aléatoirement position bateau
            bateau_pos.x = rand() % SIZE_TAB;
            bateau_pos.y = rand() % SIZE_TAB;
        } while (tableau_bateau[bateau_pos.x][bateau_pos.y] != EMPTY_CELL);
        direction = rand() % N_DIR;

        mal_placer = false;
        t_coord it_pos_bateau = bateau_pos;
        // Vérification pour chaque cellule du bateau si:
        for (int i = 0; i < size_bateau; i++) {
            // Hors limite carte
            if (iterPosDirection(direction, &it_pos_bateau) == -1)
                mal_placer = true;
            // Ou Sur une cellule non libre
            if (tableau_bateau[it_pos_bateau.x][it_pos_bateau.y] != EMPTY_CELL)
                mal_placer = true;
        }
    } while(mal_placer);

    placerSurGrille(tableau_bateau, type_bateau, direction, bateau_pos);

    // FIN LOOP
}
