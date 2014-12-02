#include "level.h"
#include "alien.h"
#include "meteorite.h"
#include "power_up.h"
#include <vector>

using namespace std;

void level_1::spawn() const //flying_object* level::spawn()
{
    int i;
    i = rand() % 1000;
    vector<int> position(2);
    position[0] = 800; //Startposition i x-led
    position[1] = rand() % 600; //Slumpad position i y_led
    vector<int> speed(2);
    speed[1] = 0; //Hastighet i y-led
    speed[0] = 1; //Hastighet i x-led

    if(i < 100)
    {
        alien_mk1 alien_1(1,speed); //new? //return (new Minus(*this))
        return; //return alien_1*
    }

    else if(i >= 100 && i < 200)
    {
        meteorite_small meteorite_1{1,position};
        return; //return meteorite_1*
    }

    return;
}

void level_2::spawn() const //flying_object* level::spawn()
{
    int i;
    i = rand() % 800;
    vector<int> position(2);
    position[0] = 800; //Startposition i bredd
    position[1] = rand() % 600;
    vector<int> speed(2);
    speed[0] = 1; //Hastighet i x-led
    speed[1] = rand() % 1; //Hastighet i y-led

    if(i < 200)
    {
        alien_mk1 alien_1(1,position); //new? //return (new Minus(*this))
        return; //return alien_1*
    }

    else if(i >= 200 && i < 250)
    {
        meteorite_small meteorite_1{1,position};
        return; //return meteorite_1*
    }

    else if(i >= 250 && i < 270)
    {
        power_up_attack attack_{1, speed, 20};
    }

    return;
}

