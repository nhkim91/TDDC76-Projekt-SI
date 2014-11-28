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

int power_up::kill_me_when() const
{
	return life_until_;
}

int power_up::set_life_time() const
{
	life_until_ = SDL_GetTicks() + 10000;
	return life_until_;
}

void power_up_attack::power_up_attack() const;
{
	return;
}

//int power_up::hit(flying_objects&)
//{
//	return;
//}


/////////////////////////////////////////////////





