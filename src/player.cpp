#include "player.h"
#include "linkheader.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_main.h>
#include <vector>
using namespace std;

player::player(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer)
{
	SDL_Surface* temp = IMG_Load("player.png");
	texture_ = SDL_CreateTextureFromSurface(renderer, temp);

	renderer_ = renderer;
	life_ = life;
	rect_.x = x_pos;
	rect_.y = y_pos;
	rect_.w = temp->w;
	rect_.h = temp->h;
	x_pos_ = x_pos;
	y_pos_ = y_pos;
	x_speed_ = x_speed;
	y_speed_ = y_speed;
	cerr << " players höjd " << rect_.h << endl;
	SDL_FreeSurface(temp);
}

player::~player()
{
	power_up_attack_.clear();
	power_up_shield_.clear();
}

bool player::check_living(int dmg)
{
	life_ = life_ - dmg;
	return (life_ <= 0);
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
			return check_living(1);
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
			return check_living(1);
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
				power_up_attack* attack_ptr {new power_up_attack{10, 10, 10, 0, 0, renderer_}};
				power_up_attack_.push_back(attack_ptr);
				return false;
			}

			else
			{
				power_up_attack_.at(0)->set_created_time();
				return false;
			}
		}


		power_up_life* other_obj_6;
		other_obj_6 = dynamic_cast<power_up_life*>(ptr_);
		if (other_obj_6 != nullptr)
		{
			life_++;
			return false;
		}

		power_up_shield* other_obj_7;
		other_obj_7 = dynamic_cast<power_up_shield*>(ptr_);
		if (other_obj_7 != nullptr)
		{
			if (power_up_attack_.empty())
			{
				power_up_shield* shield_ptr {new power_up_shield{10, 60, 10, 0, 0, renderer_}};
				power_up_shield_.push_back(shield_ptr);
				return false;
			}

			else
			{
				power_up_attack_.at(0)->set_created_time();
				return false;
			}
		}
	}

	return false;
}

flying_objects* player::attack()
{
	flying_objects* attack_ptr;
	cerr << SDL_GetTicks() << endl;
	cerr << last_shoot_time_ << endl << cooldown_ << endl;
	if (power_up_attack_.empty() && last_shoot_time_ <= (SDL_GetTicks()-cooldown_))
	{
		attack_ptr = new bullet_mk1 {1, 1, (x_pos_ + rect_.w), y_pos_ + rect_.h/2, 200, 0, renderer_};
		last_shoot_time_ = SDL_GetTicks();
		return attack_ptr;
	}
	else if(last_shoot_time_ <= (SDL_GetTicks()-cooldown_))
	{
		last_shoot_time_ = SDL_GetTicks();
		return power_up_attack_.at(0)->attack((x_pos_ + rect_.w), y_pos_ + rect_.h/2);
	}
	return nullptr;
}

void player::increase_life(int amount)
{
	life_ = life_ + amount;
}

