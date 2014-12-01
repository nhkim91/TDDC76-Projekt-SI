/*
 * meteorite.h
 *
 *  Created on: 25 nov 2014
 *      Author: anton
 */

#ifndef METEORITE_H_
#define METEORITE_H_

#include "flying_objects.h"




class meteorite :public flying_objects
{

public:

	// Datamedlemmar
	int life_;
	std::vector<int> position_;

	// Konstruktor
	meteorite(int life, std::vector<int> position): life_{life}, position_{position}{};

	// Destruktor
	 ~meteorite() = default;

	 // Funktioner
	int get_life() const override;
	void check_living();
	std::vector<int> movement() const override;
	void hit(flying_objects&)  override;
};
////////////////////////////////////////////////////////////////
class meteorite_small : public meteorite
{
public:

	// Konstruktor
	meteorite_small(int life, std::vector<int> position): meteorite::meteorite{life,position}{};

};
////////////////////////////////////////////////////////////////

#endif /* METEORITE_H_ */



