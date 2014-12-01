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

void alien::check_living()
{
	if(get_life()==0)
	{
		delete this;
	}
	else
	{
		return;
	}
}

