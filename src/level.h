/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:         level.h
 * Enhetsnamn:      level
 * Typ:             Klassdeklaration
 * Programmerare:   Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *                  Kerstin Soderqvist 911006-0309 Y3.c kerso255
 * Datum:           2014-12-xx
 *
 * BESKRIVNING
 *
 * Filen innehåller deklarationer för klassen level.
 * Den har som uppgift att hålla reda på vilken nivå spelet befinner sig på,
 * och vid behov höja nivån. Den har även funktionen spawn() som slumpmässigt
 * skapar nya objekt (aliens, meteoriter, power-ups), utifrån nivån,
 * vilka senare ska visas på spelplanen.
 */

#ifndef LEVEL_H
#define LEVEL_H

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#include "flying_objects.h"
#include "render.h"

class level
{
public:
    level() = delete;
    level(int, int, std::vector<flying_objects*>*, SDL_Renderer*);
    virtual ~level() = default;

    level(const level&) = default;

    void spawn(int);
    void set_renderer(render* rend);

private:
    int lvl{1};
    std::vector<int> data;
    std::vector<flying_objects*>* disp_objects_pointer;
    int width;
    int height;
    SDL_Renderer* renderer_;
    Uint32 latest_lvl_change_;
    Uint32 display_time_{2000};


    void get_next_lvl(int);

    //alien
    flying_objects* get_alien_mk1();
    flying_objects* get_alien_mk2();
    flying_objects* get_alien_mk3();

    //meteorite
    flying_objects* get_meteorite_small();
    flying_objects* get_meteorite_medium();

    //power_up
    flying_objects* get_power_up(int);

    render* rend_;
    SDL_Texture *renderText(const std::string &str, const std::string &fontFile,
                            SDL_Color color, int fontSize, SDL_Renderer *renderer);

};

/*
 * SLUT PÅ FILEN level.h
 */

#endif // LEVEL_H
