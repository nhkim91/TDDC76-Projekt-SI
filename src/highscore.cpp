/*
 * Har hand om alla user inputs
 * Kan implementeras
 *
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
            //Göra spelaren uppmärksam på att den har kommit med på highscore-listan?
            //Vi har samtidigt tillgång till vilken plats (i+1).
            temp.name = enter_name();
            temp.score = score;
            list_of_score.insert(it, temp);
            list_of_score.pop_back();
            write();
            return;
        }
        i++;
    }
    return;
}

//Läser in ett namn från tangentbordet.
string highscore::enter_name() //Namnet ska vara ett ord.
{
    string name;
    SDL_Delay(500);
    SDL_Event event;

    run = true;

    //Rendera tom ruta
    SDL_Color textColor {255, 255, 255, 255};

    string text = "Skriv in ditt namn utan mellanrum. Avsluta med enter.";
    renderer->render_text(text, "Arcade.ttf", textColor, 30, 50, 30);
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
                // TODO: tryck enter, behöver spara namn
            }
            else if (key == SDLK_BACKSPACE)
            {
                string text = "Skriv in ditt namn utan mellanrum. Avsluta med enter.";
                renderer->render_text(text, "Arcade.ttf", textColor, 30, 50, 30);
                if (!name.empty())
                {
                    name.erase(name.end() - 1);

                    if (!name.empty())
                    {
                        renderer->render_text(name, "Arcade.ttf", textColor, 30, 50, 60);
                    }
                }
            }
            else
            {
                //TODO: kolla att ni får bara får in A-Z om ni vill.
                string text = "Skriv in ditt namn utan mellanrum. Avsluta med enter.";
                renderer->render_text(text, "Arcade.ttf", textColor, 30, 50, 30);
                char c = *(SDL_GetKeyName(key));
                name += c;
                renderer->render_text(name, "Arcade.ttf", textColor, 30, 50, 60);
            }
            renderer->present();
        }
    }

    /*
    SDL_StartTextInput();
    while(run)
    {
        cout << "Inne i run" << endl;
        while (SDL_PollEvent (&event))
        {
            cout << "Ett event har inträffat" << endl;
            if(event.type == SDL_KEYDOWN)
            {
                cout << "Knapptryckning" << endl;
                if(isalnum(event.key.keysym.sym))
                {

                    //rendera
                    renderer->render_text(name, "seguisb.ttf", textColor, 30, 50, 30);
                    renderer->present();

                    name = name + patch::to_string(event.key.keysym.sym);

                    break;
                }
                else if(event.key.keysym.sym == SDLK_BACKSPACE)
                {
                    if(!name.empty())
                    {
                        name.erase(name.end());
                    }
                    //Rendera
                    renderer->render_text(name, "seguisb.ttf", textColor, 30, 50, 30);
                    renderer->present();
                }
                else if(event.key.keysym.sym == SDLK_RETURN)
                {
                    run = false;
                }
            }
        }
    }
    SDL_StopTextInput();
    //*/
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

    renderer->render_image("space_background.png",0, 0);

    SDL_Color textColor {187, 32, 26, 255};

    renderer->render_text("High Score", "Arcade.ttf", textColor, 100, 200, 30);

    SDL_Color textColor1 {255, 255, 255, 255};

    for (int i = 0; i < 10; ++i)
    {

        renderer->render_text((patch::to_string(i + 1) + "."), "Arcade.ttf", textColor1, 30, 200, 150 + i * 40);
        renderer->render_text(patch::to_string(list_of_score[i].score), "Arcade.ttf", textColor1, 30, 270, 150 + i * 40);
        renderer->render_text(list_of_score[i].name, "Arcade.ttf", textColor1, 30, 450, 150 + i * 40);

    }
    renderer->present();

    run = true;
    SDL_Event event;
    while(run)
    {
        SDL_WaitEvent(&event);
        if (event.type == SDL_KEYDOWN)
        {
            SDL_Keycode key = event.key.keysym.sym;
            if (key == SDLK_ESCAPE)
            {
                run = false;
                break;
            }
        }
    }
}






