/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     alien.h
 * Enhetsnamn:  alien
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
 * - alien_mk1:
 * - alien_mk2:
 * - alien_mk3:
 * 		+ Funktioner:
 * 		  - flying_objects* attack:
 *	 	  - int get_y_speed:
 *
 */
#ifndef ALIEN_H_
#define ALIEN_H_

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */
#include "flying_objects.h"

class alien : public flying_objects
{
public:
    // Konstruktor
    alien(int, int, int, int, int, SDL_Renderer*);
    alien();

    // Destruktor
    ~alien() = default;

    // Funktioner
    bool check_living(int, bool);
    bool hit(flying_objects&)  override;
};
////////////////////////////////////////////////////////////////

class alien_mk1 : public alien
{
public:
    // Konstruktor
    alien_mk1(int, int, int, int, int, SDL_Renderer*);

};
////////////////////////////////////////////////////////////////

class alien_mk2 : public alien
{
public:
    // Konstruktor
    alien_mk2(int, int, int, int, int, SDL_Renderer*);
    ~alien_mk2() = default;

};
////////////////////////////////////////////////////////////////

class alien_mk3 : public alien
{
public:
    // Konstruktor
    alien_mk3(int, int, int, int, int, SDL_Renderer*);

    //funktioner
    class flying_objects* attack();
    int get_y_speed() const;
};
////////////////////////////////////////////////////////////////

#endif
