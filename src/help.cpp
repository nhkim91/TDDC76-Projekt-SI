#include "help.h"
#include <string>

void help::set_renderer(render* rend)
{
    renderer = rend;
}

void help::show_help()
{
    renderer->render_image("space_background.png",0, 0);

    SDL_Color whiteColor {255, 255, 255, 255};
    SDL_Color redColor {187, 32, 26, 255};

    std::string msg = "Pil upp och ner styr rymdskeppet.";
    std::string msg1 = "Använd space för att skjuta fienden.";

    renderer->render_text("Help", "Arcade.ttf", whiteColor, 100, 300, 30);
    renderer->render_text(msg, "Arcade.ttf", whiteColor, 30, 80, 200);
    renderer->render_text(msg1, "Arcade.ttf", whiteColor, 30, 80, 250);
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
