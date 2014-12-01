/*
 * power_up.cpp
 *
 *  Created on: 25 nov 2014
 *      Author: anton
 */

#include "power_up.h"
#include "linkheader.h"
#include <vector>
using namespace std;

vector<int> power_up::movement() const
{

	return this->speed_;
}

int power_up::get_life() const
{
	return life_;
}

int power_up::kill_me_when()
{
	return live_until_;
}

int power_up::set_life_time()
{
	live_until_ = SDL_GetTicks() + 10000;
	return live_until_;
}


/////////////////////////////////////////////////

bullet power_up_attack::attack()
{
	return bullet{1, 1, {-1000, 0}};
}

void power_up_attack::hit(flying_objects&)
{
	return;
}
/////////////////////////////////////////////////
void power_up_shield::hit(flying_objects&)
{
	return;
}

/////////////////////////////////////////////////

void power_up_life::hit(flying_objects&)
{
	return;
}

/////////////////////////////////////////////////




