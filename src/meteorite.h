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
 *              Niclas Granstr�m, nicgr354, 900519-5376
 *
 * Datum:       2014-12-17
 *
 * BESKRIVNING:
 * Klassen inneh�ller tv� allm�nna funktioner och tv� underklasser.
 * Funktioner:
 * - check_living: Reducerar meteorites liv med m�ngden damage som f�ljer med och kollar d�refter om den fortfarande lever.
 * 	 D�r de kontrolleras det om po�ng ska delas ut till player, dvs om det var player som d�dade den. Detta h�nder
 * 	 inte om tex en annan meteorit eller en alien �ker in i meteoriten.
 * - hit: Genomf�r konsekvenser f�r om bullet tr�ffar en bullet (check_living) eller om den tr�ffar en power_up (�ker rakt igenom).
 *
 * Underklasser:
 * - meteorite_small: konstruktorn skapas i h filen och bild samt m�ngd po�ng tilldelas i cpp filen.
 * - meteorite_medium: konstruktorn skapas i h filen och bild samt m�ngd po�ng tilldelas i cpp filen.
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
