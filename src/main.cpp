
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include <SDL2_image/SDL_image.h>  //<- maggie behöver denna!
#include <SDL2/SDL_main.h>


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

using namespace std;


bool collides(const SDL_Rect& a, const SDL_Rect& b)
{
	if (
			// is a.x inside b's x-range?
			(a.x        >  b.x  &&  a.x        <  b.x + b.w) ||
			// is a.x's other corner inside b's x-range?
			(a.x + a.w  >  b.x  &&  a.x + a.w  <  b.x + b.w)
			) {
		if (
				// is a.y inside b's y-range?
				(a.y        >  b.y  &&  a.y        <  b.y + b.h) ||
				// is a.y's other corner inside b's y-range?
				(a.y + a.h  >  b.y  &&  a.y + a.h  <  b.y + b.h)
				) {
			return true;
		}
	}
	return false;
}


int main(int argc, char *argv[]) {
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cerr << "Error initializing SDL" << endl;
		exit(1);
	}

	// create the window
	SDL_Window* window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	// make the scaled rendering look smoother
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	// render at a virtual resolution then stretch to actual resolution
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	// load ball
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

		temp = IMG_Load("alien.png");
		alien = SDL_CreateTextureFromSurface(renderer, temp);
		SDL_FreeSurface(temp);
	}

	// set ball position
	SDL_Rect ballRect;
	ballRect.x = 10;
	ballRect.y = 10;
	ballRect.w = ballWidth;
	ballRect.h = ballHeight;
	int xSpeed{10};
	int ySpeed{10};

	SDL_Rect mouseRect{
		-100,
		-100,
		ballWidth,
		ballHeight
	};

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
				else if (event.key.keysym.sym == SDLK_x) {
					xSpeed = -xSpeed;
				}
				else if (event.key.keysym.sym == SDLK_y) {
					ySpeed = -ySpeed;
				}
			}
			else if (event.type == SDL_MOUSEMOTION) {
				mouseRect.x = event.motion.x - (ballWidth/2);
				mouseRect.y = event.motion.y - (ballHeight/2);
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				ballRect.x = event.button.x - (ballWidth/2);
				ballRect.y = event.button.y - (ballHeight/2);
			}
		}

		// update things
		if(collides(mouseRect, ballRect)) {
			xSpeed = -xSpeed;
			ySpeed = -ySpeed;
		}
		ballRect.x += xSpeed;
		ballRect.y += ySpeed;

		if (ballRect.x + ballWidth > SCREEN_WIDTH || ballRect.x < 0) {
			xSpeed = -xSpeed;
		}
		if (ballRect.y + ballHeight > SCREEN_HEIGHT || ballRect.y < 0) {
			ySpeed = -ySpeed;
		}

		// clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// draw things
		SDL_RenderCopy(renderer, player, nullptr, &ballRect);
		SDL_RenderCopy(renderer, alien, nullptr, &mouseRect);

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
	return 0;
}
/*
=======
#include <iostream>
#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <SDL2_image/SDL_image.h>

#include <SDL2/SDL_main.h>


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

using namespace std;


bool collides(const SDL_Rect& a, const SDL_Rect& b)
{
	if (
			// is a.x inside b's x-range?
			(a.x        >  b.x  &&  a.x        <  b.x + b.w) ||
			// is a.x's other corner inside b's x-range?
			(a.x + a.w  >  b.x  &&  a.x + a.w  <  b.x + b.w)
			) {
		if (
				// is a.y inside b's y-range?
				(a.y        >  b.y  &&  a.y        <  b.y + b.h) ||
				// is a.y's other corner inside b's y-range?
				(a.y + a.h  >  b.y  &&  a.y + a.h  <  b.y + b.h)
				) {
			return true;
		}
	}
	return false;
}


int main(int argc, char *argv[]) {
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cerr << "Error initializing SDL" << endl;
		exit(1);
	}

	// create the window
	SDL_Window* window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	// make the scaled rendering look smoother
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	// render at a virtual resolution then stretch to actual resolution
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	// load ball
	SDL_Texture* blue{nullptr};
	SDL_Texture* green{nullptr};
	int ballWidth{0};
	int ballHeight{0};
	{
		SDL_Surface* temp = IMG_Load("blue.png");

		blue = SDL_CreateTextureFromSurface(renderer, temp);
		ballWidth = temp->w;
		ballHeight = temp->h;

		SDL_FreeSurface(temp);

		temp = IMG_Load("green.png");
		green = SDL_CreateTextureFromSurface(renderer, temp);
		SDL_FreeSurface(temp);
	}

	// set ball position
	SDL_Rect ballRect;
	ballRect.x = 10;
	ballRect.y = 10;
	ballRect.w = ballWidth;
	ballRect.h = ballHeight;
	int xSpeed{10};
	int ySpeed{10};

	SDL_Rect mouseRect{
		-100,
		-100,
		ballWidth,
		ballHeight
	};

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
				else if (event.key.keysym.sym == SDLK_x) {
					xSpeed = -xSpeed;
				}
				else if (event.key.keysym.sym == SDLK_y) {
					ySpeed = -ySpeed;
				}
			}
			else if (event.type == SDL_MOUSEMOTION) {
				mouseRect.x = event.motion.x - (ballWidth/2);
				mouseRect.y = event.motion.y - (ballHeight/2);
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				ballRect.x = event.button.x - (ballWidth/2);
				ballRect.y = event.button.y - (ballHeight/2);
			}
		}

		// update things
		if(collides(mouseRect, ballRect)) {
			xSpeed = -xSpeed;
			ySpeed = -ySpeed;
		}
		ballRect.x += xSpeed;
		ballRect.y += ySpeed;

		if (ballRect.x + ballWidth > SCREEN_WIDTH || ballRect.x < 0) {
			xSpeed = -xSpeed;
		}
		if (ballRect.y + ballHeight > SCREEN_HEIGHT || ballRect.y < 0) {
			ySpeed = -ySpeed;
		}

		// clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// draw things
		SDL_RenderCopy(renderer, blue, nullptr, &ballRect);
		SDL_RenderCopy(renderer, green, nullptr, &mouseRect);

		// show the newly drawn things
		SDL_RenderPresent(renderer);

		// wait before drawing the next frame
		SDL_Delay(10);
	}

	// free memory
	SDL_DestroyTexture(blue);
	blue = nullptr;
	SDL_DestroyTexture(green);
	green = nullptr;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}
*/
