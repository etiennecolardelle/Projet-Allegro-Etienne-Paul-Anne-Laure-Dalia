#include "headers.h"

int jouer() {
    clear_bitmap(screen);
    // Load images
    jeu = load_bitmap("image/jeu/image_jeu.bmp", NULL);
    joueur = load_bitmap("image/jeu/joueur.bmp", NULL);
    objet = load_bitmap("image/jeu/steak.bmp", NULL);
    Objet2 = load_bitmap("image/jeu/salade.bmp", NULL);
    /*steakcuit = load_bitmap("image/jeu/steakcuit.bmp", NULL);*/
    POUBELLE = load_bitmap("image/jeu/poubelle.bmp", NULL);
    PLAQUE = load_bitmap("image/jeu/plaque.bmp", NULL);
    cuisinier = load_bitmap("image/jeu/cuisinier2.bmp", NULL);

    if (!jeu || !joueur || !objet) {
        allegro_message("Erreur lors du chargement de l'image !");
        return 1;
    }

    // Initialisation des positions des joueurs
    joueur1.pos_x = 150;
    joueur1.pos_y = 150;
    joueur2.pos_x = 550;
    joueur2.pos_y = 450;

    objet1.pos_x =  5; // Position initiale de l'objet
    objet1.pos_y = 50;
    objet1.tenu = 0; // L'objet n'est pas encore tenu par un joueur
    /*objet1.cooking_timer =0;
    objet1.cooked = 0;*/

    objet2.pos_x =  10; // Position initiale de l'objet
    objet2.pos_y = 430;
    objet2.tenu = 0; // L'objet n'est pas encore tenu par un joueur

    poubelle.pos_x = 300; // Position de la poubelle sur l'écran
    poubelle.pos_y = 400;

    plaque.pos_x = 370;
    plaque.pos_y = 150;



    while (!key[KEY_CAPSLOCK]) {
        clear_bitmap(page);
        blit(jeu, page, 0, 0, 0, 0, jeu->w, jeu->h);

        // Gestion du mouvement du joueur 1
        if (key[KEY_W] && key[KEY_D]) {
            joueur1.dx = 4;
            joueur1.dy = -4;
        } else if (key[KEY_W] && key[KEY_A]) {
            joueur1.dx = -4;
            joueur1.dy = -4;
        } else if (key[KEY_S] && key[KEY_D]) {
            joueur1.dx = 4;
            joueur1.dy = 4;
        } else if (key[KEY_S] && key[KEY_A]) {
            joueur1.dx = -4;
            joueur1.dy = 4;
        } else if (key[KEY_W]) {
            joueur1.dx = 0;
            joueur1.dy = -4;
        } else if (key[KEY_S]) {
            joueur1.dx = 0;
            joueur1.dy = 4;
        } else if (key[KEY_A]) {
            joueur1.dx = -4;
            joueur1.dy = 0;
        } else if (key[KEY_D]) {
            joueur1.dx = 4;
            joueur1.dy = 0;
        } else {
            joueur1.dx = 0;
            joueur1.dy = 0;
        }

        // Gestion du mouvement du joueur 2
        if (key[KEY_UP] && key[KEY_RIGHT]) {
            joueur2.dx = 4;
            joueur2.dy = -4;
        } else if (key[KEY_UP] && key[KEY_LEFT]) {
            joueur2.dx = -4;
            joueur2.dy = -4;
        } else if (key[KEY_DOWN] && key[KEY_RIGHT]) {
            joueur2.dx = 4;
            joueur2.dy = 4;
        } else if (key[KEY_DOWN] && key[KEY_LEFT]) {
            joueur2.dx = -4;
            joueur2.dy = 4;
        } else if (key[KEY_UP]) {
            joueur2.dx = 0;
            joueur2.dy = -4;
        } else if (key[KEY_DOWN]) {
            joueur2.dx = 0;
            joueur2.dy = 4;
        } else if (key[KEY_LEFT]) {
            joueur2.dx = -4;
            joueur2.dy = 0;
        } else if (key[KEY_RIGHT]) {
            joueur2.dx = 4;
            joueur2.dy = 0;
        } else {
            joueur2.dx = 0;
            joueur2.dy = 0;
        }

        // Gestion de la prise/lâcher de l'objet par les joueurs (touche C)
        if (key[KEY_C]) {
            if (!objet1.tenu) { // Si l'objet n'est pas tenu
                // Vérifier si un joueur est proche de l'objet
                if ((abs(joueur1.pos_x - objet1.pos_x) < 20 && abs(joueur1.pos_y - objet1.pos_y) < 20) ||
                    (abs(joueur2.pos_x - objet1.pos_x) < 20 && abs(joueur2.pos_y - objet1.pos_y) < 20)) {
                    objet1.tenu = 1; // L'objet est maintenant tenu
                }
            } else { // Si l'objet est tenu
                objet1.tenu = 0; // L'objet est maintenant lâché
                objet1.pos_x = joueur1.pos_x;
                objet1.pos_y = joueur1.pos_y;
            }
        }

        // Gestion de la prise/lâcher de l'objet par le joueur 2 (touche L)
        if (key[KEY_L]) {
            if (!objet1.tenu) { // Si l'objet n'est pas tenu
                // Vérifier si le joueur 2 est proche de l'objet
                if (abs(joueur2.pos_x - objet1.pos_x) < 20 && abs(joueur2.pos_y - objet1.pos_y) < 20) {
                    objet1.tenu = 1; // L'objet est maintenant tenu
                }
            } else { // Si l'objet est tenu
                objet1.tenu = 0; // L'objet est maintenant lâché
                objet1.pos_x = joueur2.pos_x;
                objet1.pos_y = joueur2.pos_y;
            }
        }

        if (key[KEY_C]) {
            if (!objet2.tenu) { // Si l'objet n'est pas tenu
                // Vérifier si le joueur 1 est proche de l'objet 2
                if (abs(joueur1.pos_x - objet2.pos_x) < 20 && abs(joueur1.pos_y - objet2.pos_y) < 20) {
                    objet2.tenu = 1; // L'objet est maintenant tenu
                }
            } else { // Si l'objet est tenu
                objet2.tenu = 0; // L'objet est maintenant lâché
                objet2.pos_x = joueur1.pos_x;
                objet2.pos_y = joueur1.pos_y;
            }
        }

        if (key[KEY_L]) {
            if (!objet2.tenu) { // Si l'objet n'est pas tenu
                // Vérifier si le joueur 2 est proche de l'objet 2
                if (abs(joueur2.pos_x - objet2.pos_x) < 20 && abs(joueur2.pos_y - objet2.pos_y) < 20) {
                    objet2.tenu = 1; // L'objet est maintenant tenu
                }
            } else { // Si l'objet est tenu
                objet2.tenu = 0; // L'objet est maintenant lâché
                objet2.pos_x = joueur2.pos_x;
                objet2.pos_y = joueur2.pos_y;
            }
        }

        if (objet1.tenu) {
            if (key[KEY_W]) objet1.pos_y -= 2; // Déplacer l'objet vers le haut
            if (key[KEY_S]) objet1.pos_y += 2; // Déplacer l'objet vers le bas
            if (key[KEY_A]) objet1.pos_x -= 2; // Déplacer l'objet vers la gauche
            if (key[KEY_D]) objet1.pos_x += 2; // Déplacer l'objet vers la droite
        }

        if (objet2.tenu) {
            if (key[KEY_W]) objet2.pos_y -= 2; // Déplacer l'objet 2 vers le haut
            if (key[KEY_S]) objet2.pos_y += 2; // Déplacer l'objet 2 vers le bas
            if (key[KEY_A]) objet2.pos_x -= 2; // Déplacer l'objet 2 vers la gauche
            if (key[KEY_D]) objet2.pos_x += 2; // Déplacer l'objet 2 vers la droite
        }


        if (key[KEY_C]) {
            if (objet1.tenu && abs(joueur1.pos_x - poubelle.pos_x) < 20 && abs(joueur1.pos_y - poubelle.pos_y) < 20) {
                objet1.tenu = 0; // L'objet est lâché
                objet1.pos_x = 5; // Retour à la position initiale
                objet1.pos_y = 50;
            }
        }

        if (key[KEY_C]) {
            if (objet2.tenu && abs(joueur1.pos_x - poubelle.pos_x) < 20 && abs(joueur1.pos_y - poubelle.pos_y) < 20) {
                objet2.tenu = 0; // L'objet est lâché
                objet2.pos_x = 10; // Retour à la position initiale
                objet2.pos_y = 530;
            }
        }

        if (key[KEY_L]) {
            if (objet1.tenu && abs(joueur2.pos_x - poubelle.pos_x) < 20 && abs(joueur2.pos_y - poubelle.pos_y) < 20) {
                objet1.tenu = 0; // L'objet est lâché
                objet1.pos_x = 5; // Retour à la position initiale
                objet1.pos_y = 50;
            }
        }

        if (key[KEY_L]) {
            if (objet2.tenu && abs(joueur2.pos_x - poubelle.pos_x) < 20 && abs(joueur2.pos_y - poubelle.pos_y) < 20) {
                objet2.tenu = 0; // L'objet est lâché
                objet2.pos_x = 10; // Retour à la position initiale
                objet2.pos_y = 530;
            }
        }

        /*if (!objet1.cooked && objet1.tenu && !objet1.pos_x > 20 && abs(joueur1.pos_x - plaque.pos_x) < 20 && abs(joueur1.pos_y - plaque.pos_y) < 20) {
            // Si oui, commencer le compte à rebours de cuisson
            objet1.cooking_timer = 50; // 50 * 100 ms = 5 s
        }

        if (objet1.cooking_timer > 0) {
            objet1.cooking_timer--;
        }

        // Si le compte à rebours atteint zéro, l'objet est cuit
        if (objet1.cooking_timer == 0 && !objet1.cooked) {
            objet1.cooked = 1; // L'objet est maintenant cuit
            objet = steakcuit; // Remplacer l'objet par sa version cuite
        }*/

        // Mise à jour des positions des joueurs
        joueur1.pos_x += joueur1.dx;
        joueur1.pos_y += joueur1.dy;
        joueur2.pos_x += joueur2.dx;
        joueur2.pos_y += joueur2.dy;

        // Vérification et ajustement des positions pour rester dans les limites de l'écran
        if (joueur1.pos_x < 0) joueur1.pos_x = 0;
        if (joueur1.pos_x > LARGEUR_ECRAN - joueur->w) joueur1.pos_x = LARGEUR_ECRAN - joueur->w;
        if (joueur1.pos_y < 0) joueur1.pos_y = 0;
        if (joueur1.pos_y > HAUTEUR_ECRAN - joueur->h) joueur1.pos_y = HAUTEUR_ECRAN - joueur->h;

        if (joueur2.pos_x < 0) joueur2.pos_x = 0;
        if (joueur2.pos_x > LARGEUR_ECRAN - joueur->w) joueur2.pos_x = LARGEUR_ECRAN - joueur->w;
        if (joueur2.pos_y < 0) joueur2.pos_y = 0;
        if (joueur2.pos_y > HAUTEUR_ECRAN - joueur->h) joueur2.pos_y = HAUTEUR_ECRAN - joueur->h;

        // Affichage des joueurs
        draw_sprite(page, PLAQUE, plaque.pos_x, plaque.pos_y);
        draw_sprite(page, POUBELLE, poubelle.pos_x, poubelle.pos_y);
        draw_sprite(page, joueur, joueur1.pos_x, joueur1.pos_y);
        textout_ex(page, font, joueur1.pseudo, joueur1.pos_x, joueur1.pos_y - 20, makecol(0, 0, 0), -1);
        draw_sprite(page, cuisinier, joueur2.pos_x, joueur2.pos_y);
        textout_ex(page, font, joueur2.pseudo, joueur2.pos_x, joueur2.pos_y - 20, makecol(0, 0, 0), -1);

        if (!objet1.tenu) {
            // Dessiner l'objet à sa position initiale s'il n'est pas tenu
            draw_sprite(page, objet, objet1.pos_x, objet1.pos_y);
        } else {
            // Dessiner l'objet sur le joueur qui le tient
            if ((abs(joueur1.pos_x - objet1.pos_x) < 20 && abs(joueur1.pos_y - objet1.pos_y) < 20)) {
                draw_sprite(page, objet, joueur1.pos_x, joueur1.pos_y);
            } else {
                draw_sprite(page, objet, joueur2.pos_x, joueur2.pos_y);
            }
        }

        if (!objet2.tenu) {
            // Dessiner l'objet à sa position initiale s'il n'est pas tenu
            draw_sprite(page, Objet2, objet2.pos_x, objet2.pos_y);
        } else {
            // Dessiner l'objet sur le joueur qui le tient
            if ((abs(joueur1.pos_x - objet1.pos_x) < 20 && abs(joueur1.pos_y - objet1.pos_y) < 20)) {
                draw_sprite(page, Objet2, joueur1.pos_x, joueur1.pos_y);
            } else {
                draw_sprite(page, Objet2, joueur2.pos_x, joueur2.pos_y);
            }
        }

        // Affichage sur l'écran
        blit(page, screen, 0, 0, 0, 0, LARGEUR_ECRAN, HAUTEUR_ECRAN);

        rest(10);

    }
    destroy_bitmap(objet);
    destroy_bitmap(steakcuit);
    destroy_bitmap(Objet2);

    return 0;
}




