#include "space_invader.h"
#include "linkheader.h"
#include <iostream>
#include <algorithm>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

space_invader::space_invader()
{
	//////KONSTRUKTOR
}

void space_invader::killer()
{
	vector<int> to_delete;
	for(unsigned int i=0 ; i<displaying_objects_.size(); i++)
	{
		for(unsigned int j=i+1; j<displaying_objects_.size(); j++)
		{
			if (collides(displaying_objects_.at(i),displaying_objects_.at(j)))
			{
				if(displaying_objects_.at(i).hit(displaying_objects_.at(j)))
				{
					to_delete.push_back(i);
				}
				if(displaying_objects_.at(j).hit(displaying_objects_.at(i)))
				{
					to_delete.push_back(j);
				}
			}
		}
	}

	//sorterar to_delete från större till mindre
	sort(to_delete.begin(), to_delete.end()+1, greater<int>());

	for(unsigned int i: to_delete)
	{
		displaying_objects_.erase(displaying_objects_.begin() + i);
	}
}

bool space_invader::collides(const flying_objects& obj_1, const flying_objects& obj_2)
{
	SDL_Rect a;
	SDL_Rect b;
	a=obj_1.get_rect();
	b=obj_2.get_rect();

	if (
			// is a.x inside b's x-range?
			(a.x > b.x  &&  a.x < b.x + b.w) ||
			// is a.x's other corner inside b's x-range?
			(a.x + a.w  >  b.x  &&  a.x + a.w  <  b.x + b.w)
	)
	{

		if (
				// is a.y inside b's y-range?
				(a.y        >  b.y  &&  a.y        <  b.y + b.h) ||
				// is a.y's other corner inside b's y-range?
				(a.y + a.h  >  b.y  &&  a.y + a.h  <  b.y + b.h)
		)
		{
			return true;
		}
	}
	return false;
}

//bool erase
