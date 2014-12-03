/*
 * alien.h
 *
 *  Created on: 25 nov 2014
 *      Author: anton
 */

#ifndef ALIEN_H_
#define ALIEN_H_


#include "flying_objects.h"

class alien :public flying_objects
{
public:

	// Datamedlemmar
	int life_;
	std::vector<int> movement_;
	SDL_Rect  rect_;

	// Konstruktor
	alien(int, int, int, int, int);

	// Destruktor
	 ~alien();

	// Funktioner
	int get_life() const override;
	bool check_living(int);
	std::vector<int> movement() const override;
	bool hit(flying_objects&)  override;
	SDL_Rect get_rect() override;

};


////////////////////////////////////////////////////////////////
class alien_mk1 : public alien
{
public:

	// Konstruktor
	alien_mk1(int life, int x_pos, int y_pos, int x_speed, int y_speed): alien::alien{life, x_pos, y_pos, x_speed, y_speed}{};

};
////////////////////////////////////////////////////////////////

class alien_mk2 : public alien
{
public:

	// Konstruktor
	alien_mk2(int life, int x_pos, int y_pos, int x_speed, int y_speed): alien::alien{life, x_pos, y_pos, x_speed, y_speed}{};

};
////////////////////////////////////////////////////////////////

class alien_mk3 : public alien
{
public:

	// Konstruktor
	alien_mk3(int life, int x_pos, int y_pos, int x_speed, int y_speed): alien::alien{life, x_pos, y_pos, x_speed, y_speed}{};

};
////////////////////////////////////////////////////////////////

#endif
