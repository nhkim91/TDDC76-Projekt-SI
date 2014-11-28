#include "alien.h"
#include "linkheader.h"
#include <vector>
using namespace std;


vector<int> alien::movement() const
{

	return speed_;
}


int alien::get_life() const
{
	return life_;
}


