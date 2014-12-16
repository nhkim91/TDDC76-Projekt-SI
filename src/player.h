#ifndef PLAYER_H_
#define PLAYER_H_

#include "flying_objects.h"

class player : public flying_objects
{

public:

    // Datamedlemmar
    class power_up_attack* power_up_attack_ {nullptr};
    class power_up_shield* power_up_shield_{nullptr};
    unsigned int cooldown_ {200};
    unsigned int last_shoot_time_ {0};
    class sound* sound_{NULL};

    // Konstruktor
    player(int, int, int, int, int, SDL_Renderer*, sound*);

    //Operatorer
    //void operator=(const player&);

    // Destruktor
    ~player();

    // Funktioner

    bool check_living(int);
    bool hit(flying_objects&)  override;
    void clear_power_up_attack();
    void clear_power_up_shield();
    power_up_attack* get_power_up_attack();
    power_up_shield* get_power_up_shield();
    flying_objects* attack();
    void increase_life(int);
    void set_special(bool);

};
#endif /* PLAYER_H_ */
