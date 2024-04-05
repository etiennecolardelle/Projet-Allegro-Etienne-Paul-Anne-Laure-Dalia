#include <allegro.h>

#define LARGEUR_ECRAN 800
#define HAUTEUR_ECRAN 600

BITMAP *page;
BITMAP *image;

int menu() {
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, LARGEUR_ECRAN, HAUTEUR_ECRAN, 0, 0);

    // double buffer
    page = create_bitmap(LARGEUR_ECRAN, HAUTEUR_ECRAN);

    // Image
    image = load_bitmap("", NULL);
    if (!image) {
        allegro_message("Erreur lors du chargement de l'image !");
        return 1;
    }

    // Formes
    rectfill(image, 100, 100, 200, 200, makecol(50, 30, 0));
    circlefill(image, 400, 300, 50, makecol(20, 0, 45));


    destroy_bitmap(page);
    destroy_bitmap(image);

    allegro_exit();
    return 0;
}
END_OF_MAIN()
