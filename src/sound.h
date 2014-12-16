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
    void set_sound(sound*);
    void play_attack();
    void play_attack_up();
    void play_shield_up();
    void play_shield_down();
    void play_power_up_bullet();
    void play_power_down_bullet();
    void play_power_up_life();
    void play_background();
    //void play_kill();
    void sound_paused();
    void stop_music();

private:
    Mix_Chunk *attack_sound = NULL;
    Mix_Chunk *attack_up_sound = NULL;
    Mix_Chunk *shield_up_sound = NULL;
    Mix_Chunk *shield_down_sound = NULL;
    Mix_Chunk *power_up_bullet_sound = NULL;
    Mix_Chunk *power_down_bullet_sound = NULL;
    Mix_Chunk *power_up_life_sound = NULL;
    //Mix_Chunk *kill_sound = NULL;
    Mix_Music *background_sound = NULL;
    Mix_Music *menu_sound = NULL;
};



#endif /* SRC_SOUND_H_ */
