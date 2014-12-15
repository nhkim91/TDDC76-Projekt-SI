/*
 * power_up.cpp
 *
 *  Created on: 25 nov 2014
 *      Author: anton
 */
#include "linkheader.h"
using namespace std;

power_up::power_up(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer)
{
	renderer_ = renderer;
	life_ = life;
	rect_.x = x_pos;
	rect_.y = y_pos;
	created_ = SDL_GetTicks();

	x_pos_ = x_pos;
	y_pos_ = y_pos;
	x_speed_ = x_speed;
	y_speed_ = y_speed;
}

int power_up::get_created_time()
{
	return created_ ;
}

void power_up::set_created_time()
{
	created_ = SDL_GetTicks();
	return;
}

bool power_up::times_up()
{
	Uint32 time = SDL_GetTicks();
	return (created_ + time_to_live_ < time);
}

bool power_up::check_living(int dmg)
{
	life_ = life_ - dmg;
	return (life_ <= 0);
}

bool power_up::hit(flying_objects& other)
{
	flying_objects *ptr_;
	ptr_ = &other;

	player* other_obj_1;
	other_obj_1 = dynamic_cast<player*>(ptr_);
	if (other_obj_1 != nullptr)
	{
		return true;
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
power_up_attack::power_up_attack(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer):
    				power_up(life, x_pos, y_pos, x_speed, y_speed, renderer)
{
	SDL_Surface* temp = IMG_Load("power_up_attack.png");
	texture_ = SDL_CreateTextureFromSurface(renderer, temp);

	rect_.w = temp->w;
	rect_.h = temp->h;

	SDL_FreeSurface(temp);
}

flying_objects* power_up_attack::attack(int x_pos, int y_pos)
{
	flying_objects* attack_ptr;
	attack_ptr = new bullet_mk2 {2, 3, x_pos, y_pos, 300, 0, renderer_};
	return attack_ptr;
}

/////////////////////////////////////////////////
power_up_life::power_up_life(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer):
		power_up(life, x_pos, y_pos, x_speed, y_speed, renderer)
{
	SDL_Surface* temp = IMG_Load("power_up_life.png");
	texture_ = SDL_CreateTextureFromSurface(renderer, temp);

	rect_.w = temp->w;
	rect_.h = temp->h;

	SDL_FreeSurface(temp);
}

/////////////////////////////////////////////////
power_up_shield::power_up_shield(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer):
    				power_up(life, x_pos, y_pos, x_speed, y_speed, renderer)
{
	SDL_Surface* temp = IMG_Load("power_up_shield.png");
	texture_ = SDL_CreateTextureFromSurface(renderer, temp);

	rect_.w = temp->w;
	rect_.h = temp->h;

	SDL_FreeSurface(temp);
}

/////////////////////////////////////////////////
