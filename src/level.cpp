/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     level.cpp
 * Enhetsnamn:  level
 * Typ:         Definitioner hörande till klassen level
 * Skriven av:  Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *              Kerstin Soderqvist 911006-0309 Y3.c kerso255
 *              Niclas Granström, nicgr354, 900519-5376
 *              Anton Gifvars,	antgi546, 890917-1657
 *
 * Datum:       2014-12-17
 *
 * BESKRIVNING
 *
 * Filen innehåller deklarationer för klassen level.
 * Den har som uppgift att hålla reda på vilken nivå spelet befinner sig på,
 * och vid behov höja nivån. Den har även funktionen spawn() som slumpmässigt
 * skapar nya objekt (aliens, meteoriter, power-ups), utifrån nivån,
 * vilka senare ska visas på spelplanen.
 */

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#include "level.h"
#include "alien.h"
#include "meteorite.h"
#include "power_up.h"
#include "space_invader.h"

using namespace std;

level::level(int WIDTH, int HEIGHT, std::vector<flying_objects*>* displaying_objects_pointer, SDL_Renderer* renderer)
{
	width = WIDTH;
	height = HEIGHT;
	disp_objects_pointer = displaying_objects_pointer;
	renderer_ = renderer;
	latest_lvl_change_ = SDL_GetTicks();
}

void level::set_renderer(render* rend)
{
	rend_ = rend;
}

void level::spawn(int score)
{
	data.resize(5);
	get_next_lvl(score);


    int i = rand() % 1000;

	if (lvl == 1)
	{
		if (i < 3)
		{
			disp_objects_pointer->push_back(get_alien_mk1());
			return;
		}

        else if (i >= 3 && i < 6)
        {
            disp_objects_pointer->push_back(get_meteorite_small());
            return;
        }
    }

	else if (lvl == 2)
	{
		if (i < 4)
		{
			disp_objects_pointer->push_back(get_alien_mk1());
			return;
		}

		else if (i >= 4 && i < 8)
		{
			disp_objects_pointer->push_back(get_alien_mk2());
			return;
		}

		else if (i >= 8 && i < 12)
		{
			disp_objects_pointer->push_back(get_meteorite_small());
			return;
		}

		else if (i >= 45 && i < 48)
		{
			disp_objects_pointer->push_back(get_power_up(i));
			return;
		}
	}

	else if (lvl == 3)
	{
		if (i < 5)
		{
			disp_objects_pointer->push_back(get_alien_mk1());
			return;
		}

		else if (i >=5 && i < 10)
		{
			disp_objects_pointer->push_back(get_alien_mk2());
			return;
		}

		else if (i >= 10 && i < 15)
		{
			disp_objects_pointer->push_back(get_alien_mk3());
			return;
		}

		else if (i >=15 && i < 20)
		{
			disp_objects_pointer->push_back(get_meteorite_medium());
			return;
		}

		else if (i >= 45 && i < 54)
		{
			disp_objects_pointer->push_back(get_power_up(i));
			return;
		}
	}
	return;
}

flying_objects* level::get_alien_mk1()
{
	data[0] = 1;
	data[1] = width;
	data[2] = rand() % (height - 100);
	data[3] = -100;
	data[4] = 0;

	flying_objects* alien_1 {new alien_mk1{data[0], data[1], data[2], data[3], data[4], renderer_}};
	return alien_1;
}

flying_objects* level::get_alien_mk2()
{
    data[0] = 2;
    data[1] = width;
    data[2] = rand() % (height - 100);
    data[3] = -(rand() % 100 + 100);
    data[4] = rand() % 1;
    flying_objects* alien_2 {new alien_mk2{data[0], data[1], data[2], data[3], data[4], renderer_}};
    return alien_2;
}

flying_objects* level::get_alien_mk3()
{
    data[0] = 4;
    data[1] = width;
    data[2] = rand() % (height - 100);
    data[3] = -(rand() % 150 + 100);
    data[4] = 200;
    flying_objects* alien_3 {new alien_mk3{data[0], data[1], data[2], data[3], data[4], renderer_}};
    return alien_3;
}

flying_objects* level::get_meteorite_small()
{
    data[0] = 1;
    data[1] = width;
    data[2] = rand() % (height - 200) +100;
    data[3] = -100;
    data[4] = 0;
    flying_objects* small {new meteorite_small{data[0], data[1], data[2], data[3], data[4], renderer_}};
    return small;
}

flying_objects* level::get_meteorite_medium()
{
    data[0] = 6;
    data[1] = width;
    data[2] = rand() % (height - 200) +100;
    data[3] = -(rand() % 100 + 100);
    data[4] = 0;
    flying_objects* medium {new meteorite_medium{data[0], data[1], data[2], data[3], data[4], renderer_}};
    return medium;
}

flying_objects* level::get_power_up(int i)
{
    data[0] = 1;
    data[1] = width;
    data[2] = rand() % (height - 100);
    data[3] = -200;
    data[4] = 0;
    if (i < 48)
    {
        flying_objects* power_up_a {new power_up_attack{data[0], data[1], data[2], data[3], data[4], renderer_}};
        return power_up_a;
    }
    if (i >= 48 && i < 51)
    {
        flying_objects* power_up_l {new power_up_life{data[0], data[1], data[2], data[3], data[4], renderer_}};
        return power_up_l;
    }
    else
    {
        flying_objects* power_up_s{new power_up_shield{data[0], data[1], data[2], data[3], data[4], renderer_}};
        return power_up_s;
    }
}

void level::get_next_lvl(int score)
{
	Uint32 current_time = SDL_GetTicks();
	SDL_Color textColor {255, 255, 255, 255};

	if (lvl == 1 && latest_lvl_change_ + display_time_ > current_time)
	{
		rend_->render_text("LEVEL 1", "Arcade.ttf", textColor, height/6, width/2, height/2);
		return;
	}

    if (lvl == 1 && score > 200)
	{
		lvl++;
		latest_lvl_change_ = SDL_GetTicks();
		return;
	}
	if (lvl == 2 && latest_lvl_change_ + display_time_ > current_time)
	{
		rend_->render_text("LEVEL 2", "Arcade.ttf", textColor, height/6, width/2, height/2);
		return;
	}
    if (lvl == 2 && score > 3000)
	{
		lvl++;
		latest_lvl_change_ = SDL_GetTicks();
		return;
	}
	else if (lvl == 3 && latest_lvl_change_ + display_time_ > current_time)
	{
		rend_->render_text("LEVEL 3", "Arcade.ttf", textColor, height/6, width/2, height/2);
	}
	return;
}

/*
 * SLUT PÅ FILEN level.cpp
 */
