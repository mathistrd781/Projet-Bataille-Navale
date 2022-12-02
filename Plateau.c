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


void affichagePlateauJoueur (char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi)
{
    gotoligcol(1, 7);
    printf("Vos Bateaux :");
    affichagePlateau(plateau_bateau, 3, 2);

    gotoligcol(1, 85);
    printf("Vos tirs :");
    affichagePlateau(plateau_tirs, 3, 80);

    //heure();

    //chronometre ();
}

void vider_Plateau (char ** plateau_bateau)
{
    for (int i = 0; i<SIZE_TAB; i++)
    {
        for (int j = 0; j<SIZE_TAB; j++)
        {
            plateau_bateau[i][j] = EMPTY_CELL;
        }
    }
}

void heure ()
{
    int h, min, s, day, mois, an;
    time_t now;

    // Renvoie l'heure actuelle
    time(&now);
    // Convertir au format heure locale
    gotoligcol(37, 15);
    struct tm *local = localtime(&now);
    h = local->tm_hour;
    min = local->tm_min;
    s = local->tm_sec;
    day = local->tm_mday;
    mois = local->tm_mon + 1;
    an = local->tm_year + 1900;
    gotoligcol(39, 15);
    printf("L'heure : %02d:%02d:%02d\n", h, min, s);
    // Afficher la date courante
    gotoligcol(41, 15);
    printf("La date : %02d/%02d/%d\n", day, mois, an);
}

void chronometre ()
{
    int valeur = 60;
    double temps = 0;

    temps = clock();

    if ((int)((clock()-temps) / CLOCKS_PER_SEC) > valeur) {
        system("clear");
        gotoligcol(43, 15);
        printf("%d", valeur);
        ++valeur;
    }

    gotoligcol(50, 15);
    printf("%ld \n", clock());
    printf("%ld", temps);
    /*

    do {
        gotoligcol(43, 15);
        printf("%d secondes", valeur);

        valeur--;
        Sleep(1000);
    } while (valeur != 0);

    printf("\a\n\nFIN DU COMPTE A REBOURS\a");*/
}
