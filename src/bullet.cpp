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

bullet::~bullet()
{
	SDL_DestoryTexture(texture_);
	SDL_DestoryRenderer(renderer_);
}

bool bullet::check_living(int dmg)
{
	life_ = life_ - dmg;
	return(life_ <= 0);
}

vector<int> bullet::movement() const
{

	return movement_;
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

/////////////////////////////////////////////////////
bullet::bullet(int life, int dmg, int x_pos, int y_pos,int x_speed, int y_speed, SDL_Renderer* renderer)
{
	//SDL_Surface* temp = IMG_Load("bullet_mk1.png");
	//texture_ = SDL_CreateTextureFromSurface(renderer, temp);


	life_= life;
	dmg_ = dmg;
	rect_.x = x_pos;
	rect_.y = y_pos;
	//rect_.w = temp->w;
	//rect_.h = temp->h;
	movement_.at(0) = x_pos;
	movement_.at(1) = y_pos;
	movement_.at(2) = x_speed;
	movement_.at(3) = y_speed;

	//SDL_FreeSurface(temp);
}
////////////////////////////////////////////////////////

bullet_mk1::bullet_mk1(int life, int dmg, int x_pos, int y_pos,int x_speed, int y_speed, SDL_Renderer* renderer):
		bullet(life, dmg, x_pos, y_pos, x_speed, y_speed, renderer)
{
	SDL_Surface* temp = IMG_Load("bullet_mk1.png");
	texture_ = SDL_CreateTextureFromSurface(renderer, temp);

	/*
	life_= life;
	dmg_ = dmg;
	rect_.x = x_pos;
	rect_.y = y_pos;
	 */
	rect_.w = temp->w;
	rect_.h = temp->h;
	/*
	movement_.at(0) = x_pos;
	movement_.at(1) = y_pos;
	movement_.at(2) = x_speed;
	movement_.at(3) = y_speed;
	 */
	SDL_FreeSurface(temp);
}

/////////////////////////////////////////////////

bullet_mk2::bullet_mk2(int life, int dmg, int x_pos, int y_pos,int x_speed, int y_speed, SDL_Renderer* renderer):
		bullet(life, dmg, x_pos, y_pos, x_speed, y_speed, renderer)
{
	SDL_Surface* temp = IMG_Load("bullet_mk2.png");
	texture_ = SDL_CreateTextureFromSurface(renderer, temp);

	/*
			life_= life;
			dmg_ = dmg;
			rect_.x = x_pos;
			rect_.y = y_pos;
	 */
	rect_.w = temp->w;
	rect_.h = temp->h;
	/*
			movement_.at(0) = x_pos;
			movement_.at(1) = y_pos;
			movement_.at(2) = x_speed;
			movement_.at(3) = y_speed;
	 */
	SDL_FreeSurface(temp);
}

///////////////////////////////////////////////////
