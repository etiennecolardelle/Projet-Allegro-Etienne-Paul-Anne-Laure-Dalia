#include "Header.h"
#include <stdio.h>
#include <allegro.h>
#include <stdbool.h>

void deplacement(BITMAP *page) {
    int x1g = 50, x1d = 200;
    int y1h = 50, y1b = 200;
    int x2g = 400, x2d = 550;
    int y2h = 300, y2b = 450;

    int couleur1, couleur2;
    page = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(page);
    show_mouse(screen);

    while (!key[KEY_ESC]) {
        clear_bitmap(page);

        int moveX1 = 0, moveY1 = 0;

        if (key[KEY_W]) moveY1 -= 5;
        if (key[KEY_A]) moveY1 += 5;
        if (key[KEY_S]) moveX1 -= 5;
        if (key[KEY_D]) moveX1 += 5;

        // Vérification des limites de l'écran pour le premier carré
        if (x1g + moveX1 >= 0 && x1d + moveX1 <= SCREEN_W && y1h + moveY1 >= 0 && y1b + moveY1 <= SCREEN_H) {
            x1g += moveX1;
            x1d += moveX1;
            y1h += moveY1;
            y1b += moveY1;
        }

        int moveX2 = 0, moveY2 = 0;

        if (key[KEY_UP]) moveY2 -= 5;
        if (key[KEY_DOWN]) moveY2 += 5;
        if (key[KEY_LEFT]) moveX2 -= 5;
        if (key[KEY_RIGHT]) moveX2 += 5;

        // Vérification des limites de l'écran pour le deuxième carré
        if (x2g + moveX2 >= 0 && x2d + moveX2 <= SCREEN_W && y2h + moveY2 >= 0 && y2b + moveY2 <= SCREEN_H) {
            x2g += moveX2;
            x2d += moveX2;
            y2h += moveY2;
            y2b += moveY2;
        }

        if (x1g <= x2d && x2g <= x1d && y1h <= y2b && y2h <= y1b) {
            couleur1 = makecol(255, 0, 0);
            couleur2 = makecol(255, 0, 0);
        } else {
            couleur1 = makecol(0, 255, 255);
            couleur2 = makecol(0, 0, 255);
        }

        rectfill(page, x1g, y1h, x1d, y1b, couleur1);
        rectfill(page, x2g, y2h, x2d, y2b, couleur2);

        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        rest(10);
    }
}