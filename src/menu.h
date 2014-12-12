#ifndef MENU_H
#define MENU_H
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <string>
#include <vector>
#include "render.h"
#include "space_invader.h"
#include "highscore.h"
#include "help.h"

class menu
{
public:
    menu()=default;
    ~menu()=default;

    void set_renderer(render*);
    void set_play(space_invader*);
    void set_highscore(highscore*);
    void set_help(help*);
    void run();


private:
    int selected_item {0};

    render* renderer;
    space_invader* si;
    highscore* hs;
    help* h;

    void render_menu();
};

#endif // MENU_H
