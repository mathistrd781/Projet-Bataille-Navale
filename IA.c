#include "header.h"


int choixIA () // choix du level de difficulté
{
    int x = 21, y = 68;
    char toucheIA = '0';
    int choixDifficulte;
    gotoligcol(20,70);
    printf ("Veuillez choisir le niveaux dd diffculte voulu pour la partie");
    gotoligcol(21,70);
    printf("Facile");
    gotoligcol(22,70);
    printf("Moyen");
    gotoligcol(23,70);
    printf("Difficile");

    do {
        do {
            toucheIA = getch();
        } while ((toucheIA != FLECHE_BAS) && (toucheIA != FLECHE_HAUT) && (toucheIA != ENTER));

        gotoligcol(x, y);
        printf (" ");
        switch (toucheIA){
            case FLECHE_BAS:
                if (x<23){
                    if (x+1 == 24)
                        y = 68;

                    if (x+1 == 23)
                        y = 68;

                    if (x+1 == 22)
                        y = 68;

                    x++;

                    gotoligcol(x,y);
                    printf ("%c", FLECHE);
                }

                else
                {
                    gotoligcol(x,y);
                    printf ("%c", FLECHE);
                }
                break;

            case FLECHE_HAUT:
                if (x>21){
                    if (x-1 == 23)
                        y = 68;

                    if (x-1 == 22)
                        y = 68;

                    if (x-1 == 21)
                        y = 68;

                    x--;

                    gotoligcol(x,y);
                    printf ("%c", FLECHE);
                }

                else
                {
                    gotoligcol(x,y);
                    printf ("%c", FLECHE);
                }
                break;

        }
    } while (toucheIA != ENTER);

    /// ACTION

    if (x == 21){
        system("cls");
        choixDifficulte = 1;
    }
    else if (x == 22){
        system("cls");
        choixDifficulte = 2;
    }
    else if (x == 23){
        system("cls");
        choixDifficulte = 3;
    }


    return choixDifficulte;
}

void IA (int choixdificulte, char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi)
{
    switch (choixdificulte) {
        case 1:
            IA1(plateau_bateau);
            break;
        case 2:
            IA2(plateau_bateau);
            break;
        case 3:
            IA3(plateau_bateau);
            break;
    }
}

void IA1 (char ** plateau_bateau)
{
    int x,y;
    //choisir une case aléatoire parmis les 225
    x = rand () % 18;

    system("cls");
    printf("%d, %d", x, y);

    if (plateau_bateau[(x-3)/2][(y-82)/4] == EMPTY_CELL){ //tir dans l'eau
        gotoligcol(x, y);
        Couleur(3, CouleurFond);
        printf("%c", Rond);
    }
    else if (plateau_bateau[(x-3)/2][(y-82)/4] != EMPTY_CELL){ //tir touche un bateau
        gotoligcol(x, y);
        Couleur(14, CouleurFond);
        printf("%c", Rond);
        //plateau_tirs[(x-3)/2][(y-82)/4] = plateau_bateau[(x-3)/2][(y-82)/4];
    }
    /*else if ((plateau_bateau[(x-3)/2][(y-82)/4] != EMPTY_CELL) && Bateau_Coule){ //tir coule un bateau
    for (int i = 0; i < SIZE_BATEAU; i++){
        gotolicol(x+i, y); //si bateau place verticalement (gotoligcol(x, y+i) sinon)
        Couleur(rougeFonce, CouleurFond);
        printf("%c", Rond);
    }
    }*/

}

void IA2 (char ** plateau_bateau)
{
    //choisir une case aleatoire parmis les 225 et des qu on touche focus les case a cote

}

void IA3 (char ** plateau_bateau)
{
    //choisir les cases les plus pose
}
