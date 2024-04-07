#include "headers.h"

int RegleDuJeu() {
    clear_bitmap(screen);
// Load images
    while (!key[KEY_CAPSLOCK]) {
        regle = load_bitmap("image/jeu/regles.bmp", NULL);
        if (!regle) {
            allegro_message("Erreur lors du chargement de l'image des regle !");
            return 1;
        }

        //clear_bitmap(screen);
        blit(regle, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
}

int quitter(){
    allegro_exit();
}