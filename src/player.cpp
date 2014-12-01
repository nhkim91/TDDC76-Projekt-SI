#include "player.h"
#include "linkheader.h"
#include <iostream>

#include <vector>
using namespace std;

void player::operator=(const player& other)
{
	life_ = other.life_;
	speed_ = other.speed_;
}

void player::check_living()
{
	if(get_life()<=0)
	{
		delete this;
		return;
	}
	else
	{
		return;
	}
}

vector<int> player::movement() const
{
	return speed_;
}

int player::get_life() const
{
	return life_;
}

vector<power_up_attack*> player::get_power_up_attack()
{
	return power_up_attack_;
}
vector<power_up_shield*> player::get_power_up_shield()
{
	return power_up_shield_;
}

void player::hit(flying_objects& other)

{
	flying_objects *ptr_;
	ptr_ = &other;

	meteorite* other_obj_1;
	other_obj_1 = dynamic_cast<meteorite*>(ptr_);
	if (other_obj_1 != nullptr)
	{
		if (power_up_shield_.empty())
		{
			--life_;
			check_living();
			return;
		}
		else
		{
			return;
		}
	}

	bullet* other_obj_2;
	other_obj_2 = dynamic_cast<bullet*>(ptr_);
	if (other_obj_2 != nullptr)
	{
		if (power_up_shield_.empty())
		{
			life_= life_-other_obj_2->get_dmg();
			check_living();
			return;
		}
		else
		{
			return;
		}

	}

	alien* other_obj_3;
	other_obj_3 = dynamic_cast<alien*>(ptr_);
	if (other_obj_3 != nullptr)
	{
		if (power_up_shield_.empty())
		{
			--life_;
			check_living();
			return;
		}
		else
		{
			return;
		}
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
				power_up_attack_.at(0)->set_life_time();
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

		power_up_shield* other_obj_7;
		other_obj_7 = dynamic_cast<power_up_shield*>(ptr_);
		if (other_obj_7 != nullptr)
		{
			power_up_shield_.push_back(other_obj_7);
			return;
		}
		else
		{
			power_up_shield_.at(0)->set_life_time();
			return;
		}
	}

	return;
}

bullet player::attack()
{
	if (power_up_attack_.empty())
	{
		return bullet{1, 1, {-1000, 0}};

	}
	else
	{
		return power_up_attack_.at(0)->attack();
	}
}





