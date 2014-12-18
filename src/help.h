/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:         help.h
 * Enhetsnamn:      help
 * Typ:             Klassdeklaration
 * Skriven av:      Kim Nguyen Hoang, kimng797, 910112-0260
 *                  Kerstin Soderqvist, kerso255, 911006-0309
 *                  Niclas Granström, nicgr354, 900519-5376
 *                  Anton Gifvars, antgi546, 890917-1657
 *
 * Datum:           2014-12-17
 *
 * BESKRIVNING
 *
 * Filen innehåller deklarationer för klassen help, som har som uppgift
 * att innehålla och framföra information om hur man spelar spelet.
 *
 * Funktioner:
 * - show_help: Visar hjälptext.
 * - set_renderer: Sätter pekare till renderare.
 *
 */

#ifndef HELP_H
#define HELP_H

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#include "render.h"

class help
{
public:
    help() = default;
    ~help() = default;

    void show_help();
    void set_renderer(render*);

private:
    render* renderer;
};

/*
 * SLUT PÅ FILEN help.h
 */

#endif // HELP_H
