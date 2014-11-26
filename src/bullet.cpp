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








