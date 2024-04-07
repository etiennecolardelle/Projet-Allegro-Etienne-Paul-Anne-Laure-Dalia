#include "headers.h"

int chargementniveau() {
// Load images
    niveau = load_bitmap("image/NIVEAU/niveau.bmp", NULL);
    niveau1 = load_bitmap("image/NIVEAU/niveau1.bmp", NULL);
    niveau2 = load_bitmap("image/NIVEAU/niveau2.bmp", NULL);
    niveau3 = load_bitmap("image/NIVEAU/niveau3.bmp", NULL);

    if (!niveau) {
        allegro_message("Erreur lors du chargement de l'image des pseudos !");
        return 1;
    }

    // Affichage du curseur de la souris
    show_mouse(screen);

    while (!key[KEY_ESC]) {
        // Vérification si la souris est sur la case "Jouer"
        clear_bitmap(page);
        blit(niveau, page, 0, 0, 0, 0, niveau->w, niveau->h);

        if (mouse_x >= 35 && mouse_x <= 186 &&
            mouse_y >= 266 && mouse_y <= 366) {
                draw_sprite(page, niveau1, 0, 0);
            if (mouse_b) {
                Niveau1();
            }

        } else if (mouse_x >= 185 && mouse_x <= 316 &&
                   mouse_y >= 498 && mouse_y <= 606) {
            draw_sprite(page, niveau2, 0, 0);
            if (mouse_b) {
                Niveau2();
            }


        } else if (mouse_x >= 654 && mouse_x <= 798 &&
                   mouse_y >= 263 && mouse_y <= 370) {
            draw_sprite(page, niveau3, 0, 0);
            if (mouse_b) {
                Niveau3();
            }

        }
            // Rafraîchir l'écran
            // blit(screen, page, 0, 0, 0, 0, LARGEUR_ECRAN, HAUTEUR_ECRAN);

            blit(page, screen, 0, 0, 0, 0, LARGEUR_ECRAN, HAUTEUR_ECRAN);

    }
    // Nettoyage
    destroy_bitmap(page);
    destroy_bitmap(niveau);

    allegro_exit();
}