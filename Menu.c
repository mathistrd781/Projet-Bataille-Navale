//
// Created by mathi on 14/11/2022.
//

#include "header.h"

void menu()
{
    int i;
    int x = 15, y = 53;
    char toucheMenu = '0';
    char toucheRetourMenu = '0';

    hide_cursor(0);


    ///AFFICHAGE COMMANDES GENERALES
    Couleur(CouleurTexte, CouleurFond);

    ///LIGNES HORIZONTALES
    for (i = 40; i < 105; i++)
    {
        gotoligcol(25,i);
        printf("%c", BAR_H);

        gotoligcol(34,i);
        printf("%c", BAR_H);
    }

    ///LIGNES VERTICALES
    for (i = 25; i < 34; i++)
    {
        gotoligcol(i,40);
        printf("%c", BAR_V);

        gotoligcol(i,105);
        printf("%c", BAR_V);
    }

    ///AFFICHAGE ANGLES
    gotoligcol(25,40);
    printf("%c", ANGLE_HG);
    gotoligcol(25,105);
    printf("%c", ANGLE_HD);
    gotoligcol(34,105);
    printf("%c", ANGLE_BD);
    gotoligcol(34,40);
    printf("%c", ANGLE_BG);

    gotoligcol(27,64);
    Couleur(rougeFonce,CouleurFond);
    printf("COMMANDES DU JEU");
    Couleur(CouleurTexte,CouleurFond);

    gotoligcol(30,45);
    printf("Entree  %c  Fleches directionnnelles   %c  Espace  %c  Esc", BAR_V, BAR_V, BAR_V);


    ///AFFICHAGE MENU
    Couleur(CouleurTexte,CouleurFond);

    ///LIGNES HORIZONTALES
    for(i = 40; i < 105; i++)
    {
        gotoligcol(10,i);
        printf("%c", BAR_H);

        gotoligcol(23,i);
        printf("%c", BAR_H);
    }

    ///LIGNES VERTICALES
    for (i = 10; i < 23; i++)
    {
        gotoligcol(i,40);
        printf("%c", BAR_V);

        gotoligcol(i,105);
        printf("%c", BAR_V);
    }

    ///AFFICHAGE ANGLES
    gotoligcol(10,40);
    printf("%c", ANGLE_HG);
    gotoligcol(10,105);
    printf("%c", ANGLE_HD);
    gotoligcol(23,40);
    printf("%c", ANGLE_BG);
    gotoligcol(23,105);
    printf("%c", ANGLE_BD);
    gotoligcol(11, 65);
    Couleur(rougeFonce,CouleurFond);
    printf("Bataille Navale");
    Couleur(CouleurTexte,CouleurFond);

    gotoligcol(12,63);
    for (i = 0; i < 19; i++)
    {
        printf("%c", BAR_H);
    }

    gotoligcol(15,55);
    printf("Jouer une partie contre l'ordinateur");
    gotoligcol(17,55);
    printf("Charger une partie");
    gotoligcol(19,55);
    printf("Aide");
    gotoligcol(21,55);
    printf("Quitter");

    gotoligcol(x,y);
    printf("%c", FLECHE);

    ///CURSEUR
    do
    {
        do
        {
            toucheMenu = getch();
        }while((toucheMenu!=FLECHE_BAS)&&(toucheMenu!=FLECHE_HAUT)&&(toucheMenu!=ENTER));

        gotoligcol(x,y);
        printf(" ");

        switch(toucheMenu)
        {
            case FLECHE_BAS :

                if(x < 21)
                {
                    if(x+2 == 23)
                        y = 53;
                    if(x+2 == 21)
                        y = 53;
                    if(x+2 == 19)
                        y = 53;
                    if(x+2 == 17)
                        y = 53;

                    x = x + 2;
                    gotoligcol(x,y);
                    printf("%c", FLECHE);
                }
                else
                {
                    gotoligcol(x,y);
                    printf("%c", FLECHE);
                }

                break;

            case FLECHE_HAUT :

                if(x > 15)
                {
                    if(x-2 == 21)
                        y = 53;
                    if(x-2 == 19)
                        y = 53;
                    if(x-2 == 17)
                        y = 53;
                    if(x-2 == 15)
                        y = 53;

                    x = x - 2;
                    gotoligcol(x,y);
                    printf("%c", FLECHE);
                }
                else
                {
                    gotoligcol(x,y);
                    printf("%c", FLECHE);
                }
                break;
        }
    } while(toucheMenu!=ENTER);

    ///ACTION
    if(x == 15)
    {
        system("cls");
        jeu();
        actionJoueur();

        ///RETOUR MENU
        do
        {
            toucheRetourMenu = getch();
        } while(toucheRetourMenu != ESC);

        system("cls");
        menu();
    }
    else
    {
        if(x == 17)
        {
            system("cls");
            //Charger une partie

            ///RETOUR MENU
            do
            {
                toucheRetourMenu = getch();
            } while(toucheRetourMenu != ESC);

            system("cls");
            menu();
        }
        else
        {
            if(x == 19)
            {
                system("cls");
                aide(); //Aide (règles du jeu et touches clavier)

                ///RETOUR MENU
                do
                {
                    toucheRetourMenu = getch();
                } while(toucheRetourMenu != ESC);

                system("cls");
                menu();
            }
            else
            {
                if(x == 21)
                {
                    system("cls");

                    ///Quitter le programme
                    finPartie();
                    exit (0);
                }
            }
        }
    }
}



