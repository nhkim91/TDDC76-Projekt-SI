/*
 * power_up.h
 *
 *  Created on: 25 nov 2014
 *      Author: anton
 */
#include "flying_objects.h"

#ifndef POWER_UP_H_
#define POWER_UP_H_

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
	void set_movement();
	bool times_up();
	bool check_living(int);
	bool hit(flying_objects&) override;
};
////////////////////////////////////////////////////////////////
class power_up_attack : public power_up
{
public:
	// Datamedlemmar


	// Konstruktor
	power_up_attack(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer);

	// destruktor
	~power_up_attack()=default;
	// Funktioner
	flying_objects* attack(int, int);


};
////////////////////////////////////////////////////////////////
class power_up_life : public power_up
{
public:

	// Konstruktor
	power_up_life(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer);

	// Funktioner


};
////////////////////////////////////////////////////////////////
class power_up_shield : public power_up
{
public:

	// Konstruktor
	power_up_shield(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer);

	// funktioner



};
////////////////////////////////////////////////////////////////

#endif /* POWER_UP_H_ */

