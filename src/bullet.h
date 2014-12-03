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
	std::vector<int> movement_;
	SDL_Rect rect_;

	//Funktioner
	int get_life() const override;
	bool check_living(int);
	std::vector<int> movement() const override;
	int get_dmg() const;
	bool hit(flying_objects&) override;
	SDL_Rect get_rect() const override;


	// Konstruktor
	bullet(int, int, int, int, int, int);

	// Destruktor
	 ~bullet()=default;
};

class bullet_mk1 : public bullet
{
public:
		// Konstruktor
	bullet_mk1(int life, int dmg, int x_pos, int y_pos, int x_speed, int y_speed): bullet::bullet{life,dmg,x_pos,y_pos,x_speed,y_speed}{};


	 // Funktioner
};
#endif /* BULLET_H_ */
