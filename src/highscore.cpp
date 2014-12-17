/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     highscore.cpp
 * Enhetsnamn:  highscore
 * Typ:         Definitioner hörande till klassen highscore
 * Skriven av:  Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *              Kerstin Soderqvist 911006-0309 Y3.c kerso255
 * Datum:       2014-12-17
 *
 * BESKRIVNING
 *
 * Filen innehåller definitioner för klassen highscore.
 * Den har som uppgift att ha hand om highscore sedan tidigare spelade spel genom att
 * ladda in och visa highscore på skärmen, samt att då poängen, vid avslutat spel,
 * kvalificerar sig för highscore-listan, spara över detta till listan.
 */

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>

#include <fstream>
#include <sstream>
#include <iostream>

#include "highscore.h"
#include "patch.h"

using namespace std;

void highscore::set_renderer(render* rend)
{
    renderer = rend;
}

void highscore::save_score(int score)
{
    load();
    highscore_element temp;
    vector<highscore_element>::iterator it;
    int i {0};
    renderer->render_image("Astronaut.png",0,0,1.0f);
    SDL_Color whiteColor {255, 255, 255, 255};
    SDL_Event event;
    for (it = list_of_score.begin(); it != list_of_score.end(); it++)
    {
        if (score > list_of_score[i].score)
        {
            run = true;

            string text = "Congratulations!";
            string text2 = "You entered top 10.";
            renderer->render_text(text, "Arcade.ttf", whiteColor, 50, 200, 20);
            renderer->render_text(text2, "Arcade.ttf", whiteColor, 50, 150, 70);
            renderer->present();
            while (run)
            {
                SDL_WaitEvent(&event);
                if (event.type == SDL_KEYDOWN)
                {
                    SDL_Keycode key = event.key.keysym.sym;
                    if (key == SDLK_RETURN || key == SDLK_RETURN2)
                    {
                        run = false;
                        break;
                    }
                }
            }

            temp.name = enter_name();
            temp.score = score;
            list_of_score.insert(it, temp);
            list_of_score.pop_back();
            write();
            show_highscore();
            return;
        }
        i++;
    }

    run = true;
    string text3 = "Game Over";
    renderer->render_text(text3, "Arcade.ttf", whiteColor, 100, 170, 50);
    renderer->present();
    SDL_Delay(1500);
}

string highscore::enter_name()
{
    string name;
    SDL_Event event;

    run = true;

    SDL_Color textColor {255, 255, 255, 255};

    renderer->render_image("Astronaut.png",0,0,1.0f);
    string text = "Write your name. Then hit enter.";
    renderer->render_text(text, "Arcade.ttf", textColor, 40, 50, 20);
    renderer->present();

    while (run)
    {
        SDL_WaitEvent(&event);
        if (event.type == SDL_KEYDOWN)
        {
            SDL_Keycode key = event.key.keysym.sym;
            if (key == SDLK_RETURN || key == SDLK_RETURN2)
            {
                if (!name.empty())
                {
                    run = false;
                    break;
                }
                else
                {
                    renderer->render_image("Astronaut.png",0,0,1.0f);
                    renderer->render_text(text, "Arcade.ttf", textColor, 40, 50, 20);
                }
            }
            else if (key == SDLK_BACKSPACE)
            {
                renderer->render_image("Astronaut.png",0,0,1.0f);
                renderer->render_text(text, "Arcade.ttf", textColor, 40, 50, 20);
                if (!name.empty())
                {
                    name.erase(name.end() - 1);

                    if (!name.empty())
                    {
                        renderer->render_text(name, "Arcade.ttf", textColor, 40, 50, 70);
                    }
                }
            }
            else
            {
                renderer->render_image("Astronaut.png",0,0,1.0f);
                renderer->render_text(text, "Arcade.ttf", textColor, 40, 50, 20);
                char c = *(SDL_GetKeyName(key));
                name += c;
                renderer->render_text(name, "Arcade.ttf", textColor, 40, 50, 70);
            }
            renderer->present();
        }
    }

    return name;
}

void highscore::load()
{
    list_of_score.resize(10);
    ifstream hs;
    hs.open("highscore.txt");
    highscore_element temp;

    if (hs.is_open())
    {

        for (int i = 0; i < 10; i++)
        {
            hs >> temp.name;
            hs >> temp.score;
            list_of_score[i] = temp;
        }
    }
    else
    {
        cout << "Tom High Score" << endl;
        return;
    }

    hs.close();
    return;
}

void highscore::write()
{
    ofstream hs;
    hs.open("highscore.txt", ios::out | ios::trunc);

    for (int i = 0; i < 10; i++)
    {
        hs << list_of_score[i].name;
        hs << " ";
        hs << list_of_score[i].score;
        hs << " \n";
    }

    hs.close();
    return;
}

void highscore::show_highscore()
{
    load();

    renderer->render_image("Colorful_space.png", 0, 0, 0.45f);

    SDL_Color redColor {187, 32, 26, 255};

    renderer->render_text("High Score", "Arcade.ttf", redColor, 100, 150, 30);

    SDL_Color whiteColor {255, 255, 255, 255};

    for (int i = 0; i < 10; ++i)
    {
        renderer->render_text((patch::to_string(i + 1) + "."), "Arcade.ttf", whiteColor, 30, 200, 130 + i * 30);
        renderer->render_text(patch::to_string(list_of_score[i].score), "Arcade.ttf", whiteColor, 30, 270, 130 + i * 30);
        renderer->render_text(list_of_score[i].name, "Arcade.ttf", whiteColor, 30, 450, 130 + i * 30);
        renderer->render_text("Back to Menu", "Arcade.ttf", redColor, 40, 280, 550);
    }
    renderer->present();

    run = true;
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
 * SLUT PÅ FILEN highscore.cpp
 */
