#ifndef SPACE_INVADER_H
#define SPACE_INVADER_H
#include <vector>
#include "flying_objects.h"
class space_invader
{
public:

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	// create the window
	SDL_Window* window_ = SDL_CreateWindow("SDL Testet", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer_ = SDL_CreateRenderer(window_, -1, 0);

    space_invader() = default;
    std::vector<flying_objects*> displaying_objects_;

    void get_objects_to_kill();
    void kill_objects(std::vector<unsigned int>);
    bool my_sort(int i, int j);
    bool collides(const flying_objects&, const flying_objects&);
    void run();
};

#endif // SPACE_INVADER_H
