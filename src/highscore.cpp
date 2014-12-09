#include "highscore.h"
#include <map>

using namespace std;

//Jämför score med list_of_score
bool highscore::cmp_score(int score)
{
    map<string, int>::const_iterator it;
    for (it = list_of_score.begin(); it != list_of_score.end(); it++)
    {
        if(score > it->second)
        {
            position = it;
            return true;
        }
    }
    return false;
}

//TO DO: save() ska anropa cmp_score, enter_name() och read()
//show_highscore() som ska anropa load() bl.a.
