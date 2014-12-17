/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     alien.cpp
 * Enhetsnamn:  alien
 * Typ:         Definitioner h�rande till klassen flying_objects
 * Skriven av:  Anton Gifvars, antgi546, 890917-1657
 * 				Margareta Vi, marvi154,  920809-0309
 * 				Madeleine Ardic, madar730, 930922-4245
 * Datum:       2014-12-xx
 *
 * BESKRIVNING:
 * Filen innh�ller definitioner f�r klassen alien.
 * Klassen inneh�ller tre alians mk1-mk3 med olika
 * funktioner f�r att ge de deras egenskaper.
 *
 * REFERERADE BIBLIOTEK OCH MODULER:
 */
#include "linkheader.h"
#include <math.h>
using namespace std;

bool alien::check_living(int dmg, bool give_points)
{
    life_ = life_ - dmg;

    if (life_ <= 0 && give_points)
    {
        score_given_ = init_score_;
        return true;
    }
    if (life_ <= 0)
    {
        return true;
    }
    return false;
}

bool alien::hit(flying_objects& other)
{
    flying_objects *ptr_;
    ptr_ = &other;
    int dmg_taken {1};
    int other_x_speed;
	other_x_speed = other.get_x_speed();

    meteorite* other_obj_1;
    other_obj_1 = dynamic_cast<meteorite*>(ptr_);
    if (other_obj_1 != nullptr)
    {
        return check_living(dmg_taken, false);
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
    	if(x_speed_ * other_x_speed < 0)
    	{
    		return check_living(other_obj_3->get_dmg(), true);
    	}
    }
    return false;
}

alien::alien(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer)
{
    renderer_ = renderer;
    life_ = life;
    rect_.x = x_pos;
    rect_.y = y_pos;

    x_pos_ = x_pos;
    y_pos_ = y_pos;
    x_speed_ = x_speed;
    y_speed_ = y_speed;
}

alien_mk1::alien_mk1(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer):
    alien(life, x_pos, y_pos, x_speed, y_speed, renderer)
{
    SDL_Surface* temp = IMG_Load("alien1.png");
    texture_ = SDL_CreateTextureFromSurface(renderer, temp);

    init_score_ = 100;
    rect_.w = temp->w;
    rect_.h = temp->h;

    SDL_FreeSurface(temp);
}

alien_mk2::alien_mk2(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer):
    alien(life, x_pos, y_pos, x_speed, y_speed, renderer)
{
    SDL_Surface* temp = IMG_Load("alien2.png");
    texture_ = SDL_CreateTextureFromSurface(renderer, temp);

    init_score_ = 200;
    rect_.w = temp->w;
    rect_.h = temp->h;
    SDL_FreeSurface(temp);
}

alien_mk3::alien_mk3(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer):
    alien(life, x_pos, y_pos, x_speed, y_speed, renderer)
{
    SDL_Surface* temp = IMG_Load("alien3.png");
    texture_ = SDL_CreateTextureFromSurface(renderer, temp);

    init_score_ = 300;
    rect_.w = temp->w;
    rect_.h = temp->h;

    SDL_FreeSurface(temp);
}

int alien_mk3::get_y_speed() const
{
	double time = SDL_GetTicks()/1000;
	return (y_speed_* sin(time));
}

flying_objects* alien_mk3::attack()
{
    int offset {50};
    flying_objects* attack_ptr;
    attack_ptr = new bullet_mk1 {1, 1, (x_pos_ - offset), y_pos_ + rect_.h / 2, (x_speed_ - 200), 0, renderer_};
    return attack_ptr;
}

