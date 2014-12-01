/*
 * bullet.cpp
 *
 *  Created on: 25 nov 2014
 *      Author: anton
 */


#include "bullet.h"
#include "linkheader.h"
#include <vector>
using namespace std;


void bullet::check_living()
{
	if(get_life()==0)
	{
		delete this;
	}
	else
	{
		return;
	}
}

vector<int> bullet::movement() const
{

	return speed_;
}

int bullet::get_life() const
{
	return life_;
}

int bullet::get_dmg() const
{
	return dmg_;
}

void bullet::hit(flying_objects& other)
{
	return;
}
/////////////////////////////////////////////////








