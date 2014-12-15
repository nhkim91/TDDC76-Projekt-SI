#include <iostream>
#include "render.h"
#include "flying_objects.h"
#include "power_up.h"
using namespace std;


render::render()
{
	TTF_Init();
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


	if(new_attack_ptr != nullptr)
	{
		SDL_RenderCopy(renderer, new_attack_ptr->get_texture(), nullptr, &new_attack_ptr->get_rect());
	}

	if(new_shield_ptr != nullptr)
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
	text_rect.x = x_pos;
	text_rect.y = y_pos;
	text_rect.w = surf->w;
	text_rect.h = surf->h;

	SDL_RenderCopy(renderer, texture, NULL, &text_rect);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return;
}

void render::render_image(const string &imageFile, int x_pos, int y_pos, double scale)
{
	SDL_Surface* surf = IMG_Load(imageFile.c_str());

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == nullptr)
	{
		cout << "Error, kan inte skapa en textur till bilden." << endl;
	}

	SDL_Rect image_rect;
	image_rect.x = x_pos;
	image_rect.y = y_pos;
	image_rect.w = (int) (((surf->w) * scale) + 0.5f);
	image_rect.h = (int) (((surf->h) * scale) + 0.5f);

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

