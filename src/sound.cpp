/*
 * sound.cpp
 *
 *  Created on: 14 dec 2014
 *      Author: samanthavi
 */

#include "sound.h"
#include <iostream>
#include <stdio.h>
using namespace std;

sound::~sound()
{
	Mix_FreeChunk(attack_sound);
}

sound::sound()
{
	attack_sound = Mix_LoadWAV("sfx_laser1.ogg");
	if(attack_sound == NULL)
	{
		fprintf(stderr, "unable to load attack fle  %s\n", Mix_GetError());
	}
	background_sound = Mix_LoadMUS("background.ogg");
	if(background_sound == NULL)
	{
		fprintf(stderr, "unable to load background file  %s\n", Mix_GetError());
	}
}
void sound::play_attack()
{
	if((Mix_PlayChannel(-1,attack_sound,0)) == -1)
	{
		fprintf(stderr,"unable to play ogg file: %s\n", Mix_GetError());
	}
}

void sound::play_background()
{
	if(Mix_PlayingMusic() == 0)
	{
		Mix_PlayMusic(background_sound, -1);
	}
}


void sound::play_menu()
{
	if(Mix_PlayingMusic() == 0)
	{
		Mix_PlayMusic(menu_sound, -1);
	}
}
