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

power_up::power_up(int life, int x_pos, int y_pos, int x_speed, int y_speed)
{
	life_= life;
	rect_.x = x_pos;
	rect_.y = y_pos;
	rect_.w = 100;
	rect_.h = 100;
	movement_.at(0) = x_pos;
	movement_.at(1) = y_pos;
	movement_.at(2) = x_speed;
	movement_.at(3) = y_speed;

}


vector<int> power_up::movement() const
{

	return this->movement_;
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
	movement_ = {0,0,5000,0};
	return;
}

bool power_up::check_living(int dmg)
{
	life_ = life_ - dmg;
	return(life_ <= 0);
}
/////////////////////////////////////////////////

bullet power_up_attack::attack(int x_pos, int y_pos)
{
	return bullet{2, 3, x_pos, y_pos, 15, 0};
}

bool power_up_attack::hit(flying_objects& other)
{
	flying_objects *ptr_;
	ptr_ = &other;

	player* other_obj_1;
	other_obj_1 = dynamic_cast<player*>(ptr_);
	if (other_obj_1 != nullptr)
	{
		pick_up_position();
		set_life_time();
		return false;
	}

	bullet* other_obj_2;
	other_obj_2 = dynamic_cast<bullet*>(ptr_);
	if (other_obj_2 != nullptr)
	{
		return true;
	}

	return false;

}

/////////////////////////////////////////////////
bool power_up_life::hit(flying_objects& other)
{
	flying_objects *ptr_;
	ptr_ = &other;

	player* other_obj_3;
	other_obj_3 = dynamic_cast<player*>(ptr_);
	if (other_obj_3 != nullptr)
	{
		pick_up_position();
		return false;
	}

	return false;
}

/////////////////////////////////////////////////

bool power_up_shield::hit(flying_objects& other)
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
			return false;
		}
		else
		{
			other_obj_5->get_power_up_shield().at(0)->set_life_time();
			return false;
		}
	}

	bullet* other_obj_6;
	other_obj_6 = dynamic_cast<bullet*>(ptr_);
	if (other_obj_6 != nullptr)
	{
		return true;
	}

	return false;

}

/////////////////////////////////////////////////



