//
// Created by bllcp on 06/04/2024.
//

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
BITMAP *jeu;
BITMAP *joueur;
BITMAP *cuisinier;
BITMAP *pseudo;
BITMAP *regle;
BITMAP *niveau;
BITMAP *niveau1;
BITMAP *niveau2;
BITMAP *niveau3;
BITMAP *objet;
BITMAP *Objet2;
BITMAP *POUBELLE;
BITMAP *steakcuit;
BITMAP *PLAQUE;


typedef struct {
    char pseudo[50];
    int pos_x, pos_y;
    int dx, dy;
    int frame_counter;
    //enum Direction current_direction;
}Personnage;

Personnage joueur1;
Personnage joueur2;

typedef struct {
    int pos_x, pos_y;
    int dx, dy;
    int tenu; // 1 si tenu par un joueur sinon 0
    int cooking_timer;
    int cooked;
}Objet;

typedef struct {
    int pos_x;
    int pos_y;
} Poubelle;
Poubelle poubelle;

typedef struct {
    int pos_x;
    int pos_y;
} Plaque;
Plaque plaque;

Objet objet1;
Objet objet2;

void menu();
int jouer();
void commandes();
int quitter();
int Pseudo();
int RegleDuJeu();
int chargementniveau();
int Niveau1();
int Niveau2();
int Niveau3();

#endif //PROJET_ECECOOK_HEADERS_H
