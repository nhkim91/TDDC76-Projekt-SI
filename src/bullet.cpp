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



bool bullet::check_living(int dmg)
{
	life_ = life_ - dmg;
	return(life_ <= 0);
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

bool bullet::hit(flying_objects& other)
{
	flying_objects *ptr_;
	ptr_ = &other;

	meteorite* other_obj_1;
	other_obj_1 = dynamic_cast<meteorite*>(ptr_);
	if (other_obj_1 != nullptr)
	{
		return check_living(other_obj_1->get_life());
	}

	alien* other_obj_2;
	other_obj_2 = dynamic_cast<alien*>(ptr_);
	if (other_obj_2 != nullptr)
	{
		return check_living(other_obj_2->get_life());
	}

	player* other_obj_3;
	other_obj_3 = dynamic_cast<player*>(ptr_);
	if (other_obj_3 != nullptr)
	{
		return check_living(other_obj_3->get_life());;
	}

	bullet* other_obj_4;
	other_obj_4 = dynamic_cast<bullet*>(ptr_);
	if (other_obj_4 != nullptr)
	{
		return check_living(other_obj_4->get_life());;
	}

	power_up* other_obj_5;
	other_obj_5 = dynamic_cast<power_up*>(ptr_);
	if (other_obj_5 != nullptr)
	{
		return check_living(other_obj_5->get_life());;
	}

}
/////////////////////////////////////////////////








