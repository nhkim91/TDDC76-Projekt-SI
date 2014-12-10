#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <string>
#include <vector>

class highscore
{
public:
    highscore();
    ~highscore() = default;

    highscore(const highscore&) = default;

    void save_score(int);
    void show_highscore();

private:
    struct highscore_element
    {
        std::string name;
        int score;
    };

    std::vector<highscore_element> list_of_score;

    void load(); //Laddar in highscore till list_of_score.
    std::string enter_name(); //Tar in ett namn från tangentbordet.
    void write(); //Skriver över highscore till fil.
};

#endif // HIGHSCORE_H
