/*
 * sound.cpp
 *
 *  Created on: 14 dec 2014
 *      Author: samanthavi
 */

#include "sound.h"

sound::~sound()
{
	Mix_FreeChunk(attack_sound);
}
void sound::play_attack()
{
	Mix_PlayChannel(-1,attack_sound,0);
}


