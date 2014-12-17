/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     space_invader.h
 * Enhetsnamn:  space_invader
 * Typ:         Deklarationsfil för space_invader
 * Skriven av:  Kim Nguyen Hoang, kimng797, 910112-0260
 *              Kerstin Soderqvist, kerso255, 911006-0309
 *              Anton Gifvars, antgi546, 890917-1657
 * 				Margareta Vi, marvi154,  920809-0309
 * 				Madeleine Ardic, madar730, 930922-4245
 *              Niclas Granström, nicgr354, 900519-5376
 *
 * Datum:       2014-12-17
 *
 * BESKRIVNING
 *
 * Härifrån styrs spelet.
 *
 * Funktioner:
 * - get_objects_to_kill:
 * - kill_objects:
 * - my_sort:
 * - collides:
 * - check_x_collides:
 * - check_y_collides:
 * - run: Körfunktion
 * - render_things: Renderar objekten
 * - update_things: Uppdaterar fönstret
 * - add_object:
 * - power_up_timer_check:
 * - get_score:
 * - make_alien_attack:
 *
 */

#ifndef SPACE_INVADER_H
#define SPACE_INVADER_H

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#include <vector>
#include "flying_objects.h"
#include "render.h"
#include "level.h"
#include "sound.h"
class space_invader
{
public:

    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    class player* player_;
    std::vector<flying_objects*> displaying_objects_;

    space_invader() = delete;

    ~space_invader();
    space_invader(SDL_Renderer*, render*, sound*, int, int);


    void get_objects_to_kill();
    void kill_objects(std::vector<unsigned int>);
    bool my_sort(int i, int j);
    bool collides(const flying_objects&, const flying_objects&);
    bool check_x_collides(SDL_Rect, SDL_Rect);
    bool check_y_collides(SDL_Rect, SDL_Rect);
    bool run();
    void render_things(std::vector<flying_objects*>);
    void update_things(std::vector<flying_objects*>, float);
    void add_object(flying_objects*);
    void power_up_timer_check();
    int get_score();
    void make_alien_attack();

private:
    SDL_Renderer* renderer_;
    render* render_;
    level* level_;
    int score_ {0};
    sound* sound_;

    SDL_Texture* background_texture;
    SDL_Rect background_rect;


};

#endif // SPACE_INVADER_H
