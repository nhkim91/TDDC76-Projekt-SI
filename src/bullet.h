/*
 * IDA Programvaruproduktion AB (u.p.a.)
 *
 * IDENTIFIERING
 *
 * Filnamn:    bullet.h
 * Enhetsnamn: Bullet
 * Typ:        -----
 * Revision:   2.1
 * Skriven av: Anton, Margareta, Madeleine
 *
 *
 * BESKRIVNING
 *
 * Denna klass �r till f�r bullet, dvs skott som både alien och player anv�nder sig av.
 * Funktioner:
 *  - get_life: h�mtar livet p� bullet
 *  - check_living: kollar om bullet lever
 *  - movement: en vektor som sparar undan positionerningen i x- och y-led samt hastigheten i x- och y-led.
 *  - get_dmg: retunerar antalet skada som bullet har.
 *  - hit: konsekvensena som händer när bullet krockar med resterande klasser
 *
 *   Inneh�ller också sub-klasserna bullet_mk1 som är default skottet, bullet_mk2 som fås genom en power up.
 *
 * REVISIONSBER�TTELSE
 *
 * Revision     Datum   F�r�ndringar
 *
 * 1            940319  Ursprungsversion
 * 1.1          940407  ...
 * ...
 * 2.0          940821  ...
 */

#ifndef BULLET_H_
#define BULLET_H_

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */
#include "flying_objects.h"

class bullet : public flying_objects
{
public:
    // Datamedlemmar
    int dmg_;

    //Funktioner
    bool check_living(int);
    int get_dmg() const;
    bool hit(flying_objects&) override;

    // Konstruktor
    bullet(int, int, int, int, int, int, SDL_Renderer*);
    bullet();

    // Destruktor
    ~bullet() = default;
};
//////////////////////////////////////////
class bullet_mk1 : public bullet
{
public:
    // Konstruktor
    bullet_mk1(int, int, int, int, int, int, SDL_Renderer*);

    // Funktioner
};

//////////////////////////////////////////
class bullet_mk2 : public bullet
{
public:
    // Konstruktor
    bullet_mk2(int, int, int, int, int, int, SDL_Renderer*);


    // Funktioner
};
#endif /* BULLET_H_ */
