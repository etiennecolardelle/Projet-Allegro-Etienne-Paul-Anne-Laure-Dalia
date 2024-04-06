#include "headers.h"

int jouer(){
    clear_bitmap(page);

    // Load image
    jeu = load_bitmap("image/jeu/image_jeu.bmp", NULL);
    joueur = load_bitmap("image/jeu/joueur.bmp",NULL);
    if (!jeu) {
        allegro_message("Erreur lors du chargement de l'image !");
        return 1;
    }
joueur1.pos_x=LARGEUR_ECRAN/2;
joueur1.pos_y=HAUTEUR_ECRAN/2;

    while (!key[KEY_CAPSLOCK]){
        clear_bitmap(page);
        blit(jeu, page, 0, 0, 0, 0, jeu->w, jeu->h);

        if (key[KEY_W]) joueur1.dy+=1;
        else if (key[KEY_S]) joueur1.dy-=1;
        else if (key[KEY_A]) joueur1.dx-=1;
        else if (key[KEY_D]) joueur1.dx+=1;
        else joueur1.dx=0, joueur1.dy=0;

        joueur1.pos_x += joueur1.dx ;
        joueur1.pos_y += joueur1.dy ;
        draw_sprite(page,joueur,joueur1.pos_x,joueur1.pos_y);
        blit(page, screen, 0, 0, 0, 0, LARGEUR_ECRAN, HAUTEUR_ECRAN);

    }
}
