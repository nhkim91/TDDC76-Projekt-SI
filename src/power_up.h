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
	std::vector<int> movement_;
	int live_until_;
	SDL_Texture* power_up_{nullptr};


	// Konstruktor
	power_up(int life, std::vector<int> movement, int live_until): life_{life}, movement_{movement}, live_until_{live_until}{};


	// Destruktor
	 ~power_up() = default;

	// Funktioner
	 int get_life() const override;
	 std::vector<int> movement() const override;
	 int kill_me_when();
	 int set_life_time();
	 void set_movement();
	 void pick_up_position();
	 bool check_living(int);
};
////////////////////////////////////////////////////////////////
class power_up_attack : public power_up
{
public:
	// Datamedlemmar


	// Konstruktor
	power_up_attack(int life, std::vector<int> movement, int live_until): power_up::power_up{life,movement,live_until}{};

	// Destruktor
	~power_up_attack()=default;

	// Funktioner
	class bullet attack();
	bool hit(flying_objects&);


};
////////////////////////////////////////////////////////////////
class power_up_life : public power_up
{
public:

	// Konstruktor
	power_up_life(int life, std::vector<int> movement, int life_until): power_up::power_up{life,movement,life_until}{};

	// Funktioner
	bool hit(flying_objects&) override;

};
////////////////////////////////////////////////////////////////
class power_up_shield : public power_up
{
public:

	// Konstruktor
	power_up_shield(int life, std::vector<int> movement,int life_until): power_up::power_up{life,movement,life_until}{};

	// funktioner

	bool hit(flying_objects&) override;

};
////////////////////////////////////////////////////////////////

#endif /* POWER_UP_H_ */

