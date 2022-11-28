cmake_minimum_required(VERSION 3.23)
project(Projet_Bataille_Navale C)

set(CMAKE_C_STANDARD 23)

add_executable(Projet_Bataille_Navale main.c header.h Couleur.c Curseur.c Presentation.c Menu.c Jeu.c Aide.c placementBateau.c Plateau.c Tir.c Fusee.c Deplacement.c Sauvegarde.c ActionJoueur.c FindePartie.c)
