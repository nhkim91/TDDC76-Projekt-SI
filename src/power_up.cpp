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

void power_up::pick_up_position()
{
	speed_ = {0,0,5000,0};
	return ;
}

/////////////////////////////////////////////////

bullet power_up_attack::attack()
{
	return bullet{1, 1, {-1000, 0}};
}

void power_up_attack::hit(flying_objects& other)
{
	flying_objects *ptr_;
	ptr_ = &other;

	player* other_obj_1;
	other_obj_1 = dynamic_cast<player*>(ptr_);
	if (other_obj_1 != nullptr)
	{
		pick_up_position();
		set_life_time();
		return;
	}

	bullet* other_obj_2;
	other_obj_2 = dynamic_cast<bullet*>(ptr_);
	if (other_obj_2 != nullptr)
	{
		delete this;
		return;
	}

	return;

}

/////////////////////////////////////////////////
void power_up_life::hit(flying_objects& other)
{
	flying_objects *ptr_;
	ptr_ = &other;

	player* other_obj_3;
	other_obj_3 = dynamic_cast<player*>(ptr_);
	if (other_obj_3 != nullptr)
	{
		delete this;
		return;
	}

	return;
}

/////////////////////////////////////////////////

void power_up_shield::hit(flying_objects& other)
{
	flying_objects *ptr_;
	ptr_ = &other;

	player* other_obj_5;
	other_obj_5 = dynamic_cast<player*>(ptr_);
	if (other_obj_5 != nullptr)
	{
		if (other_obj_5->get_power_up_shield().empty())
		{
			pick_up_position();
			set_life_time();
			return;
		}
		else
		{
			other_obj_5->get_power_up_shield().at(0)->set_life_time();
			return;
		}
	}

	bullet* other_obj_6;
	other_obj_6 = dynamic_cast<bullet*>(ptr_);
	if (other_obj_6 != nullptr)
	{
		delete this;
		return;
	}

	return;

}

/////////////////////////////////////////////////



