#include "headers.h"

void menu() {
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, LARGEUR_ECRAN, HAUTEUR_ECRAN, 0, 0);

    // Create bitmaps
    page = create_bitmap(LARGEUR_ECRAN, HAUTEUR_ECRAN);
    image_menu = load_bitmap("image/menu/image_menu.bmp", NULL);
    image1_menu = load_bitmap("image/menu/jouer.bmp", NULL);
    image2_menu = load_bitmap("image/menu/niveau.bmp", NULL);
    image3_menu = load_bitmap("image/menu/regle_du_jeu.bmp", NULL);
    image4_menu = load_bitmap("image/menu/quitter.bmp", NULL);


    if (!image_menu) {
        allegro_message("Erreur lors du chargement de l'image !");
        return;
    }

    // Affichage du curseur de la souris
    show_mouse(screen);


    while (!key[KEY_ESC]) {
        // Vérification si la souris est sur la case "Jouer"
        clear_bitmap(page);
        blit(image_menu, page, 0, 0, 0, 0, image_menu->w, image_menu->h);

        if (mouse_x >= 253 && mouse_x <= 548 &&
            mouse_y >= 248 && mouse_y <= 297) {
            draw_sprite(page, image1_menu, 0, 0);
            if (mouse_b) { // Clic gauche détecté
                Pseudo();
            }


        } else if (mouse_x >= 253 && mouse_x <= 548 &&
                   mouse_y >= 322 && mouse_y <= 371) {
            draw_sprite(page, image2_menu, 0, 0);
            if (mouse_b) { // Clic gauche détecté
                chargementniveau();
            }

        } else if (mouse_x >= 253 && mouse_x <= 548 &&
                   mouse_y >= 397 && mouse_y <= 446) {
            draw_sprite(page, image3_menu, 0, 0);

            if (mouse_b) { // Clic gauche détecté
                RegleDuJeu();
            }

        } else if (mouse_x >= 253 && mouse_x <= 548 &&
                   mouse_y >= 472 && mouse_y <= 521) {
            draw_sprite(page, image4_menu, 0, 0);
            if (mouse_b) {
                quitter();
            }

        }

        // Rafraîchir l'écran
        // blit(screen, page, 0, 0, 0, 0, LARGEUR_ECRAN, HAUTEUR_ECRAN);
        blit(page, screen, 0, 0, 0, 0, LARGEUR_ECRAN, HAUTEUR_ECRAN);

    }
    // Nettoyage
    destroy_bitmap(page);
    destroy_bitmap(image_menu);

    allegro_exit();
}