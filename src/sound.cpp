/*
 * TDDC76 PROJEKT: Space Invader
 *
 * IDENTIFIERING
 *
 * Filnamn:     sound.cpp
 * Enhetsnamn:  sound
 * Typ:
 * Skriven av:  Margareta Vi, marvi154,  920809-0309
 * 				Madeleine Ardic, madar730, 930922-4245
 * Datum:       2014-12-xx
 *
 * BESKRIVNING:
 *
 * Filen innehåller deklarationer för klassen sound.
 *
 * REFERERADE BIBLIOTEK OCH MODULER:
 */

#include "sound.h"
#include <iostream>
#include <stdio.h>
using namespace std;

sound::~sound()
{
	Mix_FreeChunk(attack_sound);
	Mix_FreeChunk(attack_up_sound);
	Mix_FreeChunk(shield_up_sound);
	Mix_FreeChunk(shield_down_sound);
	Mix_FreeChunk(power_up_bullet_sound);
	Mix_FreeChunk(power_down_bullet_sound);
	Mix_FreeChunk(power_up_life_sound);
	Mix_FreeMusic(background_sound);
	Mix_FreeMusic(menu_sound);
	attack_sound = NULL;
	attack_up_sound = NULL;
	background_sound = NULL;
	menu_sound = NULL;
}

sound::sound()
{
	attack_sound = Mix_LoadWAV("sfx_laser1.ogg");
	if (attack_sound == NULL)
	{
		fprintf(stderr, "unable to load attack sound %s\n", Mix_GetError());
	}

	attack_up_sound = Mix_LoadWAV("Laser_blast.ogg");
	if (attack_sound == NULL)
	{
		fprintf(stderr, "unable to load attack_up sound %s\n", Mix_GetError());
	}

	shield_up_sound = Mix_LoadWAV("sfx_shieldUp.ogg");
	if (shield_up_sound == NULL)
	{
		fprintf(stderr, "unable to load attack sound %s\n", Mix_GetError());
	}
	shield_down_sound = Mix_LoadWAV("sfx_shieldDown.ogg");
	if (shield_down_sound == NULL)
	{
		fprintf(stderr, "unable to load attack sound %s\n", Mix_GetError());
	}

	power_up_bullet_sound = Mix_LoadWAV("zapThreeToneUp.ogg");
	if (power_up_bullet_sound == NULL)
	{
		fprintf(stderr, "unable to load attack sound %s\n", Mix_GetError());
	}
	power_down_bullet_sound = Mix_LoadWAV("zapThreeToneDown.ogg");
	if (power_up_bullet_sound == NULL)
	{
		fprintf(stderr, "unable to load attack sound %s\n", Mix_GetError());
	}
	power_up_life_sound = Mix_LoadWAV("highUp.ogg");
	if (power_up_life_sound == NULL)
	{
		fprintf(stderr, "unable to load attack sound %s\n", Mix_GetError());
	}
	/*kill_sound = Mix_LoadWAV("");
	if (kill_sound == NULL)
	{
		fprintf(stderr, "unable to load kill sound %s\n", Mix_GetError());
	}

	 */
	background_sound = Mix_LoadMUS("background.ogg");
	if (background_sound == NULL)
	{
		fprintf(stderr, "unable to load background sound  %s\n", Mix_GetError());
	}
	menu_sound = Mix_LoadMUS("menu_sound.ogg");
	if (menu_sound == NULL)
	{
		fprintf(stderr, "unable to load menu sound %s\n", Mix_GetError());
	}
}

void sound::play_attack()
{
	if ((Mix_PlayChannel(-1, attack_sound, 0)) == -1)
	{
		fprintf(stderr, "unable to play attack sound: %s\n", Mix_GetError());
	}
}

void sound::play_attack_up()
{
	if ((Mix_PlayChannel(-1, attack_up_sound, 0)) == -1)
	{
		fprintf(stderr, "unable to play attack sound: %s\n", Mix_GetError());
	}
}

void sound::play_shield_up()
{
	if ((Mix_PlayChannel(-1, shield_up_sound, 0)) == -1)
	{
		fprintf(stderr, "unable to play attack sound: %s\n", Mix_GetError());
	}
}

void sound::play_shield_down()
{
	if ((Mix_PlayChannel(-1, shield_down_sound, 0)) == -1)
	{
		fprintf(stderr, "unable to play attack sound: %s\n", Mix_GetError());
	}
}

void sound::play_power_up_bullet()
{
	if ((Mix_PlayChannel(-1, power_up_bullet_sound, 0)) == -1)
	{
		fprintf(stderr, "unable to play attack sound: %s\n", Mix_GetError());
	}
}

void sound::play_power_down_bullet()
{
	if ((Mix_PlayChannel(-1, power_down_bullet_sound, 0)) == -1)
	{
		fprintf(stderr, "unable to play attack sound: %s\n", Mix_GetError());
	}
}

void sound::play_power_up_life()
{
	if ((Mix_PlayChannel(-1, power_up_life_sound, 0)) == -1)
	{
		fprintf(stderr, "unable to play attack sound: %s\n", Mix_GetError());
	}
}

void sound::play_background()
{
	if (Mix_PlayingMusic() == 0)
	{
		Mix_PlayMusic(background_sound, -1);
	}
}

void sound::sound_paused()
{
	if( Mix_PlayingMusic() == 0 )
	{
		//Play the music
		Mix_PlayMusic( background_sound, -1 );
	}
	//If music is being played
	else
	{
		//If the music is paused
		if( Mix_PausedMusic() == 1 )
		{
			//Resume the music
			Mix_ResumeMusic();
		}
		//If the music is playing
		else
		{
			//Pause the music
			Mix_PauseMusic();
		}
	}
}

void sound::stop_music()
{
	Mix_HaltMusic();
}
