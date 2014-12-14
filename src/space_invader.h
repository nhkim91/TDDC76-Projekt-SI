#ifndef SPACE_INVADER_H
#define SPACE_INVADER_H
#include <vector>
#include "flying_objects.h"
class space_invader
{
public:

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    class player* player_;

    space_invader() = default;
    space_invader(SDL_Renderer*);
    std::vector<flying_objects*> displaying_objects_;

    void get_objects_to_kill();
    void kill_objects(std::vector<unsigned int>);
    bool my_sort(int i, int j);
    bool collides(const flying_objects&, const flying_objects&);
    bool check_x_collides(SDL_Rect, SDL_Rect);
    bool check_y_collides(SDL_Rect, SDL_Rect);
    void run();
    void render_things(std::vector<flying_objects*>);
    void update_things(std::vector<flying_objects*>, float);
    void add_object(flying_objects*);


private:
    SDL_Renderer* renderer_;

};

#endif // SPACE_INVADER_H
