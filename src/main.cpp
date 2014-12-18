/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     main.cpp
 * Enhetsnamn:  main
 * Typ:         Körfil
 * Skriven av:  Kim Nguyen Hoang, kimng797, 910112-0260
 *              Kerstin Soderqvist, kerso255, 911006-0309
 *              Anton Gifvars, antgi546, 890917-1657
 * 				Margareta Vi, marvi154,  920809-0309
 * 				Madeleine Ardic, madar730, 930922-4245
 *              Niclas Granström, nicgr354, 900519-5376
 *
 * Datum:       2014-12-17
 *
 * BESKRIVNING
 *
 * Härifrån körs spelet.
 *
 */

#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "space_invader.h"
#include "highscore.h"
#include "menu.h"
#include "sound.h"


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
    int SCREEN_WIDTH{1000};
    int SCREEN_HEIGHT{700};


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


    SDL_Window* window = SDL_CreateWindow("Space Invader", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
			SDL_RENDERER_PRESENTVSYNC);

	sound all_sounds = sound();
	render rend(SCREEN_WIDTH, SCREEN_HEIGHT);
	rend.set_renderer(renderer);
	all_sounds.play_background();

	highscore hs;
	hs.set_renderer(&rend);

	help h;
	h.set_renderer(&rend);

	menu m;
	m.set_renderer(&rend);
	m.set_highscore(&hs);
	m.set_help(&h);
	m.set_sound(&all_sounds);
	m.set_screen_size(SCREEN_WIDTH, SCREEN_HEIGHT);
	m.run();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	//förstör all sound
	SDL_Quit();

	return 0;
}
