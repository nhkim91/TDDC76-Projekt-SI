#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <SDL2/SDL_main.h>
#include "space_invader.h"
#include "highscore.h"
#include "menu.h"
#include "sound.h"
#include <SDL2/SDL_mixer.h>

#include<sstream>

using namespace std;


template <typename T>
std::string to_string(T value)
{
    //create an output string stream
    std::ostringstream os ;

    //throw the value into the string stream
    os << value ;

    //convert the string stream into a string and return
    return os.str() ;
}

int main(int, char**)
{
    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        cerr << "Error initializing SDL" << endl;
        exit(1);
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2 , 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
    Mix_AllocateChannels(16);


    SDL_Window* window = SDL_CreateWindow("Highscore", SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                             SDL_RENDERER_PRESENTVSYNC);


    sound all_sounds = sound();
    render rend;
    rend.set_renderer(renderer);

    space_invader SI(renderer, &rend, &all_sounds);

    //space_invader SI(renderer, &rend);

    //SI.run(); // TODO: Bra om space_invader retunerar score.

    highscore hs;
    hs.set_renderer(&rend);

    help h;
    h.set_renderer(&rend);





    menu m;
    m.set_renderer(&rend);
    m.set_highscore(&hs);
    m.set_help(&h);
    m.set_sound(&all_sounds);
    //m.set_play(&SI);
    m.run();



    // free memory


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}

