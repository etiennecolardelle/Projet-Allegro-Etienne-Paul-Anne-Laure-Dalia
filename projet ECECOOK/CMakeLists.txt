cmake_minimum_required(VERSION 3.26)
project(projet_ECECOOK C)

set(CMAKE_C_STANDARD 11)

add_executable(projet_ECECOOK main.c
        headers.h
        menu.c
        jouer.c
        commande.c
        Pseudo.c
        Pseudo.c
        RegleDuJeu.c
        niveau.c
        chagement_niveau.c)
target_link_libraries(projet_ECECOOK -lmingw32 -lalleg44)