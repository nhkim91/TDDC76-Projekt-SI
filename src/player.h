

#ifndef PLAYER_H_
#define PLAYER_H_


#include "flying_objects.h"



class player :public flying_objects{

public:

	// Datamedlemmar
	int life_;
	int dmg_;
	std::vector<int> speed_;
	std::vector<class power_up_attack*> power_up_attack_;
	std::vector<class power_up_shield*> power_up_shield_;



	// Konstruktor
	player(int life,int dmg, std::vector<int> speed): life_{life}, dmg_{dmg}, speed_{speed}{};

	//Operatorer
	void operator=(const player&);

	// Destruktor
	 ~player() = default;

	 // Funktioner
	 int get_life() const override;
	 void check_living();
	 void hit(flying_objects&)  override;
	 std::vector<int> movement() const override;
	 std::vector<power_up_attack*> get_power_up_attack();
	 std::vector<power_up_shield*> get_power_up_shield();
	 class bullet attack();

};
#endif /* PLAYER_H_ */
