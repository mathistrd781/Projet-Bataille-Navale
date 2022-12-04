#include "header.h"


void jeu(int choixDifficulte, char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi){

    vider_Plateau(plateau_bateau);
    vider_Plateau(plateau_tirs);
    vider_Plateau(plateau_ennemi);


    for (int i = 0; i < NOMBRE_SOUS_MARIN; i++)
    {
        placementBateau(plateau_bateau, SOUS_MARIN);
    }
    for (int i = 0; i < NOMBRE_DESTROYER; i++)
    {
        placementBateau(plateau_bateau, DESTROYER);
    }

    for(int i =0; i < NOMBRE_CROISEUR ; i++)
    {
        placementBateau(plateau_bateau, CROISEUR);
    }

    placementBateau(plateau_bateau, PORTE_AVION);


    for (int i = 0; i < NOMBRE_SOUS_MARIN; i++)
    {
        placementBateau(plateau_ennemi, SOUS_MARIN);
    }
    for (int i = 0; i < NOMBRE_DESTROYER; i++)
    {
        placementBateau(plateau_ennemi, DESTROYER);
    }

    for(int i =0; i < NOMBRE_CROISEUR ; i++)
    {
        placementBateau(plateau_ennemi, CROISEUR);
    }

    placementBateau(plateau_ennemi, PORTE_AVION);

    choixDifficulte = choixIA ();

    system("cls");
}

void boucle_de_jeu (int choixDifficulte, char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi)
{
    affichagePlateauJoueur (plateau_bateau, plateau_tirs, plateau_ennemi);

    actionJoueur(choixDifficulte, plateau_bateau, plateau_tirs, plateau_ennemi);

    IA (choixDifficulte, plateau_bateau, plateau_tirs, plateau_ennemi);

    sauvegardePartie(choixDifficulte, plateau_bateau,plateau_ennemi,plateau_tirs);
}
