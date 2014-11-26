#include "player.h"
#include "linkheader.h"
#include <iostream>

#include <vector>
using namespace std;

void player::operator=(const player& other)
{
	life_ = other.life_;
	dmg_ = other.dmg_;
	speed_ = other.speed_;
}



vector<int> player::movement() const
{
	return speed_;
}

int player::get_life() const
{
	return life_;
}

void player::hit(flying_objects& other)
{
	flying_objects *ptr_;
	ptr_ = &other;

	meteorite* other_obj_1;
	other_obj_1 = dynamic_cast<meteorite*>(ptr_);
	if (other_obj_1 != nullptr)
	{
		--life_;
		return;
	}

	bullet* other_obj_2;
	other_obj_2 = dynamic_cast<bullet*>(ptr_);
	if (other_obj_2 != nullptr)
	{
		life_= life_-other_obj_2->get_dmg();
		return;
	}

	alien* other_obj_3;
	other_obj_3 = dynamic_cast<alien*>(ptr_);
	if (other_obj_3 != nullptr)
	{
		--life_;
		return;
	}

	power_up* other_obj_4;
	other_obj_4 = dynamic_cast<power_up*>(ptr_);
	if (other_obj_4 != nullptr)
	{

		power_up_attack* other_obj_5;
		other_obj_5 = dynamic_cast<power_up_attack*>(ptr_);
		if (other_obj_5 != nullptr)
		{
			if (power_up_attack_.empty())
			{
				power_up_attack_.push_back(other_obj_5);
				return;
			}

			else
			{
				power_up_attack_.at(0)->reset_timer();
				return;
			}
		}


		power_up_life* other_obj_6;
		other_obj_6 = dynamic_cast<power_up_life*>(ptr_);
		if (other_obj_6 != nullptr)
		{
			++life_;
			return;
		}



	}

	return;
}




