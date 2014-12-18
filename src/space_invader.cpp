/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     space_invader.cpp
 * Enhetsnamn:  space_invader
 * Typ:         Definitionsfil för space_invader
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
 * Härifrån styrs spelet.
 *
 */

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#include <iostream>
#include <algorithm>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "space_invader.h"
#include "level.h"
#include "time.h"
#include "patch.h"
#include "sound.h"
#include "linkheader.h"
#include "flying_objects.h"
using namespace std;

space_invader::space_invader(SDL_Renderer* renderer, render* rend, sound* sound,
		int screen_width, int screen_height)
{
	SCREEN_WIDTH = screen_width;
	SCREEN_HEIGHT = screen_height;
	level_ = new level {SCREEN_WIDTH, SCREEN_HEIGHT, &displaying_objects_, renderer};
	level_->set_renderer(rend);
	renderer_ = renderer;
	render_ = rend;
	sound_ = sound;
	flying_objects* pp3 {new player{3, 0, 300, 0, 0, renderer_, sound_}};
	displaying_objects_.push_back(pp3);

	player* player_ptr;
	player_ptr = dynamic_cast<player*>(pp3);
	player_ = player_ptr;

    //Laddar in och skapar en textur för spelbakgrunden.
	string imageFile{"dark_space.png"};
	SDL_Surface* background_surf = IMG_Load(imageFile.c_str());
	background_texture = SDL_CreateTextureFromSurface(renderer_, background_surf);
	if (background_texture == nullptr)
	{
        cout << "Error, kan inte skapa en textur till bakgrundsbilden." << endl;
	}

	background_rect.x = 0;
	background_rect.y = 0;
	background_rect.w = background_surf->w;
	background_rect.h = background_surf->h;

	SDL_FreeSurface(background_surf);
}

space_invader::~space_invader()
{
	delete player_;
	delete level_;
	displaying_objects_.clear();
	SDL_DestroyTexture(background_texture);
}

void space_invader::power_up_timer_check()
{
	if (player_->get_power_up_attack() != nullptr)
	{
		if (player_->get_power_up_attack()->times_up())
		{
            player_->clear_power_up_attack();
		}
	}

	if (player_->get_power_up_shield() != nullptr)
	{
		if (player_->get_power_up_shield()->times_up())
		{
			player_->clear_power_up_shield();
			player_->set_special(false);
		}
	}
	return;
}

void space_invader::get_objects_to_kill()
{
	vector<unsigned int> to_delete;
	for (unsigned int i = 0; i  < displaying_objects_.size(); i++)
	{
		for (unsigned int j = i + 1; j < displaying_objects_.size(); j++)
		{

			if (collides(*displaying_objects_.at(i),
					*displaying_objects_.at(j)))
			{

				if (displaying_objects_.at(j)->hit(
						*displaying_objects_.at(i)))
				{
					to_delete.push_back(j);
				}
				if (displaying_objects_.at(i)->hit(
						*displaying_objects_.at(j)))
				{
					to_delete.push_back(i);
				}
			}
		}
	}

	kill_objects(to_delete);
}

void space_invader::kill_objects(vector<unsigned int> to_delete)
{
	if (to_delete.size() != 0)
	{
		sort(to_delete.begin(), to_delete.end(), greater<int>());
		to_delete.erase(unique(to_delete.begin(), to_delete.end()), to_delete.end());
	}
	for (unsigned int i : to_delete)
	{
		score_ += displaying_objects_.at(i)->get_score();
		displaying_objects_.erase(displaying_objects_.begin() + i);
	}
}

bool space_invader::collides(const flying_objects& obj_1,
		const flying_objects& obj_2)
{
	SDL_Rect a;
	SDL_Rect b;
	a = obj_1.get_rect();
	b = obj_2.get_rect();

	bool collide_x = false;
	bool collide_y = false;

	if (a.w <= b.w)
	{
		collide_x = check_x_collides(a, b);
	}
	else
	{
		collide_x = check_x_collides(b, a);
	}

	if (collide_x)
	{
		if (a.h <= b.h)
		{
			collide_y = check_y_collides(a, b);
		}
		else
		{
			collide_y = check_y_collides(b, a);
		}
	}
	return (collide_y);
}

bool space_invader::check_x_collides(SDL_Rect a, SDL_Rect b)
{
	return (
			// is a.x inside b's x-range?
			(a.x > b.x && a.x < b.x + b.w) ||
			// is a.x's other corner inside b's x-range?
			(a.x + a.w > b.x && a.x + a.w < b.x + b.w));
}

bool space_invader::check_y_collides(SDL_Rect a, SDL_Rect b)
{
	return (
			// is a.y inside b's y-range?
			(a.y > b.y && a.y < b.y + b.h) ||
			// is a.y's other corner inside b's y-range?
			(a.y + a.h > b.y && a.y + a.h < b.y + b.h));
}

void space_invader::render_things(vector<flying_objects*> render_vector)
{
	SDL_Color whiteColor {255, 255, 255, 255};

	int offset {SCREEN_WIDTH/16};

	for (unsigned int i = 0; i < render_vector.size(); i++)
	{
		render_->render_flying_object(render_vector.at(i));
	}

	render_->render_power_up(player_->get_power_up_attack(), player_->get_power_up_shield());

	for (unsigned int i = 0; i < player_->get_life(); i++)
	{
		render_->render_image("power_up_life.png", (SCREEN_WIDTH/4 + i * offset), SCREEN_HEIGHT/60);
	}

	render_->render_text("Score: " + patch::to_string(score_), "Arcade.ttf", whiteColor, SCREEN_HEIGHT/15, 5*SCREEN_WIDTH/8, SCREEN_HEIGHT/20);

	SDL_RenderPresent(renderer_);
	SDL_RenderClear(renderer_);
}

bool space_invader::run()
{
	// make the scaled rendering look smoother
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	// render at a virtual resolution then stretch to actual resolution
	SDL_RenderSetLogicalSize(renderer_, SCREEN_WIDTH, SCREEN_HEIGHT);


	const Uint32 target_frame_delay = 10;
	Uint32 start_time = SDL_GetTicks();
	Uint32 last_frame_time = start_time;

	const Uint8* keystate;
	keystate = SDL_GetKeyboardState(NULL);

	//För att slumpningen av monster ska få olika utfall.
    srand(time(0));

	// main loop
	bool dead {false};
	bool running { true };

	while (running)
	{
		if (player_->get_life() <= 0)
		{
			dead = true;
			return dead;
		}

		Uint32 frame_delay = SDL_GetTicks() - last_frame_time;
		float delta_time = frame_delay / 1000.0f;
		last_frame_time += frame_delay;

		player_->set_y_speed(0);
		SDL_PumpEvents();

		// handle events
		SDL_Event event;

		if (keystate[SDL_SCANCODE_SPACE])
		{
			add_object(player_->attack());
		}

		if (keystate[SDL_SCANCODE_UP])
		{
			player_->set_y_speed(-250);
		}

		if (keystate[SDL_SCANCODE_DOWN])
		{
			player_->set_y_speed(250);
		}

		while (SDL_PollEvent(&event))
		{

			if (event.type == SDL_QUIT)
			{
				running = false;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}
				else if (event.key.keysym.sym == SDLK_m)
				{
					sound_->sound_paused();
				}
			}
		}

		get_objects_to_kill();

		update_things(displaying_objects_, delta_time);

        render_->render_game_background(background_texture, &background_rect);

		level_->spawn(score_);

		render_things(displaying_objects_);

		power_up_timer_check();

		// wait before drawing the next frame
		frame_delay = SDL_GetTicks() - last_frame_time;

		if (target_frame_delay > frame_delay)
		{
			Uint32 sleep_time = target_frame_delay - frame_delay;
			SDL_Delay(sleep_time);
		}

		make_alien_attack();
	}

	return dead;
}

void space_invader::update_things(vector<flying_objects*> update_vector, float time_diff)
{
	vector<unsigned int> to_delete;
	for (unsigned int i = 0; i < update_vector.size(); i++)
	{
		flying_objects* temp = update_vector.at(i);
		int new_x_speed, new_y_speed;

		alien_mk3* ptr;
		ptr = dynamic_cast<alien_mk3*>(temp);
		if (ptr != nullptr)
		{
			new_y_speed = ptr->get_y_speed() * time_diff;
		}
		else
		{
			new_y_speed = temp->get_y_speed() * time_diff;
		}

		new_x_speed = temp->get_x_speed() * time_diff;

		temp->set_x_pos(new_x_speed + temp->get_x_pos());
		temp->set_y_pos(new_y_speed + temp->get_y_pos());

		temp->get_rect().x = temp->get_x_pos();
		temp->get_rect().y = temp->get_y_pos();

		///Uppe och nere////
		if (temp->get_y_pos() + temp->get_rect().h > SCREEN_HEIGHT)
		{
			temp->set_y_pos(temp->get_y_pos() - new_y_speed);
		}
		else
		{
			temp->get_rect().y = temp->get_y_pos();
		}

		if (temp->get_y_pos() < 0)
		{
			temp->set_y_pos(temp->get_y_pos() - new_y_speed);
		}
		else
		{
			temp->get_rect().y = temp->get_y_pos();
		}

		alien* alien_ptr;
		alien_ptr = dynamic_cast<alien*>(temp);
		if (alien_ptr != nullptr)
		{
			if (temp->get_x_pos() + temp->get_rect().w < 0)
			{
				player_->increase_life(-1);
				to_delete.push_back(i);
			}
		}

		else if (temp->get_x_pos() + temp->get_rect().w < 0 ||
				temp->get_x_pos() > SCREEN_WIDTH + temp->get_rect().w)
		{
			to_delete.push_back(i);
		}
	}

	kill_objects(to_delete);
}

void space_invader::add_object(flying_objects* ptr)
{
	if (ptr != nullptr)
	{
		displaying_objects_.push_back(ptr);
	}
	return;
}

int space_invader::get_score()
{
	return score_;
}

void space_invader::make_alien_attack()
{
	int shoot_if;

	for (unsigned int i = 0; i < displaying_objects_.size(); i++)
	{
		alien_mk3* other_obj;
		other_obj = dynamic_cast<alien_mk3*>(displaying_objects_.at(i));
		if (other_obj != nullptr)
		{
			shoot_if = rand() % 200;
			if (shoot_if == 1)
			{
				add_object(other_obj->attack());

			}
		}
	}
}
