#ifndef SPACE_INVADER_H
#define SPACE_INVADER_H
#include <vector>
#include "flying_objects.h"
#include "render.h"
#include "level.h"
#include "sound.h"
class space_invader
{
public:

    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    class player* player_;
    std::vector<flying_objects*> displaying_objects_;

    space_invader() = delete;

    ~space_invader();
    space_invader(SDL_Renderer*, render*, sound*, int, int);


    void get_objects_to_kill();
    void kill_objects(std::vector<unsigned int>);
    bool my_sort(int i, int j);
    bool collides(const flying_objects&, const flying_objects&);
    bool check_x_collides(SDL_Rect, SDL_Rect);
    bool check_y_collides(SDL_Rect, SDL_Rect);
    bool run();
    void render_things(std::vector<flying_objects*>);
    void update_things(std::vector<flying_objects*>, float);
    void add_object(flying_objects*);
    void power_up_timer_check();
    int get_score();
    void make_alien_attack();
private:
    SDL_Renderer* renderer_;
    render* render_;
    level* level_;
    int score_ {0};
    sound* sound_;

    SDL_Texture* background_texture;
    SDL_Rect background_rect;


};

#endif // SPACE_INVADER_H
