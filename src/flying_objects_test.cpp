

#include "flying_objects.h"
#include "player.h"
#include "bullet.h"
#include "meteorite.h"
#include "power_up.h"


#include <iostream>
#include <vector>
using namespace std;


int main(int,char**) {

	vector<int> v(2);
	v[0] = 7;
	v[1] = 5;
	player player_{6, v};
	bullet bullet_{1, 5, v};
	meteorite_small meteorite_{3,v};
	power_up_attack attack_{67, v, 19};
	//vector<int> post;
	//post = meteorite_.movement();
	//cout << post.size()<< endl;
	//cout << post.at(0)<< endl;
	//cout << player_.get_life() << endl;
	//cout << bullet_.get_dmg() << endl;
 	//player_.hit(bullet_);
	//cout << player_.get_life() << endl;
	//player_.get_power_up_attack();
	//if (player_.get_power_up_attack().empty())
	//{
	//	cout << "ratt!" << endl;
	//}
	//cout << player_.get_power_up_attack().empty() << endl;
	//cout << player_.get_power_up_attack().size() << endl;


	//player_.hit(attack_);
	//cout << player_.get_power_up_attack().empty() << endl;

	//cout << player_.get_power_up_attack().at(0)->get_life() << endl;


	//maggies test!

	attack_.hit(player_);
	cout << "I gave an attack_up to player!\n";
	attack_.hit(meteorite_);
	cout << "I hit a meteorite and nothing happend\n";

	//alien alien_{67, v, 19};
	//attack_.hit(alien_);

	//attack_.hit(bullet_);
	//cout << "i'm dead\n";

	power_up_shield shield_{67, v, 19};
	shield_.hit(player_);
	cout << "I shielded a player!\n";

	power_up_shield life_{67, v, 19};
	life_.hit(player_);
	cout << "I gave life to a player!\n";

	cout << player_.get_life() << endl << bullet_.get_life() << endl;
	player_.hit(bullet_);
	//bullet_.hit(player_);
	cout << "här"<<endl;
	cout << player_.get_life() << endl << bullet_.get_life() << endl;

	return 0;
}
