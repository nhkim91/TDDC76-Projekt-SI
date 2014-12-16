/*
 * IDA Programvaruproduktion AB (u.p.a.)
 *
 * IDENTIFIERING
 *
 * Filnamn:    meteorite.h
 * Enhetsnamn: meteorite
 * Typ:        ---------------
 * Revision:
 * Skriven av: Anton, Margareta, Madeleine
 *
 *
 * BESKRIVNING
 *
 *
 * REVISIONSBERÄTTELSE
 *
 * Revision     Datum   Förändringar
 *
 * 1            940319  Ursprungsversion
 * 1.1          940407  ...
 * ...
 * 2.0          940821  ...
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
    // Datamedlemmar

    // Konstruktor
    meteorite(int, int, int, int, int, SDL_Renderer*);
    meteorite();

    // Destruktor
    ~meteorite()=default;

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

