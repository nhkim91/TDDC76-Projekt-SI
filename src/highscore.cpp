#include "highscore.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//Jämför score med den redan existerande highscore-listan. Om spelaren placerar sig på listan anropas enter_name()
//och poängen sparas över till highscore-listan.
void highscore::save_score(int score)
{
    load();
    highscore_element temp;
    vector<highscore_element>::iterator it;
    int i{0};
    for (it = list_of_score.begin(); it != list_of_score.end(); it++)
    {
        if(score > list_of_score[i].score)
        {
            //Göra spelaren uppmärksam på att den har kommit med på highscore-listan?
            //Vi har samtidigt tillgång till vilken plats (i+1).
            temp.name = enter_name(); //TO DO: enter_name()
            temp.score = score;
            list_of_score.insert(it,temp);
            list_of_score.pop_back();
            write(); //TO DO: read() - spara över highscore till fil
            return;
        }
        i++;
    }
    return;
}

//Läser in ett namn från tangentbordet.
string highscore::enter_name() //Namnet ska vara ett ord.
{

}

//Läser in highscore från fil och sparar över till list_of_score.
void highscore::load()
{
    list_of_score.resize(10);
    ifstream highscore;
    highscore.open ("highscore.txt");
    highscore_element temp;

    if(highscore.is_open())
    {
        for(int i = 0; i < 10; i++)
        {
            highscore >> temp.name;
            highscore >> temp.score;
            list_of_score[i] = temp;
        }
    }
    else
    {
        return; //TO DO: Fixa felhantering.
    }
    highscore.close();
    return;
}

//Sparar över highscore till fil.
void highscore::write()
{
    ofstream highscore;
    highscore.open("highscore.txt", ios::out | ios::trunc);

    for(int i = 0; i < 10; i++)
    {
        highscore << list_of_score[i].name;
        highscore << list_of_score[i].score;
    }

    highscore.close();
    return;
}




//TO DO: show_highscore() som ska anropa load() bl.a.
