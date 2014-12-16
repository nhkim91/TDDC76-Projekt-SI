/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:    bullet.h
 * Enhetsnamn: Bullet
 * Typ:         Klassdeklaration
 * Skriven av:  Anton Gifvars, antgi546, 890917-1657
 * 				Margareta Vi, marvi154,  920809-0309
 * 				Madeleine Ardic, madar730, 930922-4245
 * Datum:       2014-12-xx
 *
 * BESKRIVNING:
 *
 * Denna klass ‰r till fˆr bullet, dvs skott som b√•de alien och player anv‰nder sig av.
 * Funktioner:
 *  - get_life: h‰mtar livet pÂ bullet
 *  - check_living: kollar om bullet lever
 *  - movement: en vektor som sparar undan positionerningen i x- och y-led samt hastigheten i x- och y-led.
 *  - get_dmg: retunerar antalet skada som bullet har.
 *  - hit: konsekvensena som h√§nder n√§r bullet krockar med resterande klasser
 *
 *   InnehÂller ocks√• sub-klasserna bullet_mk1 som √§r default skottet, bullet_mk2 som f√•s genom en power up.
 *
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
