#include "header.h"


int main()
{

    srand(time(NULL));

    char ** plateau_bateau = genererPlateau(HAUTEUR, LARGEUR);
    char ** plateau_tirs = genererPlateau(HAUTEUR, LARGEUR);
    char ** plateau_ennemi = genererPlateau(HAUTEUR, LARGEUR);


    hide_cursor(0);
    //presentation();
    menu(plateau_bateau, plateau_tirs, plateau_ennemi);

    freePlateau(plateau_bateau, HAUTEUR);
    freePlateau(plateau_tirs, HAUTEUR);
    freePlateau(plateau_ennemi, HAUTEUR);

    return 0;
}
