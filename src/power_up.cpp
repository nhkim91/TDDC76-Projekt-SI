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

	return this->position_;
}

int power_up::get_life() const
{
	return life_;
}

void power_up::hit(flying_objects& other)
{
	return;
}

void power_up_attack::reset_timer()
	{
		timer_=10000;
	}

int power_up_attack::get_timer()
{
	return timer_;
}

void power_up_attack::countdown_timer()
{
	--timer_;
	if(timer_==0)
	{
		delete this;
	}
}
/////////////////////////////////////////////////





