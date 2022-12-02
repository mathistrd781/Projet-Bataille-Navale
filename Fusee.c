#include "header.h"

void Eclairage(char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi){

    char sauvTab[15][15];
    int i,j;
    char toucheFusee='0';
    char toucheCurseur='0';
    int x = 5, y = 86;

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

            case SPACE : //Eclairer
                system("cls");

                /// Sauvegarde le tab
                for (i=0;i<15;i++){
                    for (j=0;j<15;j++){
                        sauvTab[i][j]=plateau_tirs[i][j];
                    }
                }

                /// Remplissage du tableau éclairege
                for(j=0;j<=3;j++){
                    for(i=0;i<=3;i++){
                        if (((x-3)/2)+i<15) {
                            plateau_tirs[ (x-3)/2 + j][(y-82)/4 + i] = plateau_ennemi[(x-3)/2+ j][(y-82)/4 + i];
                        }
                    }
                }

                /// Affichage du tableau tir
                affichagePlateauJoueur (plateau_bateau, plateau_tirs, plateau_ennemi);

                Sleep(5000);

                /// Remet le tab a ces valeur de base
                for (i=0;i<15;i++){
                    for (j=0;j<15;j++){
                        plateau_tirs[i][j]=sauvTab[i][j];
                    }
                }
                system("cls");

                break;

            case ENTER : //retour choix action
                system("cls");
                hide_cursor(0);
                break;
        }
    }while(toucheCurseur!=SPACE && toucheCurseur!=ENTER);
}
