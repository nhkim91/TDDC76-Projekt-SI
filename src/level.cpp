#include "level.h"
#include "alien.h"
#include <vector>

using namespace std;

void level::spawn()
{
    int i;
    i = rand();
    vector<int> position{2};
    position[0] = 100; //Startposition i bredd

    position[1] = rand()/600;

    if(i < 100)
    {
        alien_mk1 alien_1(1,position);
    }

}
