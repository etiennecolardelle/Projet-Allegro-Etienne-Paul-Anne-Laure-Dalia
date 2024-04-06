
#ifndef PROJET_ECECOOK_HEADERS_H
#define PROJET_ECECOOK_HEADERS_H

#include <allegro.h>
#include <stdio.h>

#define LARGEUR_ECRAN 800
#define HAUTEUR_ECRAN 600

BITMAP *page;
BITMAP *image_menu;
BITMAP *image1_menu;
BITMAP *image2_menu;
BITMAP *image3_menu;
BITMAP *image4_menu;
BITMAP *image5_menu;
BITMAP *jeu;
BITMAP *joueur;




typedef struct {
    char *nomSource;  // nom du fichier image contenant la s�quence
    int nimg;        // nombre d'images dans la s�quence
    int tx,ty;       // largeur et hauteur des images de la s�quence
    char pseudo[50];
    int pos_x, pos_y;
    int dx, dy;
    int frame_counter;
    //enum Direction current_direction;
}Personnage;

Personnage joueur1;

void menu();
int jouer();
void commandes();

#endif //PROJET_ECECOOK_HEADERS_H
