#include <allegro.h>

#define LARGEUR_ECRAN 800
#define HAUTEUR_ECRAN 600

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
