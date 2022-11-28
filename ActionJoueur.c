//
// Created by mathi on 23/11/2022.
//

#include "header.h"

void actionJoueur(){
    int i;
    int x, y;
    char toucheAction = '0';


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
            menu();
        }
        else
        {
            if ((toucheAction == v) || (toucheAction == V))
            {
                system("cls");
                char ** plateauEnnemi = genererPlateau(HAUTEUR, LARGEUR);

                gotoligcol(1, 60);
                printf("Bateaux Ennemis :");
                affichagePlateau(plateauEnnemi, 5, 40);
                freePlateau(plateauEnnemi, HAUTEUR);

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
                jeu();
                actionJoueur();
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
    }while (toucheAction != ENTER);

    ///ACTION
    if (x == 38)
    {
        system("cls");
        //Tirer
        jeu();
        tir();
    }
    else
    {
        if (x == 39)
        {
            system("cls");
            //Eclairer
        }
        else
        {
            if (x == 40)
            {
                system("cls");
                //Déplacer bateau
            }
        }
    }
}