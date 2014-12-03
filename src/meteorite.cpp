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


bool meteorite::check_living(int dmg)
{
	life_ = life_ - dmg;
	return(life_ <= 0);
}
bool meteorite::hit(flying_objects& other)
{
	flying_objects *ptr_;
	ptr_ = &other;


	bullet* other_obj_4;
	other_obj_4 = dynamic_cast<bullet*>(ptr_);
	if (other_obj_4 != nullptr)
	{
		return check_living(other_obj_4->get_dmg());
	}

	power_up* other_obj_5;
	other_obj_5 = dynamic_cast<power_up*>(ptr_);
	if (other_obj_5 != nullptr)
	{
		return false;
	}

	return true;
}

vector<int> meteorite::movement() const
{

	return position_;
}

int meteorite::get_life() const
{
	return life_;
}



/////////////////////////////////////////////////
