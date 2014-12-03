/*
 * meteorite.cpp
 *
 *  Created on: 25 nov 2014
 *      Author: anton
 */
#include "meteorite.h"
#include "linkheader.h"
#include <iostream>
//#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include <SDL2/SDL_main.h>
#include <vector>
using namespace std;

meteorite::meteorite(int life, int x_pos, int y_pos, int x_speed, int y_speed)
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

	return movement_;
}

int meteorite::get_life() const
{
	return life_;
}



/////////////////////////////////////////////////
