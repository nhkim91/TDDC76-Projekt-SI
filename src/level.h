#ifndef LEVEL_H
#define LEVEL_H

#include "flying_objects.h"

class level
{
public:
	SDL_Renderer* renderer_{NULL};
    level() = default;
    virtual ~level() = default;

    level(const level& l);

    flying_objects* spawn(int);

private:
    int lvl = 1;
    std::vector<int> data;

    void get_next_lvl(int);

    //alien
    flying_objects* get_alien_mk1();
    flying_objects* get_alien_mk2();
    flying_objects* get_alien_mk3();

    //meteorite
    flying_objects* get_meteorite_small();

    //power_up
    flying_objects* get_power_up(int);

};


#endif // LEVEL_H
