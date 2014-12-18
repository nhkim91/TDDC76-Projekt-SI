/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     highscore.cpp
 * Enhetsnamn:  highscore
 * Typ:         Definitioner hörande till klassen highscore
 * Skriven av:  Kim Nguyen Hoang, kimng797, 910112-0260
 *              Kerstin Soderqvist, kerso255, 911006-0309
 *              Niclas Granström, nicgr354, 900519-5376
 *              Anton Gifvars,	antgi546, 890917-1657
 *
 * Datum:       2014-12-17
 *
 * BESKRIVNING
 *
 * Filen innehåller definitioner för klassen highscore.
 * Den har som uppgift att ha hand om highscore sedan tidigare spelade spel genom att
 * ladda in och visa highscore på skärmen, samt att då poängen, vid avslutat spel,
 * kvalificerar sig för highscore-listan, spara över detta till listan.
 */

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>

#include <fstream>
#include <sstream>
#include <iostream>

#include "highscore.h"
#include "patch.h"

using namespace std;

void highscore::set_renderer(render* rend)
{
	renderer = rend;
}

void highscore::save_score(int score)
{
	int screen_width = renderer->get_width();
	int screen_height = renderer->get_height();
	load();
	highscore_element temp;
	vector<highscore_element>::iterator it;
	int i {0};
	renderer->render_background("Astronaut.png",0,0);
	SDL_Color whiteColor {255, 255, 255, 255};
    string text3 = "Press enter to continue.";
	SDL_Event event;
	for (it = list_of_score.begin(); it != list_of_score.end(); it++)
	{
		if (score > list_of_score[i].score)
		{
			run = true;

			renderer->render_background("Astronaut.png",0,0);

			string text = "Congratulations!";
			string text2 = "You entered top 10.";
			renderer->render_text(text, "Arcade.ttf", whiteColor, screen_height/12, screen_width/2, screen_height/15);
			renderer->render_text(text2, "Arcade.ttf", whiteColor, screen_height/12, screen_width/2, screen_height/6);
            renderer->render_text(text3, "Arcade.ttf", whiteColor, screen_height/18, screen_width/2, screen_height/2+4*screen_height/9);
			renderer->present();
			while (run)
			{
				SDL_WaitEvent(&event);
				if (event.type == SDL_KEYDOWN)
				{
					SDL_Keycode key = event.key.keysym.sym;
					if (key == SDLK_RETURN || key == SDLK_RETURN2)
					{
						run = false;
						break;
					}
				}
			}

			temp.name = enter_name();
			temp.score = score;
			list_of_score.insert(it, temp);
			list_of_score.pop_back();
			write();
			show_highscore();
			return;
		}
		i++;
	}

    string text4 = "Game Over";
    renderer->render_text(text4, "Arcade.ttf", whiteColor, screen_height/4, screen_width/2, screen_height/7);
    renderer->render_text(text3, "Arcade.ttf", whiteColor, screen_height/18, screen_width/2, screen_height/2+4*screen_height/9);
	renderer->present();

    run = true;

    while (run)
    {
        SDL_WaitEvent(&event);
        if (event.type == SDL_KEYDOWN)
        {
            SDL_Keycode key = event.key.keysym.sym;
            if (key == SDLK_RETURN || key == SDLK_RETURN2)
            {
                run = false;
                break;
            }
        }
    }
}

string highscore::enter_name()
{
	int screen_width = renderer->get_width();
	int screen_height = renderer->get_height();
	string name;
	SDL_Event event;

	run = true;

    SDL_Color whiteColor {255, 255, 255, 255};

	renderer->render_background("Astronaut.png",0,0);
	string text = "Write your name. Then hit enter.";
    renderer->render_text(text, "Arcade.ttf", whiteColor, screen_height/20, screen_width/2, screen_height/15);
	renderer->present();

	while (run)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
		{
			SDL_Keycode key = event.key.keysym.sym;
			if (key == SDLK_RETURN || key == SDLK_RETURN2)
			{
				if (!name.empty())
				{
					run = false;
					break;
				}
				else
				{
					renderer->render_background("Astronaut.png",0,0);
                    renderer->render_text(text, "Arcade.ttf", whiteColor, screen_height/20, screen_width/2, screen_height/15);
				}
			}
			else if (key == SDLK_BACKSPACE)
			{
				renderer->render_background("Astronaut.png",0,0);
                renderer->render_text(text, "Arcade.ttf", whiteColor, screen_height/20, screen_width/2, screen_height/15);
				if (!name.empty())
				{
					name.erase(name.end() - 1);

					if (!name.empty())
					{
                        renderer->render_text(name, "Arcade.ttf", whiteColor, screen_height/20, screen_width/2, screen_height/10);
					}
				}
			}
			else
			{
				renderer->render_background("Astronaut.png",0,0);
                renderer->render_text(text, "Arcade.ttf", whiteColor, screen_height/20, screen_width/2, screen_height/15);
				char c = *(SDL_GetKeyName(key));
				name += c;
                renderer->render_text(name, "Arcade.ttf", whiteColor, screen_height/20, screen_width/2, screen_height/10);
			}
			renderer->present();
		}
	}

	return name;
}

void highscore::load()
{
	list_of_score.resize(10);
	ifstream hs;
	hs.open("highscore.txt");
	highscore_element temp;

	if (hs.is_open())
	{

		for (int i = 0; i < 10; i++)
		{
			hs >> temp.name;
			hs >> temp.score;
			list_of_score[i] = temp;
		}
	}
	else
	{
		cout << "Tom High Score" << endl;
		return;
	}

	hs.close();
	return;
}

void highscore::write()
{
	ofstream hs;
	hs.open("highscore.txt", ios::out | ios::trunc);


	for (int i = 0; i < 10; i++)
	{
		hs << list_of_score[i].name;
		hs << " ";
		hs << list_of_score[i].score;
		hs << " \n";
	}

	hs.close();
	return;
}

void highscore::show_highscore()
{
	int screen_width = renderer->get_width();
	int screen_height = renderer->get_height();
	load();

	renderer->render_background("Colorful_space.png", 0, 0);

	SDL_Color redColor {187, 32, 26, 255};

	renderer->render_text("High Score", "Arcade.ttf", redColor, screen_height/6, screen_width/2, screen_height/12);

	SDL_Color whiteColor {255, 255, 255, 255};

	for (int i = 0; i < 10; ++i)
	{

		renderer->render_text((patch::to_string(i + 1) + "."), "Arcade.ttf", whiteColor,
				screen_height/30, screen_width/4, screen_height/6 + i * screen_height/15);

		renderer->render_text(patch::to_string(list_of_score[i].score), "Arcade.ttf", whiteColor,
				screen_height/30, screen_height/2.2, screen_height/6 + i * screen_height/15);


		renderer->render_text(list_of_score[i].name, "Arcade.ttf", whiteColor,
				screen_height/30, screen_height/1.33, screen_height/6 + i * screen_height/15);

		renderer->render_text("Back to Menu", "Arcade.ttf", redColor,
				screen_height/15, screen_width/2, screen_height/1.1);

	}
	renderer->present();

	run = true;
	SDL_Event event;
	while (run)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
		{
			SDL_Keycode key = event.key.keysym.sym;
			if (key == SDLK_ESCAPE || key == SDLK_RETURN)
			{
				run = false;
				break;
			}
		}
	}
}

/*
 * SLUT PÅ FILEN highscore.cpp
 */
