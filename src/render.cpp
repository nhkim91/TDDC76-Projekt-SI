/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     render.cpp
 * Enhetsnamn:  render
 * Typ:         Definitioner hörande till klassen render
 * Skriven av:  Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *              //Kerstin Soderqvist 911006-0309 Y3.c kerso255
 * Datum:       2014-12-xx
 *
 * BESKRIVNING
 *
 * Filen innehåller deklarationer för klassen render. Klassen render har koll på
 * det mesta som ska renderas (visas i fönster), förutom objekten på spelplanen.
 * Klassen har bl.a. funktionerna render_text() och render_image() som renderar
 * text respektive bilder.
 */

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#include <iostream>
#include "render.h"
#include "flying_objects.h"
#include "power_up.h"

using namespace std;

render::render(int width, int height)
{
	TTF_Init();
	screen_width = width;
	screen_height= height;
}
int render::get_width()
{
	return screen_width;
}

int render::get_height()
{
	return screen_height;
}

void render::render_flying_object(flying_objects* object)
{
	SDL_RenderCopy(renderer, object->get_texture(), nullptr, &object->get_rect());
	return;
}


void render::render_power_up(power_up_attack* attack_ptr, power_up_shield* shield_ptr)
{
	flying_objects* new_attack_ptr;
	flying_objects* new_shield_ptr;

	new_attack_ptr = dynamic_cast<flying_objects*>(attack_ptr);
	new_shield_ptr = dynamic_cast<flying_objects*>(shield_ptr);


	if (new_attack_ptr != nullptr)
	{
		SDL_RenderCopy(renderer, new_attack_ptr->get_texture(), nullptr, &new_attack_ptr->get_rect());
	}

	if (new_shield_ptr != nullptr)
	{
		SDL_RenderCopy(renderer, new_shield_ptr->get_texture(), nullptr, &new_shield_ptr->get_rect());
	}
}



void render::render_text(const std::string &text, const std::string &fontFile,
		SDL_Color color, int fontSize, int x_pos, int y_pos)
{
	TTF_Font* font = TTF_OpenFont(fontFile.c_str(), fontSize); // öppnar filen med fonten
	if (font == nullptr)
	{
		cout << "Error, kan inte öppna font" << endl;
		return;
	}

	SDL_Surface* surf = TTF_RenderText_Blended(font, text.c_str(), color); // ritar ut texten på en surface
	if (surf == nullptr)
	{
		TTF_CloseFont(font);
		cout << "Error, kan inte rendrera text" << endl;
		return;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == nullptr)
	{
		cout << "Error, kan inte skapa en textur till texten" << endl;
	}

	SDL_Rect text_rect;
	text_rect.w = surf->w;
	cerr << "width "<< text_rect.w<< endl;
	text_rect.h = surf->h;
	cerr << "height"<< text_rect.h <<endl;
	text_rect.x = x_pos-text_rect.w/2;
	text_rect.y = y_pos-text_rect.h/2;


	SDL_RenderCopy(renderer, texture, NULL, &text_rect);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return;
}

void render::render_image(const string &imageFile, int x_pos, int y_pos)
{
	SDL_Surface* surf = IMG_Load(imageFile.c_str());

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == nullptr)
	{
		cout << "Error, kan inte skapa en textur till bilden." << endl;
	}

	double width_ratio = (double)(surf->w)/screen_width;
	double height_ratio = (double)(surf->h)/screen_height;
	double scale;
	cerr << "WIDTH: " << width_ratio << " Height: " << height_ratio << endl;
	if(width_ratio <= height_ratio)
	{
		scale = 1/width_ratio;
	}
	else
	{
		scale = 1/height_ratio;
	}
cerr << scale << " SCALE\n";

	SDL_Rect image_rect;
	image_rect.x = x_pos;
	image_rect.y = y_pos;
	image_rect.w = (int)(((surf->w) * scale));
	image_rect.h = (int)(((surf->h) * scale));

	SDL_RenderCopy(renderer, texture, NULL, &image_rect);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surf);
}

void render::present()
{
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}

void render::set_renderer(SDL_Renderer* rend)
{
	renderer = rend;
}

SDL_Renderer* render::get_renderer()
{
	return renderer;
}

/*
 * SLUT PÅ FILEN render.cpp
 */
