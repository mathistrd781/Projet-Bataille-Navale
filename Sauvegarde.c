#include "header.h"

void chargerPartie(int choixDifficulte, char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi) {
    FILE* sauvegarde;
    int i,j;
    int n;
    sauvegarde = fopen("sauv.txt", "r");

    /// charger Plateau Bateaux
    for (i=1;i<HAUTEURSAUV;i++){
        for (j=1;j<HAUTEURSAUV;j++){
            n=fgetc(sauvegarde);
            plateau_bateau[i][j]=n;
        }
    }

    /// charger Plateau Tir
    for (i=1;i<HAUTEURSAUV;i++){
        for (j=1;j<HAUTEURSAUV;j++){
            n=fgetc(sauvegarde);
            plateau_tirs[i][j]= n;
        }
    }

    /// charger Plateau Ennemie
    for (i=1;i<HAUTEURSAUV;i++){
        for (j=1;j<HAUTEURSAUV;j++){
            n=fgetc(sauvegarde);
            plateau_ennemi[i][j]= n;
        }
    }

    /// choix
    choixDifficulte=fgetc(sauvegarde);
    fclose(sauvegarde);

}

void sauvegardePartie(int choixDifficulte, char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi) {
    FILE* sauvegarde;
    int i,j;
    sauvegarde = fopen("sauv.txt", "w");
    /// sauv tabBateaux
    for (i=1;i<HAUTEURSAUV;i++){
        for (j=1;j<HAUTEURSAUV;j++){
            fprintf( sauvegarde , "%c", plateau_bateau[i][j]);
        }
        //fprintf(sauvegarde,"\n");
    }
    /// sauv tabEnnemie

    for (i=1;i<HAUTEURSAUV;i++){
        for (j=1;j<HAUTEURSAUV;j++){
            fprintf( sauvegarde , "%c", plateau_ennemi[i][j]);
        }
        //fprintf(sauvegarde,"\n");
    }
    /// sauv tabTIR

    for (i=1;i<HAUTEURSAUV;i++){
        for (j=1;j<HAUTEURSAUV;j++){
            fprintf( sauvegarde , "%c", plateau_tirs[i][j]);
        }
        //fprintf(sauvegarde,"\n");
    }
    /// sauv choix
    fprintf( sauvegarde , "%d", choixDifficulte);
    fclose(sauvegarde);
}
