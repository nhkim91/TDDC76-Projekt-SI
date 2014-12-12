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
char *highscore::enter_name() //Namnet ska vara ett ord.
{

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

    //list_of_score[0].score = 99999;


    for (int i = 0; i < 10; i++)
    {
        hs << list_of_score[i].name;
        hs << " ";
        hs << list_of_score[i].score;
        hs << " ";
    }

    hs.close();
    return;
}


void highscore::show_highscore()
{
    load();
    SDL_Color textColor{187, 32, 26, 255};

    renderer->render_text("High Score","Arcade.ttf",textColor, 100, 200, 30);

    SDL_Color textColor1{255, 255, 255, 255};

    for(int i = 0; i < 10; ++i)
    {

        renderer->render_text((patch::to_string(i+1) + "."),"Arcade.ttf",textColor1, 30, 200, 150 + i*40);
        renderer->render_text(patch::to_string(list_of_score[i].score),"Arcade.ttf",textColor1, 30, 270, 150 + i*40);
        renderer->render_text(list_of_score[i].name,"Arcade.ttf",textColor1, 30, 450, 150 + i*40);

    }
    renderer->present();
}






