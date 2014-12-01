#include "alien.h"
#include "linkheader.h"
#include <vector>
using namespace std;


vector<int> alien::movement() const
{

	return speed_;
}


int alien::get_life() const
{
	return life_;
}

void alien::check_living()
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

void alien::hit(flying_objects& other)
{
	flying_objects *ptr_;
	ptr_ = &other;

	meteorite* other_obj_1;
	other_obj_1 = dynamic_cast<meteorite*>(ptr_);
	if (other_obj_1 != nullptr)
	{
		life_= life_ - other_obj_1->get_life();
		check_living();
		return;
	}

	player* other_obj_2;
	other_obj_2 = dynamic_cast<player*>(ptr_);
	if (other_obj_2 != nullptr)
	{
		life_= life_ - other_obj_2->get_life();
		check_living();
		return;
	}

	bullet* other_obj_3;
	other_obj_3 = dynamic_cast<bullet*>(ptr_);
	if (other_obj_3 != nullptr)
	{
		life_= life_ - other_obj_3->get_dmg();
		check_living();
		return;
	}

	alien* other_obj_4;
	other_obj_4 = dynamic_cast<alien*>(ptr_);
	if (other_obj_4 != nullptr)
	{
		return;
	}

	power_up* other_obj_5;
	other_obj_5 = dynamic_cast<power_up*>(ptr_);
	if (other_obj_5 != nullptr)
	{
		return;
	}

}
