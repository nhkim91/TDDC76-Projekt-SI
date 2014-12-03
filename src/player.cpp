#include "player.h"
#include "linkheader.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <SDL2/SDL_main.h>
#include <vector>
using namespace std;

player::player(int life, int x_pos, int y_pos, int x_speed, int y_speed)
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


player::~player()
{
	movement_.clear();
	power_up_attack_.clear();
	power_up_shield_.clear();
}

bool player::check_living(int dmg)
{
	life_= life_ - dmg;
	return (life_<=0);
}

vector<int> player::movement() const
{
	return movement_;
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

bool player::hit(flying_objects& other)

{
	flying_objects *ptr_;
	ptr_ = &other;

	meteorite* other_obj_1;
	other_obj_1 = dynamic_cast<meteorite*>(ptr_);
	if (other_obj_1 != nullptr)
	{
		if (power_up_shield_.empty())
		{
			return check_living(-1);
		}
		else
		{
			return false;
		}
	}

	bullet* other_obj_2;
	other_obj_2 = dynamic_cast<bullet*>(ptr_);
	if (other_obj_2 != nullptr)
	{
		if (power_up_shield_.empty())
		{
			return check_living(other_obj_2->get_dmg());
		}
		else
		{
			return false;
		}

	}

	alien* other_obj_3;
	other_obj_3 = dynamic_cast<alien*>(ptr_);
	if (other_obj_3 != nullptr)
	{
		if (power_up_shield_.empty())
		{
			return check_living(-1);
		}
		else
		{
			return false;
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
				return false;
			}

			else
			{
				power_up_attack_.at(0)->set_life_time();
				return false;
			}
		}


		power_up_life* other_obj_6;
		other_obj_6 = dynamic_cast<power_up_life*>(ptr_);
		if (other_obj_6 != nullptr)
		{
			++life_;
			return false;
		}

		power_up_shield* other_obj_7;
		other_obj_7 = dynamic_cast<power_up_shield*>(ptr_);
		if (other_obj_7 != nullptr)
		{
			power_up_shield_.push_back(other_obj_7);
			return false;
		}
		else
		{
			power_up_shield_.at(0)->set_life_time();
			return false;
		}
	}

	return false;
}

bullet player::attack()
{
	if (power_up_attack_.empty())
	{
		return bullet{1, 1,{10,0}};

	}
	else
	{
		return power_up_attack_.at(0)->attack((movement_.at(0)+100), movement_.at(1));
	}
}



SDL_Rect player::get_rect()
{
	return rect_;
}

