#ifndef RENDER_H
#define RENDER_H
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <set>
#include <string>


class render
{
public:
    render();
    ~render() = default;

    void render_text(const std::string &text, const std::string &fontFile,
                     SDL_Color color, int fontSize, int x_pos, int y_pos);
    void render_image(const std::string &imageFile, int x_pos, int y_pos, double scale = 1.0f);

    void present();
    void set_renderer(SDL_Renderer*);

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Surface* surf;

};

#endif // RENDER_H
