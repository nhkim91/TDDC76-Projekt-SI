/*
 * bullet.h
 *
 * Denna klass är till för bullet, dvs skott som både alien och player använder sig av.
 * Funktioner:
 *  - get_life: hämtar livet på bullet
 *  - check_living: kollar om bullet lever
 *  - movement: en veckor som sparar undan positionerningen i x- och y-led samt hastigheten i x- och y-led.
 *  -get_dmg: retunerar antalet skada som bullet har.
 *  - hit: konsekvensena som händer när bullet krockar med resterande klasser
 *
 *   Innehåller också sub-klasserna bullet_mk1 som är default skottet, bullet_mk2 som fås genom en power up.
 */


#ifndef BULLET_H_
#define BULLET_H_

#include "flying_objects.h"

class bullet : public flying_objects
{

public:


    // Datamedlemmar
    int dmg_;


    //Funktioner
    bool check_living(int);
    int get_dmg() const;
    bool hit(flying_objects&) override;



    // Konstruktor
    bullet(int, int, int, int, int, int, SDL_Renderer*);
    bullet();

    // Destruktor
    ~bullet();
};
//////////////////////////////////////////
class bullet_mk1 : public bullet
{
public:
    // Konstruktor
    bullet_mk1(int, int, int, int, int, int, SDL_Renderer*);

    // Funktioner
};

//////////////////////////////////////////
class bullet_mk2 : public bullet
{
public:

    // Konstruktor
    bullet_mk2(int, int, int, int, int, int, SDL_Renderer*);


    // Funktioner
};
#endif /* BULLET_H_ */
