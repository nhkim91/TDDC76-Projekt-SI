#ifndef LEVEL_H
#define LEVEL_H
#include <vector>


class level
{
public:
    level() = default;
    ~level() = default;

    level(const level& l);

    virtual void spawn();


private:

    std::vector<int>position(2);
    position[0] = 100; //Startposition i bredd
};

class level_1 : public level
{
public:
    level_1() = default;
    ~level_1();

};


class level_2 : public level
{
public:
    level_2() = default;
    ~level_2();

};


#endif // LEVEL_H

