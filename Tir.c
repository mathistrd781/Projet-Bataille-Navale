#include "header.h"

void tir(int choixDifficulte, char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi) {
    char toucheCurseur = '0';
    char toucheTir = '0';
    int x = 5, y = 86;

    gotoligcol(37, 55);
    printf("DOUBLE ESPACE - Tirer");

    gotoligcol(39, 55);
    printf("DOUBLE ENTER - Changer d'action");

    gotoligcol(x, y);
    hide_cursor(1);

    affichagePlateauJoueur (plateau_bateau, plateau_tirs, plateau_ennemi);

    do {
        do {
            toucheCurseur = getch();
        } while ((toucheCurseur != FLECHE_BAS) && (toucheCurseur != FLECHE_HAUT) && (toucheCurseur != FLECHE_DROITE) && (toucheCurseur != FLECHE_GAUCHE) && (toucheCurseur != SPACE) && (toucheCurseur != ENTER));

        switch (toucheCurseur) {
            case FLECHE_BAS :
                if (x < 31) {
                    gotoligcol(x + 2, y);
                    x = x + 2;
                }
                break;

            case FLECHE_HAUT :
                if (x > 5) {
                    gotoligcol(x - 2, y);
                    x = x - 2;
                }
                break;

            case FLECHE_DROITE :
                if (y < 138) {
                    gotoligcol(x, y + 4);
                    y = y + 4;
                }
                break;

            case FLECHE_GAUCHE :
                if (y > 86) {
                    gotoligcol(x, y - 4);
                    y = y - 4;
                }
                break;

            case SPACE : //tirer
                system("cls");
                printf("%d, %d", x, y);
                toucheCurseur = 1;


                 if (plateau_ennemi[(x-3)/2][(y-82)/4] == EMPTY_CELL){ //tir dans l'eau
                     gotoligcol(x, y);
                     Couleur(3, CouleurFond);
                     printf("%c", Rond);
                 }
                 else if (plateau_ennemi[(x-3)/2][(y-82)/4] != EMPTY_CELL){ //tir touche un bateau
                     gotoligcol(x, y);
                     Couleur(14, CouleurFond);
                     printf("%c", Rond);
                     plateau_tirs[(x-3)/2][(y-82)/4] = plateau_ennemi[(x-3)/2][(y-82)/4];
                 }
                 /*else if ((plateau_ennemi[(x-3)/2][(y-82)/4] != EMPTY_CELL) && Bateau_Coule){ //tir coule un bateau
                 for (int i = 0; i < SIZE_BATEAU; i++){
                        gotoligcol(x+i, y); //si bateau place verticalement (gotoligcol(x, y+i) sinon)
                        Couleur(4, CouleurFond);
                        printf("%c", Rond);
                    }
                 }*/
                Couleur(CouleurTexte, CouleurFond);

                break;

            case ENTER : //retour choix action
                system("cls");
                hide_cursor(0);
                break;
        }
    }while(toucheCurseur != SPACE && toucheCurseur != ENTER);

    /*Sleep("2000");
    system("cls");
    hide_cursor(0);*/
}
