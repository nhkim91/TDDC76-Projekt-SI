#ifndef LEVEL_H
#define LEVEL_H

#include "flying_objects.h"

class level
{
public:
	SDL_Renderer* renderer_{NULL};
    level() = default;
    level(std::vector<flying_objects*> displaying_objects_, int WIDTH, int HEIGHT);
    virtual ~level() = default;

    level(const level&) = default;

    void spawn(int);

private:
    int lvl = 1;
    std::vector<int> data;
    std::vector<flying_objects*> disp_objects_;
    std::vector<flying_objects*>::iterator it = disp_objects_.begin();
    int width;
    int height;

    void get_next_lvl(int);

    //alien
    flying_objects* get_alien_mk1();
    flying_objects* get_alien_mk2();
    flying_objects* get_alien_mk3();

    //meteorite
    flying_objects* get_meteorite_small();
    flying_objects* get_meteorite_medium();

    //power_up
    flying_objects* get_power_up(int);

};


#endif // LEVEL_H
