/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     meteorite.h
 * Enhetsnamn:  meteorite
 * Typ:         Klassdeklaration
 * Skriven av:  Anton Gifvars, antgi546, 890917-1657
 * 				Margareta Vi, marvi154,  920809-0309
 * 				Madeleine Ardic, madar730, 930922-4245
 *              Niclas Granström, nicgr354, 900519-5376
 *
 * Datum:       2014-12-17
 *
 * BESKRIVNING:
 * Klassen innehåller två allmänna funktioner och två underklasser.
 * Funktioner:
 * - check_living: Reducerar meteorites liv med mängden damage som följer med och kollar därefter om den fortfarande lever.
 * 	 Dör de kontrolleras det om poäng ska delas ut till player, dvs om det var player som dödade den. Detta händer
 * 	 inte om tex en annan meteorit eller en alien åker in i meteoriten.
 * - hit: Genomför konsekvenser för om bullet träffar en bullet (check_living) eller om den träffar en power_up (åker rakt igenom).
 *
 * Underklasser:
 * - meteorite_small: konstruktorn skapas i h filen och bild samt mängd poäng tilldelas i cpp filen.
 * - meteorite_medium: konstruktorn skapas i h filen och bild samt mängd poäng tilldelas i cpp filen.
 */

#ifndef METEORITE_H_
#define METEORITE_H_

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */
#include "flying_objects.h"

class meteorite : public flying_objects
{

public:
    // Konstruktor
    meteorite(int, int, int, int, int, SDL_Renderer*);
    meteorite();

    // Destruktor
    ~meteorite() = default;

    // Funktioner

    bool check_living(int, bool);
    bool hit(flying_objects&)  override;
};

////////////////////////////////////////////////////////////////
class meteorite_small : public meteorite
{
public:
    // Konstruktor
    meteorite_small(int, int, int, int, int, SDL_Renderer*);
};

////////////////////////////////////////////////////////////////
class meteorite_medium : public meteorite
{
public:
    // Konstruktor
    meteorite_medium(int, int, int, int, int, SDL_Renderer*);
};
///////////////////////////////////////////////////////////////
#endif /* METEORITE_H_ */
