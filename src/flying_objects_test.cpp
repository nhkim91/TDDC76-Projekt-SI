

#include "flying_objects.h"
#include "player.h"
#include "bullet.h"
#include "meteorite.h"
#include "power_up.h"


#include <iostream>
#include <vector>
using namespace std;


int main() {

	vector<int> v(2);
	v[0] = 7;
	v[1] = 5;
	player player_{6, 6, v};
	bullet bullet_{1, 5, v};
	meteorite_small meteorite_{3,v};
	power_up_attack attack_{67, v};
	//vector<int> post;
	//post = meteorite_.movement();
	//cout << post.size()<< endl;
	//cout << post.at(0)<< endl;
	cout << player_.get_life() << endl;
	cout << bullet_.get_dmg() << endl;
 	player_.hit(bullet_);
	cout << player_.get_life() << endl;
	player_.get_power_up();
	if (player_.get_power_up().empty())
	{
		cout << "ratt!" << endl;
	}
	cout << player_.get_power_up().empty() << endl;
	cout << player_.get_power_up().size() << endl;

	attack_.countdown_timer();
	cout << attack_.get_timer() << endl;
	player_.hit(attack_);
	cout << player_.get_power_up().empty() << endl;

	cout << player_.get_power_up().at(0)->get_life() << endl;



	return 0;
}
