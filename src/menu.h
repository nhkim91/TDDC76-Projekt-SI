/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:         menu.h
 * Enhetsnamn:      menu
 * Typ:             Klassdeklaration
 * Programmerare:   Kim Nguyen Hoang, kimng797, 910112-0260
 *                  Kerstin Soderqvist, kerso255, 911006-0309
 *                  Niclas Granström, nicgr354, 900519-5376
 *                  Anton Gifvars, antgi546, 890917-1657
 *
 * Datum:           2014-12-17
 *
 * BESKRIVNING
 *
 * Filen innehåller deklarationer för klassen menu.
 * Denna klass har hand om menyn, vilken är det första som visas när vi kör programmet.
 * I menyn kan man välja att spela spelet, visa highscore, se hjälpinstruktioner eller avsluta spelet.
 * Med andra ord är det den som knyter ihop de andra klasserna och anropandet av deras funktioner.
 *
 * Funktioner:
 * - set_renderer: Sätter pekare till renderare.
 * - set_play: Sätter pekare till space_invader.
 * - set_highscore: Sätter pekare till highscore.
 * - set_help: Sätter pekare till help.
 * - set_sound: Sätter pekare till sound.
 * - run: Körfunktion.
 * - set_screen_size: Sätter bredden och höjden på spelplanen.
 * - render_menu: Renderar meny.
 *
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
#include "render.h"
#include "space_invader.h"
#include "highscore.h"
#include "help.h"

class menu
{
public:
    menu() = default;
    ~menu() = default;

    void set_renderer(render*);
    void set_play(space_invader*);
    void set_highscore(highscore*);
    void set_help(help*);
    void set_sound(sound*);
    void run();
    void set_screen_size(int, int);


private:
    int selected_item {0};
    int screen_width;
    int screen_height;


    render* renderer;
    space_invader* si {nullptr};
    highscore* hs;
    help* h;
    sound* snd;

    void render_menu();
};

/*
 * SLUT PÅ FILEN menu.h
 */

#endif // MENU_H
