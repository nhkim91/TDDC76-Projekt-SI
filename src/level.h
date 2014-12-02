#ifndef LEVEL_H
#define LEVEL_H


class level
{
public:
    level() = default;
    virtual ~level() = default;

    level(const level& l);

    virtual void spawn() const = 0;

};

class level_1 : public level
{
public:
    level_1() = default;
    ~level_1();

    void spawn() const override;

};


class level_2 : public level
{
public:
    level_2() = default;
    ~level_2();

    void spawn() const override;

};


#endif // LEVEL_H
