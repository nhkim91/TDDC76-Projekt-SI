/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:         render.h
 * Enhetsnamn:      render
 * Typ:             Klassdeklaration
 * Programmerare:   Kim Nguyen Hoang, kimng797, 910112-0260
 *                  Kerstin Soderqvist, kerso255, 911006-0309
 *                  Niclas Granström, nicgr354, 900519-5376
 *                  Anton Gifvars, antgi546, 890917-1657
 *
 * Datum:           2014-12-17
 *
 * BESKRIVNING
 *
 * Filen innehåller deklarationer för klassen render. Klassen render har koll på
 * det mesta som ska renderas (visas i fönster), förutom objekten på spelplanen.
 * Klassen har bl.a. funktionerna render_text() och render_image() som renderar
 * text respektive bilder.
 *
 * Funktioner:
 * - render_text: Renderar text.
 * - render_image: Renderar bild.
 * - render_flying_object: Renderar flying_object.
 * - render_power_up: Renderar power_up.
 * - present: Visar bilden på skärmen.
 * - set_renderer: Sätter pekare till renderare.
 * - get_renderer: Returnerar renderaren.
 *
 */

#ifndef RENDER_H
#define RENDER_H

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <set>
#include <string>


class render
{
public:
    render(int, int);
    ~render() = default;

    void render_text(const std::string &text, const std::string &fontFile,
                     SDL_Color color, int fontSize, int x_pos, int y_pos);
    void render_image(const std::string &imageFile, int x_pos, int y_pos);
    void render_background(const std::string &imageFile, int x_pos, int y_pos);
    void render_game_background(SDL_Texture* background_texture, SDL_Rect* background_rect);
    void render_flying_object(class flying_objects*);
    void render_power_up(class power_up_attack*, class power_up_shield*);
    void present();
    void set_renderer(SDL_Renderer*);
    int get_width();
    int get_height();
    SDL_Renderer* get_renderer();

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Surface* surf;
    int screen_width;
    int screen_height;

};

/*
 * SLUT PÅ FILEN render.h
 */

#endif // RENDER_H
