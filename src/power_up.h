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
	int life_until_;

	// Konstruktor
	power_up(int life, std::vector<int> speed, int life_until): life_{life}, speed_{speed}, life_until_{life_until}{};

	// Destruktor
	 ~power_up() = default;

	// Funktioner
	 int get_life() const override;
	 std::vector<int> movement() const override;
	 void hit(flying_objects&) override;
	 int kill_me_when() const;
	 int set_life_time() const;
};
////////////////////////////////////////////////////////////////
class power_up_attack : public power_up
{
public:
	// Datamedlemmar
	int timer_{1000};

	// Konstruktor
	power_up_attack(int life, std::vector<int> speed, int life_until): power_up::power_up{life,speed,life_until}{};

	// Destruktor
	~power_up_attack()=default;

	// Funktioner
	void power_up_attack() const;
};
////////////////////////////////////////////////////////////////
class power_up_life : public power_up
{
public:

	// Konstruktor
	power_up_life(int life, std::vector<int> speed, int life_until): power_up::power_up{life,speed,life_until}{};

};
////////////////////////////////////////////////////////////////
class power_up_shield : public power_up
{
public:

	// Konstruktor
	power_up_shield(int life, std::vector<int> speed,int life_until): power_up::power_up{life,speed,life_until}{};

};
////////////////////////////////////////////////////////////////
class power_up_slow_motion : public power_up
{
public:

	// Konstruktor
	power_up_slow_motion(int life, std::vector<int> speed, int life_until): power_up::power_up{life,speed,life_until}{};

};

#endif /* POWER_UP_H_ */

