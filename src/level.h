#ifndef LEVEL_H
#define LEVEL_H

#include "flying_objects.h"
#include "render.h"

class level
{
public:
    level() = default;
    level(int, int, std::vector<flying_objects*>*, SDL_Renderer* renderer);
    virtual ~level() = default;

    level(const level&) = default;

    void spawn(int);

private:
    int lvl{0};
    std::vector<int> data;
    std::vector<flying_objects*>* disp_objects_pointer;
    int width;
    int height;
    SDL_Renderer* renderer_;

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

    render* renderer;
    SDL_Texture *renderText(const std::string &str, const std::string &fontFile,
                            SDL_Color color, int fontSize, SDL_Renderer *renderer);

};


#endif // LEVEL_H
