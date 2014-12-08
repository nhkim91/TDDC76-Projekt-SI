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
	std::vector<int> movement_;


	// Konstruktor
	meteorite(int, int, int, int, int, SDL_Renderer*);
	meteorite();

	// Destruktor
	 ~meteorite();

	 // Funktioner
	int get_life() const override;
	bool check_living(int);
	std::vector<int> movement() const override;
	bool hit(flying_objects&)  override;

};
////////////////////////////////////////////////////////////////
class meteorite_small : public meteorite
{
public:

	// Konstruktor
	meteorite_small(int, int, int, int, int, SDL_Renderer*);

};
////////////////////////////////////////////////////////////////
class meteorite_medium : public meteorite
{
public:

	// Konstruktor
	meteorite_medium(int, int, int, int, int, SDL_Renderer*);

};
///////////////////////////////////////////////////////////////

#endif /* METEORITE_H_ */



