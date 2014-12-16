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
 * Datum:       2014-12-xx
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

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "highscore.h"
#include "patch.h"
#include <cctype>
#include <SDL2/SDL_events.h>

using namespace std;

void highscore::set_renderer(render* rend)
{
    renderer = rend;
}


//Jämför score med den redan existerande highscore-listan. Om spelaren placerar sig på listan anropas enter_name()
//och poängen sparas över till highscore-listan.
void highscore::save_score(int score)
{
    load();
    highscore_element temp;
    vector<highscore_element>::iterator it;
    int i {0};
    for (it = list_of_score.begin(); it != list_of_score.end(); it++)
    {
        if (score > list_of_score[i].score)
        {
            SDL_Color redColor {187, 32, 26, 255};

            string text = "Congratulations!";
            string text2 = "You entered top 10.";
            renderer->render_text(text, "Arcade.ttf", redColor, 60, 190, 200);
            renderer->render_text(text2, "Arcade.ttf", redColor, 60, 140, 250);
            renderer->present();
            SDL_Delay(1500);
            //Göra spelaren uppmärksam på att den har kommit med på highscore-listan?
            //Vi har samtidigt tillgång till vilken plats (i+1).
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
    return;
}

//Läser in ett namn från tangentbordet.
string highscore::enter_name() //Namnet ska vara ett ord (får inte vara tom sträng).
{
    string name;
    SDL_Delay(500);
    SDL_Event event;

    run = true;

    //Rendera tom ruta
    SDL_Color textColor {255, 255, 255, 255};

    string text = "Write your name without space. Finish with enter.";
    renderer->render_text(text, "Arcade.ttf", textColor, 30, 50, 150);
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
                    renderer->render_text(text, "Arcade.ttf", textColor, 30, 50, 150);
                }
            }
            else if (key == SDLK_BACKSPACE)
            {
                string text = "Write your name without space. Finish with enter.";
                renderer->render_text(text, "Arcade.ttf", textColor, 30, 50, 150);
                if (!name.empty())
                {
                    name.erase(name.end() - 1);

                    if (!name.empty())
                    {
                        renderer->render_text(name, "Arcade.ttf", textColor, 30, 50, 180);
                    }
                }
            }
            else
            {
                //TODO: kolla att ni får bara får in A-Z om ni vill.
                string text = "Write your name without space. Finish with enter.";
                renderer->render_text(text, "Arcade.ttf", textColor, 30, 50, 150);
                char c = *(SDL_GetKeyName(key));
                name += c;
                renderer->render_text(name, "Arcade.ttf", textColor, 30, 50, 180);
            }
            renderer->present();
        }
    }

    return name;
}

//Läser in highscore från fil och sparar över till list_of_score.
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

//Sparar över highscore till fil.
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

    renderer->render_image("space_background.png", 0, 0);

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
