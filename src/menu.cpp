#include "menu.h"

#include <iostream>

void menu::set_renderer(render* rend)
{
    renderer = rend;
}

void menu::set_play(space_invader* _space_invader)
{
    si = _space_invader;
}

void menu::set_highscore(highscore* highscore_)
{
    hs = highscore_;
}

void menu::set_help(help* help_)
{
    h = help_;
}

void menu::run()
{
    bool loop {true};
    SDL_Event event;

    render_menu();

    while (loop)
    {
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT)
        {
            loop = false;
        }
        if (event.type == SDL_KEYDOWN)
        {
            SDL_Keycode key = event.key.keysym.sym;
            if (key == SDLK_DOWN)
            {
                ++selected_item;
                if (selected_item > 3)
                {
                    selected_item = 0;
                }
            }
            else if (key == SDLK_UP)
            {
                --selected_item;

                if (selected_item < 0)
                {
                    selected_item = 3;
                }
            }
            else if (key == SDLK_ESCAPE)
            {
                loop = false;
            }
            else if (key == SDLK_RETURN || key == SDLK_RETURN2)
            {
                if (selected_item == 0)
                {
                    si->run();
                    //int score = si->run();
                    //hs->save_score(score);
                }
                else if (selected_item == 1)
                {
                    hs->show_highscore();
                }
                else if(selected_item == 2)
                {
                    h->show_help();
                }
                else if(selected_item == 3)
                {
                    loop = false;
                }
                else
                {
                    //TODO: ERROR
                }
            }
            render_menu();
        }
    }
}


void menu::render_menu()
{
    SDL_Color whiteColor {255, 255, 255, 255};
    SDL_Color redColor {187, 32, 26, 255};

    renderer->render_image("space_background.png",0, 0);
    renderer->render_text("Space Invader", "Arcade.ttf", whiteColor, 100, 80, 30);

    //*
    if(selected_item == 0)
    {
        renderer->render_text("Play", "Arcade.ttf", redColor, 50, 350, 260);
        renderer->render_text("High Score", "Arcade.ttf", whiteColor, 50, 280, 310);
        renderer->render_text("Help", "Arcade.ttf", whiteColor, 50, 350, 360);
        renderer->render_text("Quit", "Arcade.ttf", whiteColor, 50, 350, 410);
    }
    else if(selected_item == 1)
    {
        renderer->render_text("Play", "Arcade.ttf", whiteColor, 50, 350, 260);
        renderer->render_text("High Score", "Arcade.ttf", redColor, 50, 280, 310);
        renderer->render_text("Help", "Arcade.ttf", whiteColor, 50, 350, 360);
        renderer->render_text("Quit", "Arcade.ttf", whiteColor, 50, 350, 410);
    }
    else if(selected_item == 2)
    {
        renderer->render_text("Play", "Arcade.ttf", whiteColor, 50, 350, 260);
        renderer->render_text("High Score", "Arcade.ttf", whiteColor, 50, 280, 310);
        renderer->render_text("Help", "Arcade.ttf", redColor, 50, 350, 360);
        renderer->render_text("Quit", "Arcade.ttf", whiteColor, 50, 350, 410);
    }
    else if(selected_item == 3)
    {
        renderer->render_text("Play", "Arcade.ttf", whiteColor, 50, 350, 260);
        renderer->render_text("High Score", "Arcade.ttf", whiteColor, 50, 280, 310);
        renderer->render_text("Help", "Arcade.ttf", whiteColor, 50, 350, 360);
        renderer->render_text("Quit", "Arcade.ttf", redColor, 50, 350, 410);
    }
    //*/

    renderer->present();
}
