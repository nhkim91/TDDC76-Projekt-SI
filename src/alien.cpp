#include "alien.h"
#include "linkheader.h"
#include <vector>
using namespace std;




alien::~alien()
{
	movement_.clear();
}

vector<int> alien::movement() const
{

	return movement_;
}


int alien::get_life() const
{
	return life_;
}

bool alien::check_living(int dmg)
{
	life_ = life_ - dmg;
	return (life_ <=0);
}

bool alien::hit(flying_objects& other)
{
	flying_objects *ptr_;
	ptr_ = &other;

	meteorite* other_obj_1;
	other_obj_1 = dynamic_cast<meteorite*>(ptr_);
	if (other_obj_1 != nullptr)
	{
		return check_living(other_obj_1->get_life());
	}

	player* other_obj_2;
	other_obj_2 = dynamic_cast<player*>(ptr_);
	if (other_obj_2 != nullptr)
	{
		return true;
	}

	bullet* other_obj_3;
	other_obj_3 = dynamic_cast<bullet*>(ptr_);
	if (other_obj_3 != nullptr)
	{
		return check_living(other_obj_3->get_dmg());
	}

	return false;

}
////////////////////////////////////////////////////
alien::alien(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer)
{
	/*SDL_Surface* temp = IMG_Load("alien2.png");
	texture_ = SDL_CreateTextureFromSurface(renderer, temp);
*/
	renderer_ = renderer;
	life_= life;
	rect_.x = x_pos;
	rect_.y = y_pos;
	/*rect_.w = temp->w;
	rect_.h = temp->h;
	*/
	movement_.at(0) = x_pos;
	movement_.at(1) = y_pos;
	movement_.at(2) = x_speed;
	movement_.at(3) = y_speed;

	//SDL_FreeSurface(temp);
}
////////////////////////////////////////////////////
alien_mk1::alien_mk1(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer):
				alien(life, x_pos, y_pos, x_speed, y_speed, renderer)
{
	SDL_Surface* temp = IMG_Load("alien1.png");
	texture_ = SDL_CreateTextureFromSurface(renderer, temp);

	/*renderer_ = renderer;
	life_= life;
	rect_.x = x_pos;
	rect_.y = y_pos;
	*/
	rect_.w = temp->w;
	rect_.h = temp->h;
	/*movement_.at(0) = x_pos;
	movement_.at(1) = y_pos;
	movement_.at(2) = x_speed;
	movement_.at(3) = y_speed;
*/
	SDL_FreeSurface(temp);
}
////////////////////////////////////////////////////
alien_mk2::alien_mk2(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer):
						alien(life, x_pos, y_pos, x_speed, y_speed, renderer)
{
	SDL_Surface* temp = IMG_Load("alien2.png");
	texture_ = SDL_CreateTextureFromSurface(renderer, temp);

	/*renderer_ = renderer;
	life_= life;
	rect_.x = x_pos;
	rect_.y = y_pos;
	*/
	rect_.w = temp->w;
	rect_.h = temp->h;
	/*movement_.at(0) = x_pos;
	movement_.at(1) = y_pos;
	movement_.at(2) = x_speed;
	movement_.at(3) = y_speed;
*/
	SDL_FreeSurface(temp);
}
////////////////////////////////////////////////////
alien_mk3::alien_mk3(int life, int x_pos, int y_pos, int x_speed, int y_speed, SDL_Renderer* renderer):
						alien(life, x_pos, y_pos, x_speed, y_speed, renderer)
{
	SDL_Surface* temp = IMG_Load("alien3.png");
	texture_ = SDL_CreateTextureFromSurface(renderer, temp);

	/*renderer_ = renderer;
	life_= life;
	rect_.x = x_pos;
	rect_.y = y_pos;
	*/
	rect_.w = temp->w;
	rect_.h = temp->h;
	/*movement_.at(0) = x_pos;
	movement_.at(1) = y_pos;
	movement_.at(2) = x_speed;
	movement_.at(3) = y_speed;
*/
	SDL_FreeSurface(temp);
}

////////////////////////////////////////////////////
bullet alien_mk3::attack()
{
	return bullet{1, 1,(movement_.at(0)-1), movement_.at(1), -10, 0, renderer_};

}

