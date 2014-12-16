/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:         menu.h
 * Enhetsnamn:      menu
 * Typ:             Klassdeklaration
 * Programmerare:   Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *                  Kerstin Soderqvist 911006-0309 Y3.c kerso255
 * Datum:           2014-12-xx
 *
 * BESKRIVNING
 *
 * Filen innehåller deklarationer för klassen menu.
 * Denna klass har hand om menyn, vilken är det första som visas när vi kör programmet.
 * I menyn kan man välja att spela spelet, visa highscore, se hjälpinstruktioner eller avsluta spelet.
 * Med andra ord är det den som knyter ihop de andra klasserna och anropandet av deras funktioner.
 */

#ifndef MENU_H
#define MENU_H

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <string>
#include <vector>
#include "render.h"
#include "space_invader.h"
#include "highscore.h"
#include "help.h"

class menu
{
public:
    menu()=default;
    ~menu()=default;

    void set_renderer(render*);
    void set_play(space_invader*);
    void set_highscore(highscore*);
    void set_help(help*);
    void run();


private:
    int selected_item {0};

    render* renderer;
    space_invader* si{nullptr};
    highscore* hs;
    help* h;

    void render_menu();
};

/*
 * SLUT PÅ FILEN menu.h
 */

#endif // MENU_H
