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
	alien(int life, std::vector<int> movement): life_{life}, movement_{movement}{};
	alien(int, int, int, int, int, int, int);

	// Destruktor
	 ~alien() = default;

	// Funktioner
	int get_life() const override;
	bool check_living(int);
	std::vector<int> movement() const override;
	bool hit(flying_objects&)  override;


};


////////////////////////////////////////////////////////////////
class alien_mk1 : public alien
{
public:

	// Konstruktor
	alien_mk1(int life, std::vector<int> movement): alien::alien{life,movement}{};

};
////////////////////////////////////////////////////////////////

#endif
