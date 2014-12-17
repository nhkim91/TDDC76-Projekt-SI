/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     help.cpp
 * Enhetsnamn:  help
 * Typ:         Definitioner hörande till klassen help
 * Skriven av:  Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *              Kerstin Soderqvist 911006-0309 Y3.c kerso255
 *              Niclas Granström, nicgr354, 900519-5376
 *              Anton Gifvars,	antgi546, 890917-1657
 *
 * Datum:       2014-12-17
 *
 * BESKRIVNING
 *
 * Denna implementeringsfil innehåller definitioner för klassen help, som har som uppgift
 * att innehålla och framföra information om hur man spelar spelet.
 */

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#include "help.h"
#include <string>
#include <iostream>

void help::set_renderer(render* rend)
{
    renderer = rend;
}

void help::show_help()
{
    renderer->render_background("Space.png", 0, 0);

    SDL_Color whiteColor {255, 255, 255, 255};
    SDL_Color redColor {187, 32, 26, 255};

    std::string msg = "Arrow up and down navigates the spaceship.";
    std::string msg1 = "Use space to shoot the enemy.";
    std::string msg2 = "Try not to be hit by the meteorites";
    std::string msg3 = "or when the aliens shoot you. And don't";
    std::string msg4 = "let the aliens over-run your planet.";
    int width = renderer->get_width();
    int height = renderer->get_height();

    renderer->render_text("Help", "Arcade.ttf", whiteColor, height/6, width/2, height/12);
    renderer->render_text(msg, "Arcade.ttf", whiteColor, height/20, width/2, height/3);
    renderer->render_text(msg1, "Arcade.ttf", whiteColor, height/20, width/2, height/3 + height/12);
    renderer->render_text(msg2, "Arcade.ttf", whiteColor, height/20, width/2, height/3 + 2*height/12);
    renderer->render_text(msg3, "Arcade.ttf", whiteColor, height/20, width/2, height/3 + 3*height/12);
    renderer->render_text(msg4, "Arcade.ttf", whiteColor, height/20, width/2, height/3 + 4*height/12);
    renderer->render_text("Back to Menu", "Arcade.ttf", redColor, height/15, width/2, height/3 + 6*height/12);

    renderer->present();

    bool run = true;
    SDL_Event event;

    while (run)
    {
        SDL_WaitEvent(&event);
        if (event.type == SDL_KEYDOWN)
        {
            SDL_Keycode key = event.key.keysym.sym;
            if (key == SDLK_ESCAPE || key == SDLK_RETURN)
            {
                run = false;
                break;
            }
        }
    }
}

/*
 * SLUT PÅ FILEN help.cpp
 */
