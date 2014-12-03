#include "level.h"
#include "alien.h"
#include "meteorite.h"
#include "power_up.h"
#include <vector>

using namespace std;

flying_objects* level::spawn(int score)
{
    get_next_lvl(score);

    int i = rand() % 1000;

    if(lvl == 1)
    {
        if(i < 100)
        {
            return get_alien_mk1();
        }

        else if(i >= 100 && i < 200)
        {
            return get_meteorite_small();
        }
    }

    else if(lvl == 2)
    {
        if(i < 100)
        {
            return get_alien_mk1();
        }

        else if(i >= 100 && i < 200)
        {
            return get_alien_mk2();
        }

        else if(i >= 200 && i < 300)
        {
            return get_meteorite_small();
        }

        else if(i >= 300 && i < 360)
        {
            return get_power_up(i);
        }
    }
    return 0;
}

flying_objects* level::get_alien_mk1()
{
    data[0] = 1;
    data[1] = 800;
    data[2] = rand() % 500;
    data[3] = 1; //Hastighet i x-led
    data[4] = 0;

    alien_mk1 alien(data[0], data[1], data[2], data[3], data[4]);
    flying_objects* alien_1 = static_cast<flying_objects*>(&alien);
    return alien_1;
}

flying_objects* level::get_alien_mk2()
{
    data[0] = 2;
    data[1] = 800;
    data[2] = rand() % 500;
    data[3] = rand() % 2 +1; //Hastighet i x-led
    data[4] = rand() % 1;


    alien_mk2 alien(data[0], data[1], data[2], data[3], data[4]);
    flying_objects* alien_2 = static_cast<flying_objects*>(&alien);
    return alien_2;
}

flying_objects* level::get_alien_mk3()
{
    data[0] = 4;
    data[1] = 800;
    data[2] = rand() % 500;
    data[3] = rand() % 4 +2; //Hastighet i x-led
    data[4] = rand() % 2;

    alien_mk3 alien(data[0], data[1], data[2], data[3], data[4]);
    flying_objects* alien_3 = static_cast<flying_objects*>(&alien);
    return alien_3;
}

flying_objects* level::get_meteorite_small()
{
    data[0] = 1;
    data[1] = 800;
    data[2] = rand() % 600; //(600 - meteoritens höjd)
    data[3] = 1; //Hastighet i x-led
    data[4] = 0;

    meteorite_small meteorite{data[0], data[1], data[2], data[3], data[4]};
    flying_objects* small = static_cast<flying_objects*>(&meteorite);
    return small;
}

flying_objects* level::get_power_up(int i)
{
    data[0] = 1;
    data[1] = 800;
    data[2] = rand() % 600; //(600 - power_upens höjd)
    data[3] = 1; //Hastighet i x-led
    data[4] = 0;

    if(i < 320)
    {
        power_up_attack power_up{data[0], data[1], data[2], data[3], data[4]};
        flying_objects* attack = static_cast<flying_objects*>(&power_up);
        return attack;
    }
    else if(i >= 320 && i < 340)
    {
        power_up_life power_up{data[0], data[1], data[2], data[3], data[4]};
        flying_objects* life = static_cast<flying_objects*>(&power_up);
        return life;
    }
    else
    {
        power_up_shield power_up{data[0], data[1], data[2], data[3], data[4]};
        flying_objects* shield = static_cast<flying_objects*>(&power_up);
        return shield;
    }
}


void level::get_next_lvl(int score)
{
    if(lvl == 1 && score > 100)
    {
        lvl++;
        return;
    }
    else if(lvl == 2 && score > 300)
    {
        lvl++;
        return;
    }
    return;
}
