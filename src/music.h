/*
 * music.h
 *
 *  Created on: 14 dec 2014
 *      Author: samanthavi
 */

#ifndef SRC_MUSIC_H_
#define SRC_MUSIC_H_

#include <SDL2/SDL_mixer.h>


class music
{
public:
	void starting_music();
	void playing_music();

private:
	Mix_Music *start_music = Mix_LoadMUS("");
	Mix_Music *play_music = Mix_LoadMUS("");

};



#endif /* SRC_MUSIC_H_ */
