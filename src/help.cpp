#include "help.h"
#include <string>

void help::set_renderer(render* rend)
{
    renderer = rend;
}

void help::show_help()
{
    renderer->render_image("Space.png",0, 0);

    SDL_Color whiteColor {255, 255, 255, 255};
    SDL_Color redColor {187, 32, 26, 255};

    std::string msg = "Arrow up and down navigates the spaceship.";
    std::string msg1 = "Use space to shoot the enemy.";
    std::string msg2 = "Try not to be hit by the meteorites";
    std::string msg3 = "or when the aliens shoot you. And don't";
    std::string msg4 = "let the aliens over-run your planet.";

    renderer->render_text("Help", "Arcade.ttf", whiteColor, 100, 300, 30);
    renderer->render_text(msg, "Arcade.ttf", whiteColor, 30, 80, 200);
    renderer->render_text(msg1, "Arcade.ttf", whiteColor, 30, 80, 250);
    renderer->render_text(msg2, "Arcade.ttf", whiteColor, 30, 80, 300);
    renderer->render_text(msg3, "Arcade.ttf", whiteColor, 30, 80, 350);
    renderer->render_text(msg4, "Arcade.ttf", whiteColor, 30, 80, 400);
    renderer->render_text("Back to Menu", "Arcade.ttf", redColor, 40, 280, 550);

    renderer->present();

    bool run = true;
    SDL_Event event;

    while(run)
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
