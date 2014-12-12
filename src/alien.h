/*
 * alien.h
 *
 *  Created on: 25 nov 2014
 *      Author: anton
 */

#ifndef ALIEN_H_
#define ALIEN_H_


#include "flying_objects.h"

class alien : public flying_objects
{
public:

    // Datamedlemmar



    // Konstruktor
    alien(int, int, int, int, int, SDL_Renderer*);
    alien();

    // Destruktor
    //~alien();
    ~alien() = default;

    // Funktioner
    bool check_living(int);
    bool hit(flying_objects&)  override;


};


////////////////////////////////////////////////////////////////
class alien_mk1 : public alien
{
public:

    // Konstruktor
    alien_mk1(int, int, int, int, int, SDL_Renderer*);

};
////////////////////////////////////////////////////////////////

class alien_mk2 : public alien
{
public:

    // Konstruktor
    alien_mk2(int, int, int, int, int, SDL_Renderer*);
    ~alien_mk2() = default;

};
////////////////////////////////////////////////////////////////

class alien_mk3 : public alien
{
public:

    // Konstruktor
    alien_mk3(int, int, int, int, int, SDL_Renderer*);

    //funktioner
    class bullet attack();
};
////////////////////////////////////////////////////////////////

#endif
