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
 *              Niclas Granstr�m, nicgr354, 900519-5376
 *
 * Datum:       2014-12-17
 *
 * BESKRIVNING
 * Klassen alian har tre underklasser och tv� funktioner.
 * Funktioner:
 * - check_living: Reducerar aliens liv med m�ngen damage som f�ljer med och kollar d�refter om den fortfarande lever.
 * 	 D�r de kontrolleras det om po�ng ska delas ut till player, dvs om det var player som d�dade den. Detta h�nder
 * 	 inte om tex om en meteorit eller en annan alien tr�ffar alien.
 * - hit: Genomf�r konsekvenserna f�r en kollision mellan alian och var och ett av de andra objekten. En bullet
 *   fr�n en annan alian ska �ka rakt igenom utan skada.
 *
 * Underklasser:
 * - alien_mk1: konstruktorn skapas i h filen och bild samt m�ngd po�ng tilldelas i cpp filen.
 * - alien_mk2: konstruktorn skapas i h filen och bild samt m�ngd po�ng tilldelas i cpp filen.
 * - alien_mk3: konstruktorn skapas och funktioner i h filen, bild samt m�ngd po�ng tilldelas i cpp filen.
 * 		+ Funktioner:
 * 		  - flying_objects* attack: Skapar ett flying_objects pekare som pekar p� en bullet med initialegenskaper.
 *	 	  - int get_y_speed: Ger alien_mk3 m�jlighet att r�ra sig i y led format som sinus.
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
