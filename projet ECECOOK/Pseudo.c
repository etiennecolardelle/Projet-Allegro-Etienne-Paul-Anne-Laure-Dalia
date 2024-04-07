#include "headers.h"

int Pseudo() {
    // Initialisation des pseudos
    char pseudoJoueur1[100] = "";
    char pseudoJoueur2[100] = "";

    // Load images
    pseudo = load_bitmap("image/jeu/pseudo.bmp", NULL);
    if (!pseudo) {
        allegro_message("Erreur lors du chargement de l'image des pseudos !");
        return 1;
    }

    clear_bitmap(screen);
    blit(pseudo, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    // Demander les pseudos aux joueurs
    textout_ex(screen, font, "Entrez le pseudo du joueur 1:", 80, 200, makecol(0, 0, 0), -1);
    textout_ex(screen, font, "Entrez le pseudo du joueur 2:", 450, 200, makecol(0, 0, 0), -1);

    int key;
    int index1 = 0;
    int index2 = 0;
    int player = 1; // Indicateur du joueur en train de saisir son pseudo

    do {
        if (keypressed()) {
            key = readkey();

            // Récupérer les entrées clavier pour les pseudos
            if (key >> 8 != KEY_ENTER) {
                if (key >> 8 != KEY_BACKSPACE) {
                    if (player == 1 && index1 < 99) {
                        if (key >> 8 == KEY_SPACE) {
                            pseudoJoueur1[index1++] = ' ';
                        } else {
                            pseudoJoueur1[index1++] = (char)key;
                        }
                        pseudoJoueur1[index1] = '\0';
                    } else if (player == 2 && index2 < 99) {
                        if (key >> 8 == KEY_SPACE) {
                            pseudoJoueur2[index2++] = ' ';
                        } else {
                            pseudoJoueur2[index2++] = (char)key;
                        }
                        pseudoJoueur2[index2] = '\0';
                    }
                } else if (player == 1 && index1 > 0) {
                    index1--;
                    pseudoJoueur1[index1] = '\0';
                } else if (player == 2 && index2 > 0) {
                    index2--;
                    pseudoJoueur2[index2] = '\0';
                }

                // Afficher les pseudos entrés
                clear_bitmap(screen);
                blit(pseudo, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                textout_ex(screen, font, "Entrez le pseudo du joueur 1:", 80, 200, makecol(0, 0, 0), -1);
                textout_ex(screen, font, "Entrez le pseudo du joueur 2:", 450, 200, makecol(0, 0, 0), -1);
                textout_ex(screen, font, pseudoJoueur1, 80, 220, makecol(0, 0, 0), -1);
                textout_ex(screen, font, pseudoJoueur2, 450, 220, makecol(0, 0, 0), -1);
            }

            // Passer au joueur suivant après avoir appuyé sur la touche Espace
            if (key >> 8 == KEY_SPACE) {
                player = 2;
            }
        }
    } while (!((key >> 8 == KEY_ENTER) && (index1 > 0) && (index2 > 0)));

    strcpy(joueur1.pseudo, pseudoJoueur1);
    strcpy(joueur2.pseudo, pseudoJoueur2);

    // Lancer le jeu après avoir saisi les pseudos
    clear_bitmap(screen);
    blit(screen, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);  // Effacer l'écran

    // Appeler la fonction deplacement
    jouer();

    return 0;  // Indiquer que le jeu a été lancé avec succès
}

