#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include <SDL2_image/SDL_image.h>  //<- maggie behöver denna!
#include <SDL2/SDL_main.h>
#include "space_invader.h"
#include "highscore.h"

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

int main(int argc, char *argv[])
{
    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cerr << "Error initializing SDL" << endl;
        exit(1);
    }


    SDL_Window* window = SDL_CreateWindow("Highscore", SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                             SDL_RENDERER_PRESENTVSYNC);

    /*
    render rend;
    rend.set_renderer(renderer);

    highscore hs;
    hs.set_renderer(&rend);
    hs.show_highscore();

    SDL_Delay(2000);
	*/

    space_invader SI;
    SI.run();

    /*  // make the scaled rendering look smoother
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
        int xSpeed{0};
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

        SDL_Quit();*/
    return 0;
}

//else if (event.type == SDL_MOUSEMOTION) {
//  mouseRect.x = event.motion.x - (ballWidth/2);
//  mouseRect.y = event.motion.y - (ballHeight/2);
//}
//else if (event.type == SDL_MOUSEBUTTONDOWN) {
//  ballRect.x = event.button.x - (ballWidth/2);
//  ballRect.y = event.button.y - (ballHeight/2);
//}
