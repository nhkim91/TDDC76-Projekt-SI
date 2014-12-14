/*
 * music.cpp
 *
 *  Created on: 14 dec 2014
 *      Author: samanthavi
 */


#include "music.h"

void music::starting_music()
{
	Mix_PlayMusic(start_music, -1);
}

void music::playing_music()
{
	Mix_PlayMusic(play_music, -1);

}

