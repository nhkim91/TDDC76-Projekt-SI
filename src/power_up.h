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
	std::vector<int> position_;

	// Konstruktor
	power_up(int life, std::vector<int> position): life_{life}, position_{position}{};

	// Destruktor
	 ~power_up() = default;

	// Funktioner
	 int get_life() const override;
	 std::vector<int> movement() const override;
	 void hit(flying_objects&) override;
};
////////////////////////////////////////////////////////////////
class power_up_attack : public power_up
{
public:
	// Datamedlemmar
	int timer_{1000};

	// Konstruktor
	power_up_attack(int life, std::vector<int> position): power_up::power_up{life,position}{};

	// Destruktor
	~power_up_attack()=default;

	// Funktioner
	int get_timer();
	void reset_timer();
	void countdown_timer();

};
////////////////////////////////////////////////////////////////
class power_up_life : public power_up
{
public:

	// Konstruktor
	power_up_life(int life, std::vector<int> position): power_up::power_up{life,position}{};

};
////////////////////////////////////////////////////////////////
class power_up_shield : public power_up
{
public:

	// Konstruktor
	power_up_shield(int life, std::vector<int> position): power_up::power_up{life,position}{};

};
////////////////////////////////////////////////////////////////
class power_up_slow_motion : public power_up
{
public:

	// Konstruktor
	power_up_slow_motion(int life, std::vector<int> position): power_up::power_up{life,position}{};

};

#endif /* POWER_UP_H_ */

