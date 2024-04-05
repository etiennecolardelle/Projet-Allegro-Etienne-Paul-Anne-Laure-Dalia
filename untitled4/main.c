#include <allegro.h>

#define LARGEUR_ECRAN 800
#define HAUTEUR_ECRAN 755

BITMAP *page;
BITMAP *image;

int main() {
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, LARGEUR_ECRAN, HAUTEUR_ECRAN, 0, 0);

    // Create bitmaps
    page = create_bitmap(LARGEUR_ECRAN, HAUTEUR_ECRAN);

    // Load image
    image = load_bitmap("menu.bmp", NULL);
    if (!image) {
        allegro_message("Erreur lors du chargement de l'image !");
        return 1;
    }

    // Draw shapes on the image

    rectfill(image, LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 - 80, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 - 40, makecol(255, 247, 218));
    rectfill(image, LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 - 20, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 + 20, makecol(254, 247, 218));
    rectfill(image, LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 + 40, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 + 80, makecol(254, 247, 218));
    rectfill(image, LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 + 100, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 + 140, makecol(254, 247, 218));

    textout_centre_ex(image, font, "Jouer", LARGEUR_ECRAN / 2, HAUTEUR_ECRAN / 2 - 60, makecol(0, 0, 0), -1);
    textout_centre_ex(image, font, "Niveau", LARGEUR_ECRAN / 2, HAUTEUR_ECRAN / 2 , makecol(0, 0, 0), -1);
    textout_centre_ex(image, font, "Règles du jeu", LARGEUR_ECRAN / 2, HAUTEUR_ECRAN / 2 + 60, makecol(0, 0, 0), -1);
    textout_centre_ex(image, font, "Quitter", LARGEUR_ECRAN / 2, HAUTEUR_ECRAN / 2 + 120, makecol(0, 0, 0), -1);

    // Show mouse cursor
    show_mouse(screen);

    // Blit the image onto the screen
    blit(image, screen, 0, 0, 0, 0, image->w, image->h);

    while (!key[KEY_ESC]) {
        // You can put any other logic here if needed
    }

    // Clean up
    destroy_bitmap(page);
    destroy_bitmap(image);

    allegro_exit();
    return 0;
}
END_OF_MAIN()

/*
#include <allegro.h>

#define LARGEUR_ECRAN 800
#define HAUTEUR_ECRAN 755

BITMAP *page;
BITMAP *image;

void highlight_box(int x1, int y1, int x2, int y2, int color) {
    rectfill(image, x1, y1, x2, y2, color);
}

int main() {
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, LARGEUR_ECRAN, HAUTEUR_ECRAN, 0, 0);

    // Create bitmaps
    page = create_bitmap(LARGEUR_ECRAN, HAUTEUR_ECRAN);

    // Load image
    image = load_bitmap("menu.bmp", NULL);
    if (!image) {
        allegro_message("Erreur lors du chargement de l'image !");
        return 1;
    }

    // Draw shapes on the image
    rectfill(image, LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 - 80, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 - 40, makecol(255, 247, 218));
    rectfill(image, LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 - 20, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 + 20, makecol(254, 247, 218));
    rectfill(image, LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 + 40, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 + 80, makecol(254, 247, 218));
    rectfill(image, LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 + 100, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 + 140, makecol(254, 247, 218));

    textout_centre_ex(image, font, "Jouer", LARGEUR_ECRAN / 2, HAUTEUR_ECRAN / 2 - 60, makecol(0, 0, 0), -1);
    textout_centre_ex(image, font, "Niveau", LARGEUR_ECRAN / 2, HAUTEUR_ECRAN / 2 , makecol(0, 0, 0), -1);
    textout_centre_ex(image, font, "Règles du jeu", LARGEUR_ECRAN / 2, HAUTEUR_ECRAN / 2 + 60, makecol(0, 0, 0), -1);
    textout_centre_ex(image, font, "Quitter", LARGEUR_ECRAN / 2, HAUTEUR_ECRAN / 2 + 120, makecol(0, 0, 0), -1);

    // Show mouse cursor
    show_mouse(screen);

    // Blit the image onto the screen
    blit(image, screen, 0, 0, 0, 0, image->w, image->h);

    while (!key[KEY_ESC]) {
        int mouse_x = mouse_x;
        int mouse_y = mouse_y;

        // Reset color of all rectangles
        rectfill(image, LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 - 80, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 - 40, makecol(255, 247, 218));
        rectfill(image, LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 - 20, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 + 20, makecol(254, 247, 218));
        rectfill(image, LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 + 40, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 + 80, makecol(254, 247, 218));
        rectfill(image, LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 + 100, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 + 140, makecol(254, 247, 218));

        // Highlight rectangle under mouse
        if (mouse_x >= LARGEUR_ECRAN / 2 - 60 && mouse_x <= LARGEUR_ECRAN / 2 + 60) {
            if (mouse_y >= HAUTEUR_ECRAN / 2 - 80 && mouse_y <= HAUTEUR_ECRAN / 2 - 40)
                highlight_box(LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 - 80, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 - 40, makecol(255, 255, 204));
            else if (mouse_y >= HAUTEUR_ECRAN / 2 - 20 && mouse_y <= HAUTEUR_ECRAN / 2 + 20)
                highlight_box(LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 - 20, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 + 20, makecol(255, 255, 204));
            else if (mouse_y >= HAUTEUR_ECRAN / 2 + 40 && mouse_y <= HAUTEUR_ECRAN / 2 + 80)
                highlight_box(LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 + 40, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 + 80, makecol(255, 255, 204));
            else if (mouse_y >= HAUTEUR_ECRAN / 2 + 100 && mouse_y <= HAUTEUR_ECRAN / 2 + 140)
                highlight_box(LARGEUR_ECRAN / 2 - 60, HAUTEUR_ECRAN / 2 + 100, LARGEUR_ECRAN / 2 + 60, HAUTEUR_ECRAN / 2 + 140, makecol(255, 255, 204));
        }

        // Blit the image onto the screen
        blit(image, screen, 0, 0, 0, 0, image->w, image->h);
    }

    // Clean up
    destroy_bitmap(page);
    destroy_bitmap(image);

    allegro_exit();
    return 0;
}
END_OF_MAIN()
*/
