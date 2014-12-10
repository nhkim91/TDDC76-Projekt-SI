#include "space_invader.h"
//#include "linkheader.h"
//#include "flying_objects.h"
#include "player.h"
#include "alien.h"
#include <iostream>
#include <algorithm>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

void space_invader::get_objects_to_kill()
{
	vector<unsigned int> to_delete;
	for(unsigned int i=0 ; i<displaying_objects_.size(); i++)
	{
		for(unsigned int j=i+1; j<displaying_objects_.size(); j++)
		{
			try{
				if (collides(*displaying_objects_.at(i),*displaying_objects_.at(j)))
				{
					if(displaying_objects_.at(i)->hit(*displaying_objects_.at(j)))
					{
						to_delete.push_back(i);
					}
					if(displaying_objects_.at(j)->hit(*displaying_objects_.at(i)))
					{
						to_delete.push_back(j);
					}
				}
			} catch (...) {
				cerr<<"i: "<<i<<" j: "<<j<<endl;
				throw;
			}

		}
	}
	kill_objects(to_delete);
}

void space_invader::kill_objects(vector<unsigned int> to_delete)
{
	//sorterar to_delete från större till mindre
	sort(to_delete.begin(), to_delete.end()+1, greater<int>());

	for(unsigned int i : to_delete)
	{
		try {
			displaying_objects_.erase(displaying_objects_.begin() + i);
		}catch(...) {
			cerr<<"i:"<<i<<endl;
			throw;
		}
	}
}

bool space_invader::collides(const flying_objects& obj_1, const flying_objects& obj_2)
{
	SDL_Rect a;
	SDL_Rect b;
	a=obj_1.get_rect();
	b=obj_2.get_rect();

	if (
			// is a.x inside b's x-range?
			(a.x > b.x  &&  a.x < b.x + b.w) ||
			// is a.x's other corner inside b's x-range?
			(a.x + a.w  >  b.x  &&  a.x + a.w  <  b.x + b.w)
	)
	{
		if (
				// is a.y inside b's y-range?
				(a.y > b.y  &&  a.y < b.y + b.h) ||
				// is a.y's other corner inside b's y-range?
				(a.y + a.h > b.y  &&  a.y + a.h < b.y + b.h)
		)
		{
			return true;
		}
	}
	return false;
}

void space_invader::render_things(vector<flying_objects*> render_vector)
{
	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
	SDL_RenderClear(renderer_);

	for(unsigned int i=0 ; i<render_vector.size(); i++)
	{
		SDL_RenderCopy(renderer_, render_vector.at(i)->get_texture(), nullptr, &render_vector.at(i)->get_rect());
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

	SDL_Texture* player_text{nullptr};
	SDL_Texture* alien{nullptr};
	int ballWidth{0};
	int ballHeight{0};
	{
		SDL_Surface* temp = IMG_Load("player.png");

		player_text = SDL_CreateTextureFromSurface(renderer_, temp);
		ballWidth = temp->w;
		ballHeight = temp->h;

		SDL_FreeSurface(temp);

		/*temp = IMG_Load("alien.png");
		alien = SDL_CreateTextureFromSurface(renderer_, temp);

		SDL_FreeSurface(temp);*/
	}
	// set ball position
	SDL_Rect ballRect;
	ballRect.x = 10;
	ballRect.y = 10;
	ballRect.w = ballWidth;
	ballRect.h = ballHeight;
	//int xSpeed{0};
	int ySpeed{0};

	const Uint32 target_frame_delay = 10;
	Uint32 start_time = SDL_GetTicks();
	Uint32 last_frame_time = start_time;

	// main loop
	bool running{true};
	while (running) {

		Uint32 frame_delay = SDL_GetTicks() - last_frame_time;
		float delta_time = frame_delay / 1000.0f;
		last_frame_time += frame_delay;

		// handle events
		SDL_Event event;
		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
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
					ySpeed = -10;
				}
				else if (event.key.keysym.sym == SDLK_DOWN)
				{
					ySpeed = 10;
				}
				else if(event.key.keysym.sym == SDLK_SPACE)
				{

				}
				else if(event.key.keysym.sym == SDLK_p)
				{

				}
				else if(event.key.keysym.sym == SDLK_s)
				{
					flying_objects* p1{new alien_mk2{1, 50, 50, -1, 0, renderer_}};
					displaying_objects_.push_back(p1);
					//return;
				}
			}
			else if(event.type == SDL_KEYUP){
				if (event.key.keysym.sym == SDLK_UP)
				{
					ySpeed = 0;
				}
				else if (event.key.keysym.sym == SDLK_DOWN)
				{
					ySpeed = 0;
				}
				else if(event.key.keysym.sym == SDLK_SPACE)
				{

				}
				else if(event.key.keysym.sym == SDLK_p)
				{

				}
				else if(event.key.keysym.sym == SDLK_s)
				{

				}
			}
		}

		// update things
		//	ballRect.y += ySpeed;

		//if (ballRect.y + ballHeight > SCREEN_HEIGHT || ballRect.y < 0)
		//{
		//	ySpeed = -ySpeed;
		//}

		render_things(displaying_objects_);
		// clear screen
		/*
		SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
		SDL_RenderClear(renderer_);

		// draw things
		SDL_RenderCopy(renderer_, player_text, nullptr, &ballRect);

		// show the newly drawn things
		SDL_RenderPresent(renderer_);
		 */

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
	SDL_DestroyTexture(player_text);
	player_text = nullptr;
	SDL_DestroyTexture(alien);
	alien = nullptr;
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);

	SDL_Quit();
}

void space_invader::update_things (vector<flying_objects*> update_vector, Uint32 time_diff, Uint32 time)
{
	for(unsigned int i=0 ; i<update_vector.size(); i++)
	{
		int x_temp;
		int y_temp;
		vector<unsigned int> to_delete;
		flying_objects* temp = update_vector.at(i);
		temp->set_x_pos(temp->get_x_pos() + temp->get_x_speed()*time_diff);
		y_temp = temp->get_y_pos() + temp->get_y_speed()*time_diff;

		//temp->get_rect().x + temp->get_x_speed()*time_diff;
		//temp->get_rect().y + temp->get_y_speed()*time_diff;

		if (temp->get_rect().y + temp->get_rect().h > SCREEN_HEIGHT)
		{
			if(temp->get_y_speed()>0)
			{
				temp->get_y_pos() -= temp->get_y_speed()*time_diff;
				temp->get_rect().y -= temp->get_y_speed()*time_diff;
			}
		}

		if (temp->get_rect().y < 0)
		{
			if(temp->get_y_speed()<0)
			{
				temp->get_y_pos() -= temp->get_y_speed()*time_diff;
				temp->get_rect().y -= temp->get_y_speed()*time_diff;
			}
		}

		i *ptr_;
		ptr_ = &other;

		alien* other_obj_1;
		other_obj_1 = dynamic_cast<alien*>(ptr_);
		if (other_obj_1 != nullptr)
		{
			if (temp->get_rect().x < 0)
			{
				get_player(update_vector).lose_life(1);
				to_delete.push_back(i);
			}
		}

		power_up_attack* other_obj_2;
		other_obj_2 = dynamic_cast<power_up_attack*>(ptr_);
		if (other_obj_2 != nullptr)
		{
			if (temp->get_rect().x < 0)
			{
				/* här ska i läggas till i förstörar listan */
				to_delete.push_back(i);
			}
			if(time >= temp->kill_me_when() && temp->kill_me_when() != 0)
			{
				/* här ska i läggas till i förstörar listan */
				to_delete.push_back(i);
				get_player(update_vector)->get_power_up_attack().clear();
			}
		}
		power_up_shield* other_obj_3;
		other_obj_3 = dynamic_cast<power_up_shield*>(ptr_);
		if (other_obj_3 != nullptr)
		{
			if (temp->get_rect().x < 0)
			{
				/* här ska i läggas till i förstörar listan */
				to_delete.push_back(i);
			}
			if(time >= temp->kill_me_when() && temp->kill_me_when() != 0)
			{
				/* här ska i läggas till i förstörar listan */
				to_delete.push_back(i);
				get_player(update_vector)->get_power_up_shield().clear();
			}

		}
		if (temp->get_rect().x < 0)
		{
			/* här ska i läggas till i förstörar listan */
			to_delete.push_back(i);
		}
		kill_objects(to_delete);
	}
}

player* space_invader::get_player(vector<flying_objects*> vector)
{
	for(unsigned int i=0 ; i < vector.size(); i++)
	{
		flying_objects *ptr;
		ptr = &vector.at(i);

		player* other_obj_1;
		other_obj_1 = dynamic_cast<player*>(ptr);
		if (other_obj_1 != nullptr)
		{
			return ptr;
		}
	}
	return nullptr;
}
