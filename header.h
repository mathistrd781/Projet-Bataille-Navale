//
// Created by mathi on 14/11/2022.
//

#ifndef PROJET_BATAILLE_NAVALE_HEADER_H
#define PROJET_BATAILLE_NAVALE_HEADER_H


///Bibliotèques
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


///Define pour Couleurs
#define noir 0
#define bleuFonce 1
#define vertFonce 2
#define bleuClair 3
#define rougeFonce 4
#define violet 5
#define vertCacadoie 6
#define grisClair 7
#define grisFonce 8
#define bleuFluo 9
#define vertFluo 10
#define turquoise 11
#define rougeFluo 12
#define rose 13
#define jaune 14
#define blanc 15

#define CouleurTexte 6
#define CouleurFond 0


///Define Table ASCII/ANSI
#define ENTER 13
#define FLECHE 0x1A
#define V 86
#define v 118
#define ESC 27
#define BAR_H 196
#define BAR_V 179
#define ANGLE_HG 218
#define ANGLE_HD 191
#define ANGLE_BG 192
#define ANGLE_BD 217
#define CROIX 197
#define INTER_HAUT 193
#define FLECHE_BAS 80
#define FLECHE_HAUT 72
#define FLECHE_DROITE 77
#define FLECHE_GAUCHE 75
#define SPACE 32
#define Rond 7


///Define pour Plateau
#define SIZE_TAB 15
#define HAUTEUR 15
#define LARGEUR 15
#define HAUTEUR_SQUELETTE (HAUTEUR*2)
#define LARGEUR_SQUELETTE (LARGEUR*2)

#define GET_LETTER(x) ('a' + (x/2 -1))
#define GET_NUMBER(x) (x/2)
#define GET_CELL(tab, i, j) (tab[i/2][j/2])

#define IS_PAIR(x) (!(x%2))
#define IS_IMPAIR(x) (!IS_PAIR(x))
#define IS_1_DIGIT(x) (x < 10)


///Define pour placement
#define N_DIR 4
#define EMPTY_CELL

#define SIZE_SOUS_MARIN 2
#define SIZE_PORTE_AVION 7
#define SIZE_DESTROYER 3
#define SIZE_CROISEUR 5

#define NOMBRE_SOUS_MARIN 4
#define NOMBRE_PORTE_AVION 1
#define NOMBRE_DESTROYER 2
#define NOMBRE_CROISEUR 3
#define EMPTY_CELL ' '



///Source campus
void gotoligcol(int lig, int col);
void Couleur(int texte, int fond);
void hide_cursor(int visible);


///Presentation et menu
void presentation();
void menu(char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi);


///Jeu
void jeu(int choixDifficulte, char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi);
void actionJoueur(int choixDifficulte, char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi);
char ** genererPlateau(int hauteur, int largeur);
void affichagePlateau(char ** tableau, int x_initial, int y_initial);
void freePlateau(char ** plateau, int height);
void tir(int choixDifficulte, char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi);
void chargerPartie(char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi);
void deplacerBateau(char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi);
void afficheJoueur ();
void affichagePlateauJoueur (char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi);
void vider_Plateau (char ** plateau_bateau);
void boucle_de_jeu (int choixDifficulte, char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi);
void Eclairage(char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi);
void heure();
void chronometre ();




///IA
int choixIA ();
void IA (int choixdificulte, char ** plateau_bateau, char ** plateau_tirs, char ** plateau_ennemi);
void IA1(char ** plateau_bateau);
void IA2(char ** plateau_bateau);
void IA3(char ** plateau_bateau);


//unsigned int getSizeBateau(e_type_bateau type);
//int iterPosDirection(e_direction direction, t_coord *pos) ;
//void placementBateau(char **tableau_bateau, e_type_bateau type_bateau);


///Aide
void aide();


///Sauvegarde et fin de partie
void finPartie();


///Structures
typedef struct coordTab {
    unsigned short int x;
    unsigned short int y;
}coord_t;

typedef enum type_bateau {
    SOUS_MARIN = 0,
    PORTE_AVION,
    DESTROYER,
    CROISEUR
}e_type_bateau;


typedef enum direction {
    HAUT = 0,
    BAS,
    GAUCHE,
    DROITE
}e_direction;


typedef struct coordBateau {
    unsigned int x;
    unsigned int y;
}t_coord;


typedef struct bateau {
    t_coord pos;
    e_type_bateau type;
    unsigned int size;
    e_direction direction;
    char symbole;
}t_bateau;


unsigned int getSizeBateau(e_type_bateau type);
int iterPosDirection(e_direction direction, t_coord *pos) ;
void placementBateau(char **tableau_bateau, e_type_bateau type_bateau);

#endif //PROJET_BATAILLE_NAVALE_HEADER_H










