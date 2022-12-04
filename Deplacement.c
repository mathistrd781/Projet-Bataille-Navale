#include "header.h"


#include "header.h"



/*void condition_deplacement(char ** tableau_bateau,e_type_bateau type_bateau)
{

    bool mauvais_deplacement = false ;
    int j = 0;
    t_coord bateau_pos ;
    e_direction direction ;
    unsigned int size_bateau = getSizeBateau(type_bateau);
    do
    {
        t_coord it_pos_bateau = bateau_pos ;
        for(int i = 0;i<size_bateau ; i++)
        {
            if(iterPosDirection(direction,&it_pos_bateau) == -1)
            {
                mauvais_deplacement = true ;
            }
            if(tableau_bateau[it_pos_bateau.x][it_pos_bateau.y] != EMPTY_CELL)
            {
                mauvais_deplacement = true ;
            }
      }

    }while(mauvais_deplacement);

}*/
void Deplacement_bateau(char ** tableau_bateau,t_coord pos,e_type_bateau type)
{
    char toucheDeplacement = '0' ;
    t_coord bateau_pos ;
    int x = 5 , y = 86 ;
    e_direction direction ;
    t_coord it_bateau_pos = bateau_pos ;
    int size = getSizeBateau(type) ;

    do
    {
        toucheDeplacement = getch() ;
    }while((toucheDeplacement != FLECHE_BAS) && (toucheDeplacement != FLECHE_HAUT) && (toucheDeplacement != FLECHE_DROITE) && (toucheDeplacement != FLECHE_GAUCHE)&& (toucheDeplacement != P)&&(toucheDeplacement != D)) ;
    switch (toucheDeplacement)
    {
      /*  case D ://choisi le bateau à déplacer
            if(iterPosDirection(direction,&it_bateau_pos) == -1) {
                if (tableau_bateau[it_bateau_pos.x][it_bateau_pos.y] == EMPTY_CELL)
                {

                }
            }
            break ;*/
        case P ://place le bateau
            if(iterPosDirection(direction,&it_bateau_pos) == -1)
            {
                if (tableau_bateau[it_bateau_pos.x][it_bateau_pos.y] == EMPTY_CELL)
                {
                }
            }

        case FLECHE_BAS :
            for (int i = 0 ; i < size ; i++) {
                tableau_bateau[pos.x][pos.y+1] = getRepresentationBateau(type);
                iterPosDirection(direction, &pos);
            }
            break ;
        case FLECHE_HAUT  :
            for (int i = 0 ; i < size ; i++) {
                tableau_bateau[pos.x][pos.y-1] = getRepresentationBateau(type);
                iterPosDirection(direction, &pos);
            }
            break ;

        case FLECHE_DROITE :
            for (int i = 0 ; i < size ; i++) {
                tableau_bateau[pos.x+1][pos.y] = getRepresentationBateau(type);
                iterPosDirection(direction, &pos);
            }
            break ;

        case FLECHE_GAUCHE :
            for (int i = 0 ; i < size ; i++) {
                tableau_bateau[pos.x-1][pos.y] = getRepresentationBateau(type);
                iterPosDirection(direction, &pos);
            }
            break ;
    }
}
