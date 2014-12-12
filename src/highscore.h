#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <string>
#include <vector>
#include <SDL2/SDL_ttf.h>
#include "render.h"

class highscore
{
public:
    highscore() = default;
    ~highscore() = default;

    highscore(const highscore&) = default;

    void save_score(int);
    void show_highscore();
    void set_renderer(render*);

private:
    struct highscore_element
    {
        std::string name;
        int score;
    };

    render* renderer;

    std::vector<highscore_element> list_of_score;

    bool run;

    //Laddar in highscore till list_of_score.
    void load();

    //Skriver över highscore till fil.
    void write();
    std::string enter_name(); //Tar in ett namn från tangentbordet.
};

#endif // HIGHSCORE_H
