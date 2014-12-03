#ifndef PLAYER_H_
#define PLAYER_H_

#include "flying_objects.h"

class player :public flying_objects{

public:

	// Datamedlemmar
	int life_;
	std::vector<int> movement_;
	std::vector<class power_up_attack*> power_up_attack_;
	std::vector<class power_up_shield*> power_up_shield_;

	SDL_Rect rect_;


	// Konstruktor
	player(int, int, int, int, int);

	//Operatorer
	void operator=(const player&);

	// Destruktor
	 ~player();

	 // Funktioner
	 int get_life() const override;
	 bool check_living(int);
	 bool hit(flying_objects&)  override;
	 std::vector<int> movement() const override;
	 std::vector<power_up_attack*> get_power_up_attack();
	 std::vector<power_up_shield*> get_power_up_shield();
	 class bullet attack();
	 SDL_Rect get_rect() override;
};
#endif /* PLAYER_H_ */
