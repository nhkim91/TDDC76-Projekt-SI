/*
 * Flying_objects.h
 *
 *  Created on: 23 nov 2014
 *      Author: samanthavi
 */

#ifndef FLYING_OBJECTS_H_
#define FLYING_OBJECTS_H_
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_main.h>

#include <iostream>

//#undef main

//#include <SDL2/SDL_image.h>




////////////////////////////////////////////////////////////////
class flying_objects
{
protected:
    SDL_Rect rect_;
    SDL_Texture* texture_;
    SDL_Renderer* renderer_;
    int life_;
    int x_pos_;
    int y_pos_;
    int x_speed_;
    int y_speed_;


public:


    virtual bool hit(flying_objects&)  = 0;

    virtual ~flying_objects()
    {
        std::cerr << "innan delete texture \n";
        SDL_DestroyTexture(texture_);
        std::cerr << "efter delete \n";
    }

    SDL_Rect& get_rect()
    {
        return rect_;
    }

    SDL_Rect get_rect() const
    {
        return rect_;
    }

    int get_life()
    {
        return life_;
    }

    int get_x_pos() const
    {
        return x_pos_;
    }

    int get_y_pos() const
    {
        return y_pos_;
    }

    int get_x_speed() const
    {
        return x_speed_;
    }

    int get_y_speed() const
    {
        return y_speed_;
    }

    SDL_Texture* get_texture() const
    {
        return texture_;
    }

    void set_x_pos(int new_x_pos)
    {
        x_pos_ = new_x_pos;
    }

    void set_y_pos(int new_y_pos)
    {
        y_pos_ = new_y_pos;
    }

    void set_x_speed(int new_x_speed)
    {
        x_speed_ = new_x_speed;
    }

    void set_y_speed(int new_y_speed)
    {
        y_speed_ = new_y_speed;
    }
};


////////////////////////////////////////////////////////////////

#endif /* FLYING_OBJECTS_H_ */
