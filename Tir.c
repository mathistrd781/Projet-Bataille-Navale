//
// Created by mathi on 23/11/2022.
//

#include "header.h"

void tir() {
    char toucheCurseur = '0';
    char toucheTir = '0';
    int x = 5, y = 86;

    gotoligcol(37, 55);
    printf("ESPACE - Tirer");

    gotoligcol(39, 55);
    printf("ENTER - Changer d'action");

    gotoligcol(x, y);
    hide_cursor(1);

    do {
        toucheTir = getch();
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

                /*
                 if (tabEnnemi[(x-3)/2][(y-82)/4] == NULL){ //tir dans l'eau
                 gotoligcol(x, y);
                 Couleur(bleu, CouleurFond);
                 printf("%c", Rond);
                 }
                 else if (tabEnnemi[(x-3)/2][(y-82)/4] == OCCUPE){ //tir touche un bateau
                 gotoligcol(x, y);
                 Couleur(jaune, CouleurFond);
                 printf("%c", Rond);
                 }
                 else if ((tabEnnemi[(x-3)/2][(y-82)/4] == OCCUPE) && Bateau_Coule){ //tir coule un bateau
                 for (int i = 0; i < SIZE_BATEAU; i++){
                        gotolicol(x+i, y); //si bateau place verticalement (gotoligcol(x, y+i) sinon)
                        Couleur(rougeFonce, CouleurFond);
                        printf("%c", Rond);
                    }
                 }
                 */
                break;

            case ENTER : //retour choix action
                system("cls");
                hide_cursor(0);
                jeu();
                actionJoueur();
                break;
        }
    }while(toucheTir!=SPACE);


}