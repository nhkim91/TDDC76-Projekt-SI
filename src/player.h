/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     player.h
 * Enhetsnamn:  player
 * Typ:         Klassdeklaration
 * Skriven av:  Anton Gifvars, antgi546, 890917-1657
 * 				Margareta Vi, marvi154,  920809-0309
 * 				Madeleine Ardic, madar730, 930922-4245
 * Datum:       2014-12-xx
 *
 * BESKRIVNING:
 *
 * Funktioner:
 * - check_living:
 * - hit:
 * - clear_power_up_attack:
 * - clear_power_up_shield:
 * - get_power_up_attack:
 * - get_power_up_shield:
 * - attack:
 * - increase_life:
 * - set_special:
 * - power_up_attack* get_power_up_attack:
 * - power_up_shield* get_power_up_shield:
 * - flying_objects* attack:
 */
#ifndef PLAYER_H_
#define PLAYER_H_

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */
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

    // Destruktor
    ~player();

    // Funktioner
    bool check_living(int);
    bool hit(flying_objects&)  override;
    void clear_power_up_attack();
    void clear_power_up_shield();
    void increase_life(int);
    void set_special(bool);
    power_up_attack* get_power_up_attack();
    power_up_shield* get_power_up_shield();
    flying_objects* attack();
};
#endif /* PLAYER_H_ */
