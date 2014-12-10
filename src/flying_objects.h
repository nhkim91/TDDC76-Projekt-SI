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

//#undef main

//#include <SDL2/SDL_image.h>




////////////////////////////////////////////////////////////////
class flying_objects
{
protected:
	SDL_Rect rect_;
	SDL_Texture* texture_;
	SDL_Renderer* renderer_;

public:


	virtual bool hit(flying_objects&)  = 0;
	virtual std::vector<int> movement() const = 0;
	virtual int get_life() const = 0;
	virtual ~flying_objects() {}
	SDL_Rect& get_rect()
	{
		return rect_;
	}
	SDL_Rect get_rect() const
	{
		return rect_;
	}
	SDL_Texture* get_texture() const
	{
		return texture_;
	}
};


////////////////////////////////////////////////////////////////

#endif /* FLYING_OBJECTS_H_ */
