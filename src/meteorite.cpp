/*
 * meteorite.cpp
 *
 *  Created on: 25 nov 2014
 *      Author: anton
 */
#include "meteorite.h"
#include "linkheader.h"
#include <iostream>
#include <SDL2/SDL.h>
//#include <SDL2_image/SDL_image.h>

#include <SDL2/SDL_main.h>
#include <vector>
using namespace std;



bool meteorite::check_living(int dmg)
{
    life_ = life_ - dmg;
    return (life_ <= 0);
}

bool meteorite::hit(flying_objects& other)
{
    flying_objects *ptr_;
    ptr_ = &other;


    bullet* other_obj_4;
    other_obj_4 = dynamic_cast<bullet*>(ptr_);
    if (other_obj_4 != nullptr)
    {
        return check_living(other_obj_4->get_dmg());
    }

    power_up* other_obj_5;
    other_obj_5 = dynamic_cast<power_up*>(ptr_);
    if (other_obj_5 != nullptr)
    {
        return false;
    }

    return true;
}

meteorite::meteorite(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer)
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
/////////////////////////////////////////////////
meteorite_small::meteorite_small(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer):
    meteorite(life, x_pos, y_pos, x_speed, y_speed, renderer)
{
    SDL_Surface* temp = IMG_Load("meteorite_small.png");
    texture_ = SDL_CreateTextureFromSurface(renderer, temp);


    rect_.w = temp->w;
    rect_.h = temp->h;

    SDL_FreeSurface(temp);
}
/////////////////////////////////////////////////
meteorite_medium::meteorite_medium(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer):
    meteorite(life, x_pos, y_pos, x_speed, y_speed, renderer)
{
    SDL_Surface* temp = IMG_Load("meteorite_medium.png");
    texture_ = SDL_CreateTextureFromSurface(renderer, temp);


    rect_.w = temp->w;
    rect_.h = temp->h;


    SDL_FreeSurface(temp);
}
