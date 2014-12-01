/*
 * bullet.h
 *
 *  Created on: 25 nov 2014
 *      Author: anton
 */


#ifndef BULLET_H_
#define BULLET_H_

#include "flying_objects.h"

class bullet :public flying_objects
{

public:


	// Datamedlemmar
	int life_;
	int dmg_;
	std::vector<int> speed_;

	int get_life() const override;
	void check_living();
	std::vector<int> movement() const override;
	int get_dmg() const;
	void hit(flying_objects&) override;


	// Konstruktor
	bullet(int life,int dmg, std::vector<int> speed): life_{life},dmg_{dmg}, speed_{speed}{};

	// Destruktor
	 ~bullet() = default;
};

class bullet_mk1 : public bullet
{
public:
		// Konstruktor
	bullet_mk1(int life, int dmg, std::vector<int> speed): bullet::bullet{life,dmg,speed}{};


	 // Funktioner
};
#endif /* BULLET_H_ */
