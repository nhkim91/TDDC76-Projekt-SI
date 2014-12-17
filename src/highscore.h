/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:         highscore.h
 * Enhetsnamn:      highscore
 * Typ:             Klassdeklaration
 * Programmerare:   Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *                  Kerstin Soderqvist 911006-0309 Y3.c kerso255
 * Datum:           2014-12-17
 *
 * BESKRIVNING
 *
 * Filen innehåller deklarationer för klassen highscore.
 * Den har som uppgift att ha hand om highscore sedan tidigare spelade spel,
 * ladda in och visa highscore på skärmen, samt att då poängen, vid avslutat spel,
 * kvalificerar sig för highscore-listan, spara över detta till listan.
 *
 * Funktioner:
 * - save_score: Sparar poängen i highscore.
 * - show_highscore: Visar highscore.
 * - set_renderer: Sätter en pekare till renderaren.
 * - load: Laddar in highscore.
 * - write: Skriver highscore till fil.
 * - enter_name: Tar in knapptryckningar från tangentbordet.
 */

#ifndef HIGHSCORE_H
#define HIGHSCORE_H

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#include <string>
#include <vector>
#include "render.h"

class highscore
{
public:
    highscore() = default;
    ~highscore() = default;

    highscore(const highscore&) = default;

    void save_score(int);
    void show_highscore();
    void set_renderer(render*);

private:
    struct highscore_element
    {
        std::string name;
        int score;
    };

    render* renderer;
    std::vector<highscore_element> list_of_score;
    bool run;

    void load();
    void write();
    std::string enter_name();
};

/*
 * SLUT PÅ FILEN highscore.h
 */

#endif // HIGHSCORE_H
