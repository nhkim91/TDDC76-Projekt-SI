/*
 * power_up.h
 *
 *  Created on: 25 nov 2014
 *      Author: anton
 */
#include "flying_objects.h"

#ifndef POWER_UP_H_
#define POWER_UP_H_

class power_up :public flying_objects
{

public:

	// Datamedlemmar
	int life_;
	std::vector<int> speed_;
	int live_until_;

	// Konstruktor
	power_up(int life, std::vector<int> speed, int live_until): life_{life}, speed_{speed}, live_until_{live_until}{};

	// Destruktor
	 ~power_up() = default;

	// Funktioner
	 int get_life() const override;
	 std::vector<int> movement() const override;
	 int kill_me_when();
	 int set_life_time();
};
////////////////////////////////////////////////////////////////
class power_up_attack : public power_up
{
public:
	// Datamedlemmar


	// Konstruktor
	power_up_attack(int life, std::vector<int> speed, int live_until): power_up::power_up{life,speed,live_until}{};

	// Destruktor
	~power_up_attack()=default;

	// Funktioner
	class bullet attack();
	void hit(flying_objects&);

};
////////////////////////////////////////////////////////////////
class power_up_life : public power_up
{
public:

	// Konstruktor
	power_up_life(int life, std::vector<int> speed, int life_until): power_up::power_up{life,speed,life_until}{};

	// Funktioner
	void hit(flying_objects&) override;

};
////////////////////////////////////////////////////////////////
class power_up_shield : public power_up
{
public:

	// Konstruktor
	power_up_shield(int life, std::vector<int> speed,int life_until): power_up::power_up{life,speed,life_until}{};

	// funktioner

	void hit(flying_objects&) override;

};
////////////////////////////////////////////////////////////////

#endif /* POWER_UP_H_ */

