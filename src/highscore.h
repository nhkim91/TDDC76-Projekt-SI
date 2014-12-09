#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <map>
#include <string>

class highscore
{
public:
    highscore() = default;
    ~highscore() = default;

    highscore(const highscore&) = default;

    void save();
    void show_highscore();

private:
    std::map<std::string, int> list_of_score;
    std::map<std::string, int>::const_iterator position;

    void load(); //Laddar in highscore till list_of_score
    std::string enter_name(); //Skriver in namn
    void read(); //Skriver över highscore till fil
    bool cmp_score(int); //Jämför score med list_of_score
};

#endif // HIGHSCORE_H
