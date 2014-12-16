/*
 * sound.h
 *  Created on: 14 dec 2014
 */

#ifndef SRC_SOUND_H_
#define SRC_SOUND_H_

#include <SDL2/SDL_mixer.h>
#include <string>

class sound
{
public:
	//Konstruktorer/destruktorer
	sound();
	~sound();

	// funktioner
	void play_attack();
	void play_background();
	void play_menu();
	void sound_paused();

private:
	Mix_Chunk *attack_sound = NULL;
	Mix_Music *background_sound = NULL;
	Mix_Music *menu_sound = NULL;

};



#endif /* SRC_SOUND_H_ */
