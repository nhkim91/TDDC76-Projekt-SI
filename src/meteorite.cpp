/*
 * meteorite.cpp
 *
 *  Created on: 25 nov 2014
 *      Author: anton
 */
#include "meteorite.h"
#include "linkheader.h"
#include <vector>
using namespace std;




void meteorite::hit(flying_objects& other)
{
	flying_objects *ptr_;
	ptr_ = &other;

	meteorite* other_obj;
	other_obj = dynamic_cast<meteorite*>(ptr_);
	if (other_obj != nullptr)
		{
			life_ = life_-1;
		}

	return;
}

vector<int> meteorite::movement() const
{

	return this->position_;
}

int meteorite::get_life() const
{
	return life_;
}


/////////////////////////////////////////////////
