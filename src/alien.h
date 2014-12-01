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
	std::vector<int> speed_;

	// Konstruktor
	alien(int life, std::vector<int> speed): life_{life}, speed_{speed}{};

	// Destruktor
	 ~alien() = default;

	// Funktioner
	int get_life() const override;
	void check_living();
	std::vector<int> movement() const override;
	void hit(flying_objects&)  override;


};


////////////////////////////////////////////////////////////////
class alien_mk1 : public alien
{
public:

	// Konstruktor
	alien_mk1(int life, std::vector<int> position): alien::alien{life,position}{};

};
////////////////////////////////////////////////////////////////

#endif
