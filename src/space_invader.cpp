#include "space_invader.h"
#include <iostream>
#include <algorithm>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;




void space_invader::killer()
{
	vector<int> to_delete;
	for(unsigned int i=0 ; i<displaying_objects_.size(); i++)
	{
		for(unsigned int j=i+1; j<displaying_objects_.size(); j++)
		{
			if (collides(displaying_objects_.at(i),displaying_objects_.at(j)))
			{
				if(displaying_objects_.at(i).hit(displaying_objects_.at(j)))
				{
					to_delete.push_back(i);
				}
				if(displaying_objects_.at(j).hit(displaying_objects_.at(i)))
				{
					to_delete.push_back(j);
				}
			}
		}
	}

	//sorterar to_delete från större till mindre
	sort(to_delete.begin(), to_delete.end()+1, greater<int>());

	for(unsigned int i: to_delete)
	{
		displaying_objects_.erase(displaying_objects_.begin() + i);
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

void space_invader::run()
{
	// make the scaled rendering look smoother
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	// render at a virtual resolution then stretch to actual resolution
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	// load figures

	SDL_Texture* player{nullptr};
	SDL_Texture* alien{nullptr};
	int ballWidth{0};
	int ballHeight{0};
	{
		SDL_Surface* temp = IMG_Load("player.png");

		player = SDL_CreateTextureFromSurface(renderer, temp);
		ballWidth = temp->w;
		ballHeight = temp->h;

		SDL_FreeSurface(temp);

		/*temp = IMG_Load("alien.png");
		alien = SDL_CreateTextureFromSurface(renderer, temp);

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
	// main loop
	bool running{true};
	while (running) {
		// handle events
		SDL_Event event;
		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				running = false;
			}
			else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					running = false;
				}
				else if (event.key.keysym.sym == SDLK_UP) {
					ySpeed = -10;
					cerr << "upp";
				}
				else if (event.key.keysym.sym == SDLK_DOWN) {
					ySpeed = 10;
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
			}
		}

		// update things
		ballRect.y += ySpeed;

		if (ballRect.y + ballHeight > SCREEN_HEIGHT || ballRect.y < 0) {
			ySpeed = -ySpeed;
		}

		// clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// draw things
		SDL_RenderCopy(renderer, player, nullptr, &ballRect);

		// show the newly drawn things
		SDL_RenderPresent(renderer);

		// wait before drawing the next frame
		SDL_Delay(10);
	}
	// free memory
	SDL_DestroyTexture(player);
	player = nullptr;
	SDL_DestroyTexture(alien);
	alien = nullptr;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}
