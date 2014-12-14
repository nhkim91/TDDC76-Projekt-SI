/*
 * sound.h
 *  Created on: 14 dec 2014
 */

#ifndef SRC_SOUND_H_
#define SRC_SOUND_H_

#include <SDL2/SDL_mixer.h>

class sound
{
	//Konstruktorer/destruktorer
	~sound();

	// funktioner
	void play_attack();


private:
	Mix_Chunk *attack_sound = Mix_LoadWAV("sfx_laser1.ogg");

};



#endif /* SRC_SOUND_H_ */
