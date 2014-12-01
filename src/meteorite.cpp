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


void meteorite::check_living()
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

void meteorite::hit(flying_objects& other)
{
	flying_objects *ptr_;
	ptr_ = &other;

	meteorite* other_obj_1;
	other_obj_1 = dynamic_cast<meteorite*>(ptr_);
	if (other_obj_1 != nullptr)
		{
		delete this;
		}
	else
	{
		return;
	}

	player* other_obj_2;
	other_obj_2 = dynamic_cast<player*>(ptr_);
	if (other_obj_2 != nullptr)
		{
		delete this;
		}
	else
	{
		return;
	}

	alien* other_obj_3;
	other_obj_3 = dynamic_cast<alien*>(ptr_);
	if (other_obj_3 != nullptr)
	{
		delete this;
	}
	else
	{
		return;
	}

	bullet* other_obj_4;
	other_obj_4 = dynamic_cast<bullet*>(ptr_);
	if (other_obj_4 != nullptr)
	{
		life_ = life_- other_obj_4->get_dmg();
	}
	else
	{
		return;
	}
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
