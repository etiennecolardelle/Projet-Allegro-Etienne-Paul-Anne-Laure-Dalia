
#ifndef UNTITLED3_HEADER_H
#define UNTITLED3_HEADER_H

#include <stdio.h>
#include <allegro.h>
#include <stdbool.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
typedef struct {
    char pseudo[50];
    int score;
} Player;
typedef struct {
    int x;
    int y;
} Position;
typedef enum {
    INGREDIENT_BRUT,
    INGREDIENT_DECOUPE,
    INGREDIENT_CUIT
} IngredientType;
typedef struct {
    int id;
    char nom[50];
    IngredientType type;
    // Ajoutez d'autres données pertinentes sur l'ingrédient ici
} Ingredient;
typedef struct {
    int id;
    Ingredient ingredients[4]; // Maximum de 4 ingrédients par commande
    int nbIngredients;
    int tempsLimite; // Temps limite pour terminer la commande en secondes
    // Ajoutez d'autres données pertinentes sur la commande ici
} Commande;
typedef struct {
    int type; // Type de case (plan de travail, plaque de cuisson, etc.)
    Ingredient *ingredient; // Pointeur vers l'ingrédient sur cette case, NULL si vide
    // Ajoutez d'autres données pertinentes sur la case ici
} Cuisine;

void affichage_image();
void deplacement();

#endif //UNTITLED3_HEADER_H

