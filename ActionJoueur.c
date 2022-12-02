#include "header.h"

void actionJoueur(int choixDifficulte, char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi){
    int i;
    int x, y;
    char toucheAction = '0';

    afficheJoueur ();

    ///CURSEUR
    x = 38;
    y = 56;

    do
    {
        do
        {
            toucheAction = getch();
        } while ((toucheAction != 'P') && (toucheAction != 'H') && (toucheAction != ENTER) && (toucheAction != v) && (toucheAction != V) && (toucheAction != ESC));

        if (toucheAction == ESC)
        {
            system("cls");
        }
        else
        {
            if ((toucheAction == v) || (toucheAction == V))
            {
                system("cls");

                gotoligcol(1, 60);
                printf("Bateaux Ennemis :");

                affichagePlateau(plateau_ennemi, 5, 40);

                ///Retour Plateau
                Couleur(rougeFonce, CouleurFond);
                gotoligcol(39, 55);
                printf("V - Retour Plateau de jeu");
                Couleur(CouleurTexte, CouleurFond);

                do
                {
                    toucheAction = getch();
                } while ((toucheAction != v) && (toucheAction != V));

                system("cls");

                affichagePlateauJoueur (plateau_bateau, plateau_tirs, plateau_ennemi);
                afficheJoueur ();
            }
            else
            {
                gotoligcol(x, y);
                printf(" ");

                switch (toucheAction)
                {
                    case 'P' :

                        if (x < 40) {
                            if (x + 1 == 41)
                                y = 56;
                            if (x + 1 == 40)
                                y = 56;
                            if (x + 1 == 39)
                                y = 56;

                            x = x + 1;
                            gotoligcol(x, y);
                            printf("%c", FLECHE);
                        }
                        else
                        {
                            gotoligcol(x, y);
                            printf("%c", FLECHE);
                        }
                        break;

                    case 'H' :

                        if (x > 38)
                        {
                            if (x - 1 == 40)
                                y = 56;
                            if (x - 1 == 39)
                                y = 56;
                            if (x - 1 == 38)
                                y = 56;

                            x = x - 1;
                            gotoligcol(x, y);
                            printf("%c", FLECHE);
                        }
                        else
                        {
                            gotoligcol(x, y);
                            printf("%c", FLECHE);
                        }
                        break;
                }
            }
        }
    }while (toucheAction != ENTER && toucheAction != ESC);

    ///ACTION
    if (x == 38 && toucheAction != ESC)
    {
        system("cls");
        tir(choixDifficulte, plateau_bateau, plateau_tirs, plateau_ennemi);
        boucle_de_jeu(choixDifficulte, plateau_bateau, plateau_tirs, plateau_ennemi);
    }
    else
    {
        if (x == 39 && toucheAction != ESC)
        {
            system("cls");
            Eclairage (plateau_bateau, plateau_tirs, plateau_ennemi);
            boucle_de_jeu(choixDifficulte, plateau_bateau, plateau_tirs, plateau_ennemi);
        }
        else
        {
            if (x == 40 && toucheAction != ESC)
            {
                system("cls");
                //Déplacer bateau
                boucle_de_jeu(choixDifficulte, plateau_bateau, plateau_tirs, plateau_ennemi);
            }
        }
    }
}


void afficheJoueur ()
{
    int i, x, y;
    ///AFFICHAGE COMMANDES
    Couleur(rougeFonce, CouleurFond);

    ///Affichage lignes verticales
    x = 0;
    for (i = 0; i < 34; i++)
    {
        gotoligcol(x, 71);
        printf("%c", BAR_V);
        x++;
    }

    x = 35;
    for (i = 0; i < 8; i++)
    {
        gotoligcol(x, 54);
        printf("%c", BAR_V);
        x++;
    }

    x = 35;
    for (i = 0; i < 8; i++)
    {
        gotoligcol(x, 88);
        printf("%c", BAR_V);
        x++;
    }


    ///Affichage lignes horizontales
    gotoligcol(34, 0);
    for (i = 0; i < 144; i++)
    {
        printf("%c", BAR_H);
    }

    gotoligcol(36, 66);
    for (i = 0; i < 11; i++)
    {
        printf("%c", BAR_H);
    }

    ///Affichage de l'intersection
    gotoligcol(34, 71);
    printf("%c", INTER_HAUT);


    ///MENU Actions
    ///Affichage texte
    Couleur(CouleurTexte, CouleurFond);
    gotoligcol(35, 68);
    printf("ACTIONS");
    gotoligcol(38, 58);
    printf("Tirer sur une case ennemi");
    gotoligcol(39, 58);
    printf("Lancer une fusee eclairante");
    gotoligcol(40, 58);
    printf("Deplacer d'une case un bateau");

    gotoligcol(35, 15);
    printf("Informations joueurs :");
    gotoligcol(35, 105);
    printf("Informations Ennemis :");
}
