#include "alien.h"
#include "linkheader.h"
#include <vector>
using namespace std;



alien::alien(int life, int x_pos, int y_pos, int x_speed, int y_speed)
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

alien::~alien()
{
	movement_.clear();
}

vector<int> alien::movement() const
{

	return movement_;
}


int alien::get_life() const
{
	return life_;
}

bool alien::check_living(int dmg)
{
	life_ = life_ - dmg;
	return (life_ <=0);
}

bool alien::hit(flying_objects& other)
{
	flying_objects *ptr_;
	ptr_ = &other;

	meteorite* other_obj_1;
	other_obj_1 = dynamic_cast<meteorite*>(ptr_);
	if (other_obj_1 != nullptr)
	{
		return check_living(other_obj_1->get_life());
	}

	player* other_obj_2;
	other_obj_2 = dynamic_cast<player*>(ptr_);
	if (other_obj_2 != nullptr)
	{
		return true;
	}

	bullet* other_obj_3;
	other_obj_3 = dynamic_cast<bullet*>(ptr_);
	if (other_obj_3 != nullptr)
	{
		return check_living(other_obj_3->get_dmg());
	}

	return false;

}

bullet alien_mk3::attack()
{
	return bullet{1, 1,(movement_.at(0)-1), movement_.at(1), -10, 0};

}

