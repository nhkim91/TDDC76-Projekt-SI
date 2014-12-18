/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     bullet.cpp
 * Enhetsnamn:  bullet
 * Typ:         Definitioner h�rande till klassen flying_objects
 * Skriven av:  Anton Gifvars,	antgi546, 890917-1657
 * 				Margareta Vi,	marvi154, 920809-0309
 * 				Madeleine Ardic,madar730, 930922-4245
 *              Niclas Granström, nicgr354, 900519-5376
 *
 * Datum:       2014-12-17
 *
 * BESKRIVNING:
 *
 * Filen inneh�ller deklarationer f�r klassen bullet.
 *
 * REFERERADE BIBLIOTEK OCH MODULER:
 */
#include <vector>
#include "bullet.h"
#include "linkheader.h"
using namespace std;

bool bullet::check_living(int dmg)
{
	life_ = life_ - dmg;

	if (life_ <= 0)
	{
		score_given_ = init_score_;
		return true;
	}
	return false;
}

int bullet::get_dmg() const
{
	return dmg_;
}

bool bullet::hit(flying_objects& other)
{
	flying_objects *ptr_;
	ptr_ = &other;
	int dmg_taken {1};
	int other_x_speed = other.get_x_speed();

	bullet* other_obj_1;
	other_obj_1 = dynamic_cast<bullet*>(ptr_);
	if (other_obj_1 != nullptr)
	{
		if (other_x_speed * x_speed_ < 0)
		{
			return true;
		}
		return false;
	}

	alien* other_obj_2;
	other_obj_2 = dynamic_cast<alien*>(ptr_);
	if (other_obj_2 != nullptr)
	{
		if (other_x_speed * x_speed_ < 0)
		{
			return true;
		}
		return false;
	}

	return check_living(dmg_taken);
}

bullet::bullet(int life, int dmg, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer)
{
    renderer_ = renderer;
	life_ = life;
	dmg_ = dmg;
	rect_.x = x_pos;
	rect_.y = y_pos;

	x_pos_ = x_pos;
	x_speed_ = x_speed;
	y_speed_ = y_speed;
}

bullet_mk1::bullet_mk1(int life, int dmg, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer):
    		bullet(life, dmg, x_pos, y_pos, x_speed, y_speed, renderer)
{
	SDL_Surface* temp = IMG_Load("bullet_mk1.png");
	texture_ = SDL_CreateTextureFromSurface(renderer, temp);

	init_score_ = 0;
	rect_.w = temp->w;
	rect_.h = temp->h;
	y_pos_ = y_pos - rect_.h / 2;

	SDL_FreeSurface(temp);
}

bullet_mk2::bullet_mk2(int life, int dmg, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer):
    		bullet(life, dmg, x_pos, y_pos, x_speed, y_speed, renderer)
{
	SDL_Surface* temp = IMG_Load("bullet_mk2.png");
	texture_ = SDL_CreateTextureFromSurface(renderer, temp);

	init_score_ = 0;
	rect_.w = temp->w;
	rect_.h = temp->h;
	y_pos_ = y_pos - rect_.h / 2;

	SDL_FreeSurface(temp);
}

