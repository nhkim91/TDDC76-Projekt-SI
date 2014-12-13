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
	return (life_ <= 0);
}

int bullet::get_dmg() const
{
	return dmg_;
}

bool bullet::hit(flying_objects& other)
{
	int dmg_taken {1};
	return check_living(dmg_taken);

}

/////////////////////////////////////////////////////
bullet::bullet(int life, int dmg, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer)
{

	life_ = life;
	dmg_ = dmg;
	rect_.x = x_pos;
	rect_.y = y_pos;

	x_pos_ = x_pos;
	x_speed_ = x_speed;
	y_speed_ = y_speed;


}
////////////////////////////////////////////////////////

bullet_mk1::bullet_mk1(int life, int dmg, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer):
    		bullet(life, dmg, x_pos, y_pos, x_speed, y_speed, renderer)
{
	SDL_Surface* temp = IMG_Load("bullet_mk1.png");
	texture_ = SDL_CreateTextureFromSurface(renderer, temp);


	rect_.w = temp->w;
	rect_.h = temp->h;
	y_pos_ = y_pos - rect_.h/2;

	SDL_FreeSurface(temp);
}

/////////////////////////////////////////////////

bullet_mk2::bullet_mk2(int life, int dmg, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer):
    		bullet(life, dmg, x_pos, y_pos, x_speed, y_speed, renderer)
{
	SDL_Surface* temp = IMG_Load("bullet_mk2.png");
	texture_ = SDL_CreateTextureFromSurface(renderer, temp);


	rect_.w = temp->w;
	rect_.h = temp->h;
	y_pos_ = y_pos - rect_.h/2;

	SDL_FreeSurface(temp);
}

///////////////////////////////////////////////////
