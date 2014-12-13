#ifndef PLAYER_H_
#define PLAYER_H_

#include "flying_objects.h"

class player : public flying_objects
{

public:

    // Datamedlemmar
    std::vector<class power_up_attack*> power_up_attack_;
    std::vector<class power_up_shield*> power_up_shield_;
    int cooldown_{500};
    int last_shoot_time_{0};

    // Konstruktor
    player(int, int, int, int, int, SDL_Renderer*);

    //Operatorer
    void operator=(const player&);

    // Destruktor
    ~player();

    // Funktioner

    bool check_living(int);
    bool hit(flying_objects&)  override;
    void clear_power_up_attack();
    void clear_power_up_shield();
    std::vector<power_up_attack*> get_power_up_attack();
    std::vector<power_up_shield*> get_power_up_shield();
    flying_objects* attack();
    void increase_life(int);

};
#endif /* PLAYER_H_ */
