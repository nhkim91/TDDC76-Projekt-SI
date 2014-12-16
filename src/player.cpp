#include "player.h"
#include "linkheader.h"
#include "sound.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <SDL2/SDL_main.h>
#include <vector>
using namespace std;

player::player(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer, sound* sound)
{
    SDL_Surface* temp = IMG_Load("player.png");
    texture_ = SDL_CreateTextureFromSurface(renderer, temp);

    sound_ = sound;
    init_score_ = 0;
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

    SDL_FreeSurface(temp);


    SDL_Surface* temp2 = IMG_Load("playerShip2_blue.png");
    texture_special_ = SDL_CreateTextureFromSurface(renderer, temp2);

    SDL_FreeSurface(temp2);

}

player::~player()
{
    delete power_up_attack_;
    power_up_attack_ = nullptr;
    delete power_up_shield_;
    power_up_shield_ = nullptr;
}

void player::clear_power_up_attack()
{
    flying_objects* ptr;
    ptr = dynamic_cast<flying_objects*>(power_up_attack_);
    delete ptr;
    //delete power_up_attack_;
    power_up_attack_ = nullptr;
    return;
}

void player::clear_power_up_shield()
{
    flying_objects* ptr;
    ptr = dynamic_cast<flying_objects*>(power_up_shield_);
    if (ptr == nullptr)
    {
        cerr << "nullptr\n";
    }
    delete ptr;
    //delete power_up_shield_;
    power_up_shield_ = nullptr;
    return;
}

bool player::check_living(int dmg)
{
    life_ = life_ - dmg;
    return (life_ <= 0);
}

power_up_attack* player::get_power_up_attack()
{
    return power_up_attack_;
}

power_up_shield* player::get_power_up_shield()
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
        if (power_up_shield_ == nullptr)
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
        if (power_up_shield_ == nullptr)
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
        if (power_up_shield_ == nullptr)
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
            if (power_up_attack_ == nullptr)
            {
                power_up_attack* attack_ptr {new power_up_attack{10, 10, 10, 0, 0, renderer_}};
                power_up_attack_ = attack_ptr;
                return false;
            }

            else
            {
                power_up_attack_->set_created_time();
                return false;
            }
        }


        power_up_life* other_obj_6;
        other_obj_6 = dynamic_cast<power_up_life*>(ptr_);
        if (other_obj_6 != nullptr)
        {
            if (life_ < 5)
            {
                life_++;
            }
            return false;
        }

        power_up_shield* other_obj_7;
        other_obj_7 = dynamic_cast<power_up_shield*>(ptr_);
        if (other_obj_7 != nullptr)
        {
            if (power_up_shield_ == nullptr)
            {
                power_up_shield* shield_ptr {new power_up_shield{10, 60, 10, 0, 0, renderer_}};
                power_up_shield_ = shield_ptr;
                special_ = true;
                return false;
            }

            else
            {
                power_up_shield_ ->set_created_time();
                return false;
            }
        }
    }

    return false;
}

flying_objects* player::attack()
{
    flying_objects* attack_ptr;
    if (power_up_attack_ == nullptr && last_shoot_time_ <= (SDL_GetTicks() - cooldown_))
    {
        attack_ptr = new bullet_mk1 {1, 1, (x_pos_ + rect_.w), y_pos_ + rect_.h / 2, 400, 0, renderer_};
        last_shoot_time_ = SDL_GetTicks();
        sound_->play_attack();
        return attack_ptr;
    }
    else if (last_shoot_time_ <= (SDL_GetTicks() - cooldown_))
    {
        last_shoot_time_ = SDL_GetTicks();
        sound_->play_attack();
        return power_up_attack_->attack((x_pos_ + rect_.w), y_pos_ + rect_.h / 2);
    }
    return nullptr;
}

void player::increase_life(int amount)
{
    life_ = life_ + amount;
}

void player::set_special(bool statement)
{
    //cerr << "apa!" << endl;
    special_ = statement;
}
