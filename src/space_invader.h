#ifndef SPACE_INVADER_H
#define SPACE_INVADER_H
#include <vector>
#include "flying_objects.h"

class space_invader
{
public:
    space_invader();
    std::vector<flying_objects> displaying_objects_;

    void killer();
    bool my_sort(int i, int j);
    bool collides(const flying_objects&, const flying_objects&);

};

#endif // SPACE_INVADER_H
