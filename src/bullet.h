/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:    bullet.h
 * Enhetsnamn: bullet
 * Typ:         Klassdeklaration
 * Skriven av:  Anton Gifvars, antgi546, 890917-1657
 * 				Margareta Vi, marvi154,  920809-0309
 * 				Madeleine Ardic, madar730, 930922-4245
 *              Niclas Granström, nicgr354, 900519-5376
 * Datum:       2014-12-17
 *
 * BESKRIVNING:
 *
 * Denna klass �r till f�r bullet, dvs skott som b�de alien och player anv�nder sig av.
 * Funktioner:
 *  - check_living: 	Kollar om bullet lever dvs ha life = 0,
 *  - get_dmg:			Retunerar antalet skada som bullet har.
 *  - hit: 				Konsekvensena som händer när bullet krockar med resterande klasser
 *
 *
 *  Subklasser:
 *  - bullet_mk1 : Default skottet som skapas när man börjar spela spelet.
 *  - bullet_mk2 : Det skot som skapas när player har tagit upp en power_up.
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

};
//////////////////////////////////////////

#endif /* BULLET_H_ */
