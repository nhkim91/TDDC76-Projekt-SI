/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     power_up.h
 * Enhetsnamn:  power_up
 * Typ:         Klassdeklaration
 * Skriven av:  Anton Gifvars, antgi546, 890917-1657
 * 				Margareta Vi, marvi154,  920809-0309
 * 				Madeleine Ardic, madar730, 930922-4245
 *              Niclas Granström, nicgr354, 900519-5376
 *
 * Datum:       2014-12-17
 *
 * BESKRIVNING
 * Filen innehåller deklarationer för klassen power_up.
 *
 * Det finns 3 st power_ups som man kan få i spelets gång, power_up_attck, power_up shield, och power_up life.
 * Power_up_attack och power_up_shield är tidsbaserade, dvs de försvinner efter en viss tid.
 *
 * Funktioner:
 * - get_created_time: Returnerar tidpunkten som en viss power_up skapas.
 * - set_created_time: Tidstämplar created_(den datamedlem som skapas när en power up skapas) till SDL_GetTicks.
 * - times_up: 		   Ska retunera när en viss power_up ska upphöra( gäller bara för dem tidsbaserade power_ups:en).
 * - check_living:	   Kollar om power_upen existerar. Returnerar en true/false
 * - hit:			   Kollar vad power_up har krockat med.

 * Underklasser:
 * - power_up_attack:
 *		+Funktioner:
 * 		   flying_objects* attack: skapar den bullet som player använder sig av när det har tagit upp en power_up_attack
 *
 * - power_up_shield:
 * - power_up_life:
 * 		 +Funktioner:
 * 		   flying_objects* attack:
 */
#ifndef POWER_UP_H_
#define POWER_UP_H_

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */
#include "flying_objects.h"

class power_up : public flying_objects
{
public:
	// Datamedlemmar
	Uint32 time_to_live_ {10000};
	Uint32 created_ {0};

	// Konstruktor
	power_up(int, int, int, int, int, SDL_Renderer*);

	// Destruktor
	~power_up()=default;


	// Funktioner
	int get_created_time();
	void set_created_time();
	bool times_up();
	bool check_living(int);
	bool hit(flying_objects&) override;
};
////////////////////////////////////////////////////////////////

class power_up_attack : public power_up
{
public:
	// Konstruktor
	power_up_attack(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer);

	// destruktor
	~power_up_attack() = default;

	// Funktioner
	flying_objects* attack(int, int);
};
////////////////////////////////////////////////////////////////

class power_up_life : public power_up
{
public:
	// Konstruktor
	power_up_life(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer);
};
////////////////////////////////////////////////////////////////

class power_up_shield : public power_up
{
public:
	// Konstruktor
	power_up_shield(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer);
};
////////////////////////////////////////////////////////////////

#endif /* POWER_UP_H_ */
