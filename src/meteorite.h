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
 * Datum:       2014-12-xx
 *
 * BESKRIVNING
 *
 * Funktioner:
 * - check_living:
 * - hit:
 *
 * Underklasser:
 * - meteorite_small:
 * - meteorite_medium:
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
