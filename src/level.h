#ifndef LEVEL_H_
#define LEVEL_H_
#include <vector>



class level
{
public:
    level() = default;
    virtual ~level() = default;

    level(const level& l);

    virtual void spawn();


};

class level_1 : public level
{
public:
    level_1() = default;
    ~level_1();

    void spawn();
};


class level_2 : public level
{
public:
    level_2() = default;
    ~level_2();

};


#endif // LEVEL_H
