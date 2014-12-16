/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     flying_objects.h
 * Enhetsnamn:  flying_objects
 * Typ:         Klassdeklaration
 * Skriven av:  Anton Gifvars, antgi546, 890917-1657
 * 				Margareta Vi, marvi154,  920809-0309
 * 				Madeleine Ardic, madar730, 930922-4245
 * Datum:       2014-12-xx
 *
 * BESKRIVNING
 *
 * Funktioner:
 *  - hit:
 *  - get_rect:
 *  - get_rect:
 *  - get_life:
 *  - get_x_pos:
 *  - get_y_pos:
 *  - get_x_speed:
 *  - get_y_speed:
 *  - get_texture:
 *  - set_x_pos:
 *  - set_y_pos:
 *  - set_x_speed:
 *  - set_y_speed:
 *  - get_score:
 */
#ifndef FLYING_OBJECTS_H_
#define FLYING_OBJECTS_H_

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_main.h>
#include <iostream>

class flying_objects
{
protected:
	SDL_Rect rect_;
	SDL_Texture* texture_;
	SDL_Texture* texture_special_;
	SDL_Renderer* renderer_;
	int life_;
	int x_pos_;
	int y_pos_;
	int x_speed_;
	int y_speed_;
	int score_given_ {0};
	int init_score_ {0};
	bool special_ {false};

public:
	// Destruktor
	virtual ~flying_objects()
	{
		SDL_DestroyTexture(texture_);
		SDL_DestroyTexture(texture_special_);
	}

	//funktioner
	virtual bool hit(flying_objects&)  = 0;
	////////////////////////////////////////////////////////////////

	SDL_Rect& get_rect()
	{
		return rect_;
	}
	////////////////////////////////////////////////////////////////

	SDL_Rect get_rect() const
	{
		return rect_;
	}
	////////////////////////////////////////////////////////////////

	int get_life()
	{
		return life_;
	}
	////////////////////////////////////////////////////////////////

	int get_x_pos() const
	{
		return x_pos_;
	}
	////////////////////////////////////////////////////////////////

	int get_y_pos() const
	{
		return y_pos_;
	}
	////////////////////////////////////////////////////////////////

	int get_x_speed() const
	{
		return x_speed_;
	}
	////////////////////////////////////////////////////////////////

	int get_y_speed() const
	{
		return y_speed_;
	}
	////////////////////////////////////////////////////////////////

	SDL_Texture* get_texture() const
	{
		if (special_)
		{
			//std::cerr << "apa2!" << std::endl;
			return texture_special_;
		}
		else
		{
			//std::cerr << "apa3!" << std::endl;
			return texture_;
		}
	}
	////////////////////////////////////////////////////////////////

	void set_x_pos(int new_x_pos)
	{
		x_pos_ = new_x_pos;
	}
	////////////////////////////////////////////////////////////////

	void set_y_pos(int new_y_pos)
	{
		y_pos_ = new_y_pos;
	}
	////////////////////////////////////////////////////////////////

	void set_x_speed(int new_x_speed)
	{
		x_speed_ = new_x_speed;
	}
	////////////////////////////////////////////////////////////////

	void set_y_speed(int new_y_speed)
	{
		y_speed_ = new_y_speed;
	}
	////////////////////////////////////////////////////////////////

	int get_score()
	{
		return score_given_;
	}
};
////////////////////////////////////////////////////////////////

#endif /* FLYING_OBJECTS_H_ */
