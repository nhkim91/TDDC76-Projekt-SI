/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     menu.cpp
 * Enhetsnamn:  menu
 * Typ:         Definitioner hörande till klassen menu
 * Skriven av:  Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *              Kerstin Soderqvist 911006-0309 Y3.c kerso255
 * Datum:       2014-12-xx
 *
 * BESKRIVNING
 *
 * Filen innehåller deklarationer för klassen menu.
 * Denna klass har hand om menyn, vilken är det första som visas när vi kör programmet.
 * I menyn kan man välja att spela spelet, visa highscore, se hjälpinstruktioner eller avsluta spelet.
 * Med andra ord är det den som knyter ihop de andra klasserna och anropandet av deras funktioner.
 */

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#include "menu.h"
#include <iostream>
#include "sound.h"

void menu::set_renderer(render* rend)
{
	renderer = rend;
}

void menu::set_play(space_invader* _space_invader)
{
	si = _space_invader;
}

void menu::set_highscore(highscore* highscore_)
{
	hs = highscore_;
}

void menu::set_help(help* help_)
{
	h = help_;
}

void menu::set_sound(sound* sound_)
{
	snd = sound_;
}

void menu::set_screen_size(int width, int height)
{
	screen_width = width;
	screen_height = height;
}

void menu::run()
{
	//si = new space_invader{renderer->get_renderer(), renderer};
	//set_play(SI);

	bool loop {true};
	SDL_Event event;

	render_menu();

	while (loop)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
		{
			loop = false;
		}
		if (event.type == SDL_KEYDOWN)
		{
			SDL_Keycode key = event.key.keysym.sym;
			if (key == SDLK_DOWN)
			{
				++selected_item;
				if (selected_item > 3)
				{
					selected_item = 0;
				}
			}
			else if (key == SDLK_UP)
			{
				--selected_item;



				if (selected_item < 0)
				{
					selected_item = 3;
				}
			}
			else if (key == SDLK_ESCAPE)
			{
				loop = false;
			}
			else if (key == SDLK_RETURN || key == SDLK_RETURN2)
			{
				if (selected_item == 0)
				{
					if (si == nullptr)
					{
						si = new space_invader {renderer->get_renderer(), renderer, snd, screen_width, screen_height};
					}
					if (si->run())
					{
						hs->save_score(si->get_score());
						delete si;
						si = nullptr;
					}


					//int score = si->run();
					//hs->save_score(score);
				}
				else if (selected_item == 1)
				{
					hs->show_highscore();
				}
				else if (selected_item == 2)
				{
					h->show_help();
				}
				else if (selected_item == 3)
				{
					loop = false;
				}
				else
				{
					//TODO: ERROR
				}
			}
			render_menu();
		}
	}
}


void menu::render_menu()
{
	SDL_Color whiteColor {255, 255, 255, 255};
	SDL_Color redColor {187, 32, 26, 255};

	renderer->render_background("space_background.png", 0, 0);
	renderer->render_text("Space Invader", "Arcade.ttf", whiteColor, screen_height/6, screen_width/2, screen_height/7);

	if (selected_item == 0)
	{
		renderer->render_text("Play", "Arcade.ttf", redColor, screen_height/12, screen_width/2, screen_height*0.475);
		renderer->render_text("High Score", "Arcade.ttf", whiteColor, screen_height/12, screen_width/2, screen_height*0.558);
		renderer->render_text("Help", "Arcade.ttf", whiteColor, screen_height/12, screen_width/2, screen_height*0.642);
		renderer->render_text("Quit", "Arcade.ttf", whiteColor, screen_height/12, screen_width/2, screen_height*0.725);
	}
	else if (selected_item == 1)
	{
		renderer->render_text("Play", "Arcade.ttf", whiteColor, screen_height/12, screen_width/2, screen_height*0.475);
		renderer->render_text("High Score", "Arcade.ttf", redColor, screen_height/12, screen_width/2, screen_height*0.558);
		renderer->render_text("Help", "Arcade.ttf", whiteColor, screen_height/12, screen_width/2, screen_height*0.642);
		renderer->render_text("Quit", "Arcade.ttf", whiteColor, screen_height/12, screen_width/2, screen_height*0.725);
	}
	else if (selected_item == 2)
	{
		renderer->render_text("Play", "Arcade.ttf", whiteColor, screen_height/12, screen_width/2, screen_height*0.475);
		renderer->render_text("High Score", "Arcade.ttf", whiteColor, screen_height/12, screen_width/2, screen_height*0.558);
		renderer->render_text("Help", "Arcade.ttf", redColor, screen_height/12, screen_width/2, screen_height*0.642);
		renderer->render_text("Quit", "Arcade.ttf", whiteColor, screen_height/12, screen_width/2, screen_height*0.725);
	}
	else if (selected_item == 3)
	{
		renderer->render_text("Play", "Arcade.ttf", whiteColor, screen_height/12, screen_width/2, screen_height*0.475);
		renderer->render_text("High Score", "Arcade.ttf", whiteColor, screen_height/12, screen_width/2, screen_height*0.558);
		renderer->render_text("Help", "Arcade.ttf", whiteColor, screen_height/12, screen_width/2, screen_height*0.642);
		renderer->render_text("Quit", "Arcade.ttf", redColor, screen_height/12, screen_width/2, screen_height*0.725);
	}

	renderer->present();
}

/*
 * SLUT PÅ FILEN menu.cpp
 */
