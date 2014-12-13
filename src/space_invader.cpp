#include "space_invader.h"
#include "linkheader.h"
#include "flying_objects.h"
//#include "player.h"
//#include "alien.h"
#include <iostream>
#include <algorithm>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

space_invader::space_invader(SDL_Renderer* renderer)
{
    renderer_ = renderer;
}

void space_invader::get_objects_to_kill()
{
	vector<unsigned int> to_delete;
	for (unsigned int i = 0; i  < displaying_objects_.size(); i++)
	{
		for (unsigned int j = i + 1; j < displaying_objects_.size(); j++)
		{

			try
			{
				if (collides(*displaying_objects_.at(i),
						*displaying_objects_.at(j)))
				{

					if (displaying_objects_.at(j)->hit(
							*displaying_objects_.at(i)))
					{
						cerr << "där!";
						to_delete.push_back(j);
					}
					if (displaying_objects_.at(i)->hit(
							*displaying_objects_.at(j)))
					{
						cerr << "här";
						to_delete.push_back(i);
					}
				}
			}
			catch (...)
			{
				cerr << "i: " << i << " j: " << j << endl;
				throw;
			}

		}
	}
	for(unsigned int i : to_delete)
	{

		cerr << i << endl;
	}

	kill_objects(to_delete);
}

void space_invader::kill_objects(vector<unsigned int> to_delete)
{

	//sorterar to_delete fr�n st�rre till mindre
	for (unsigned int i : to_delete)
	{
		cerr << i << endl;
	}

	sort(to_delete.begin(), to_delete.end(), greater<int>());

	if (to_delete.size() > 0)
	{
		cerr << "innan med delete\n";
	}


	for (unsigned int i : to_delete)
	{
		try
		{
			cerr << i << endl;
			displaying_objects_.erase(displaying_objects_.begin() + i);
		}
		catch (...)
		{
			cerr << "i:" << i << endl;
			throw;
		}
	}
	if (to_delete.size() > 0)
	{
		cerr << "klar med delete";
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
		collide_x = check_x_collides(a,b);
	}
	else
	{
		collide_x = check_x_collides(b,a);
	}

	if(collide_x)
	{
		if(a.h <= b.h)
		{
			collide_y = check_y_collides(a,b);
		}
		else
		{
			collide_y = check_y_collides(b,a);
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
	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
	SDL_RenderClear(renderer_);

	for (unsigned int i = 0; i < render_vector.size(); i++)
	{
		SDL_RenderCopy(renderer_, render_vector.at(i)->get_texture(), nullptr,
				&render_vector.at(i)->get_rect());
	}

	SDL_RenderPresent(renderer_);
}

void space_invader::run()
{
	// make the scaled rendering look smoother
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	// render at a virtual resolution then stretch to actual resolution
	SDL_RenderSetLogicalSize(renderer_, SCREEN_WIDTH, SCREEN_HEIGHT);
	// load figures


	const Uint32 target_frame_delay = 10;
	Uint32 start_time = SDL_GetTicks();
	Uint32 last_frame_time = start_time;

	const Uint8* keystate;
	keystate = SDL_GetKeyboardState(NULL);
	flying_objects* pp3 {new player{10, 0, 300, 0, 0, renderer_}};
	displaying_objects_.push_back(pp3);

	player* player_ptr;
	player_ptr=dynamic_cast<player*>(pp3);
	player_ = player_ptr;
	// main loop
	bool running { true };
	while (running)
	{

		Uint32 frame_delay = SDL_GetTicks() - last_frame_time;
		float delta_time = frame_delay / 1000.0f;
		//cerr << delta_time << endl;
		last_frame_time += frame_delay;

		player_->set_y_speed(0);
		SDL_PumpEvents();

		// handle events
		SDL_Event event;


		if(keystate[SDL_SCANCODE_RETURN])
		{
            /*
			flying_objects* p3 {new player{10, 0, 300, 0, 0, renderer_}};
			displaying_objects_.push_back(p3);

			player* player_ptr;
			player_ptr=dynamic_cast<player*>(p3);
			player_ = player_ptr;
            */
		}

		if(keystate[SDL_SCANCODE_ESCAPE])
		{
			//running = false;
		}

		if(keystate[SDL_SCANCODE_SPACE])
		{
			add_object(player_->attack());

		}

		if(keystate[SDL_SCANCODE_UP])
		{
			player_->set_y_speed(-100);
		}

		if(keystate[SDL_SCANCODE_DOWN])
		{
			player_->set_y_speed(100);
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
				else if (event.key.keysym.sym == SDLK_UP)
				{

				}
				else if (event.key.keysym.sym == SDLK_DOWN)
				{

				}
				else if (event.key.keysym.sym == SDLK_SPACE)
				{
					//vector<unsigned int> to_kill;
					//displaying_objects_.erase(displaying_objects_.begin());

				}
				else if (event.key.keysym.sym == SDLK_p)
				{
					flying_objects* p6 {new power_up_attack {1, 500, 400, -100, 0, renderer_}};
					displaying_objects_.push_back(p6);
				}
				else if (event.key.keysym.sym == SDLK_s)
				{
					flying_objects* p1 { new alien_mk2 { 1, 500, 400, -100, 0,
						renderer_}};
					displaying_objects_.push_back(p1);
					//return;
				}
				else if (event.key.keysym.sym == SDLK_u)
				{
					flying_objects* p3 {new player{10, 0, 300, 0, 0, renderer_}};
					displaying_objects_.push_back(p3);
				}
				else if (event.key.keysym.sym == SDLK_l)
				{
					cerr << player_->get_life() << " " <<
							displaying_objects_.size() << endl;
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.sym == SDLK_UP)
				{

				}
				else if (event.key.keysym.sym == SDLK_DOWN)
				{

				}
				else if (event.key.keysym.sym == SDLK_SPACE)
				{

				}
				else if (event.key.keysym.sym == SDLK_p)
				{

				}
				else if (event.key.keysym.sym == SDLK_s)
				{

				}
			}
		}

		get_objects_to_kill();
		update_things(displaying_objects_, delta_time);
		render_things(displaying_objects_);

		// wait before drawing the next frame
		frame_delay = SDL_GetTicks() - last_frame_time;
		if (target_frame_delay > frame_delay)
		{
			Uint32 sleep_time = target_frame_delay - frame_delay;
			SDL_Delay(sleep_time);
		}

		//SDL_Delay(10);
	}

	// free memory

	SDL_DestroyRenderer(renderer_);
    //SDL_DestroyWindow(window_);

	SDL_Quit();
}



void space_invader::update_things(vector<flying_objects*> update_vector, float time_diff)
{

	vector<unsigned int> to_delete;
	for (unsigned int i = 0; i < update_vector.size(); i++)
	{
		flying_objects* temp = update_vector.at(i);
		int new_x_speed, new_y_speed;

		new_x_speed = temp->get_x_speed() * time_diff;
		new_y_speed = temp->get_y_speed() * time_diff;

		temp->set_x_pos(new_x_speed + temp->get_x_pos());
		temp->set_y_pos(new_y_speed + temp->get_y_pos());

		temp->get_rect().x = temp->get_x_pos();
		temp->get_rect().y = temp->get_y_pos();



		///Uppe och nere////
		if (temp->get_y_pos() + temp->get_rect().h > SCREEN_HEIGHT)
		{
			temp->set_y_pos(temp->get_y_pos() - temp->get_y_speed() * time_diff);
		}
		else
		{
			temp->get_rect().y = temp->get_y_pos();
		}

		if (temp->get_y_pos() < 0)
		{
			temp->set_y_pos(temp->get_y_pos() - temp->get_y_speed() * time_diff);
		}
		else
		{
			temp->get_rect().y = temp->get_y_pos();
		}
		///////////////////////////////////


		alien* alien_ptr;
		alien_ptr = dynamic_cast<alien*>(temp);
		if (alien_ptr != nullptr)
		{
			if (temp->get_x_pos() + temp->get_rect().w < 0)
			{
				player_->increase_life(-1);
				//cerr << "hit";
				to_delete.push_back(i);
			}
		}

		else if (temp->get_x_pos() + temp->get_rect().w < 0 ||
				temp->get_x_pos() + temp->get_rect().w > SCREEN_WIDTH)
		{
			to_delete.push_back(i);
		}
	}
	for (unsigned int i : to_delete)
	{
		cerr << i << endl;
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


