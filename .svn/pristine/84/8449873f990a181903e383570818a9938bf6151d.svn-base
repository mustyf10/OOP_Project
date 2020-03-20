// Cat.cpp: implementation of the Cat class
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////

#include "Cat.h"

Cat::Cat() : MovableGridItem(CAT), p_mouse_(nullptr)
{
	positionAtRandom();
}
Cat::~Cat() 
{
	p_mouse_= nullptr;
}
bool Cat::isAtPosition(int x, int y) 
{
	return (x_ == x) && (y_ == y);
}
bool Cat::hasCaughtMouse()
{
	assert(p_mouse_ != 0);  //Pre-condition: The cat needs to know where the mouse is 
	return isAtPosition(p_mouse_->getX(), p_mouse_->getY());
}
void Cat::spotMouse(Mouse* p_mouse) 
{
	p_mouse_ = p_mouse;
}
void Cat::chaseMouse() 
{	 
	assert(p_mouse_ != 0);  //Pre-condition: The cat needs to know where the mouse is 
	//assume cat only move when necessary
	int catDX(0), catDY(0);
	//update coordinate if necessary
	if (x_ < p_mouse_->getX())             //if cat on left of mouse
		catDX = 1;                          //cat should move right
	else                                    //otherwise
		if (x_ > p_mouse_->getX())         //if cat on left of mouse
			catDX = -1;                     //cat should move left
	if (y_ < p_mouse_->getY())             //if cat is above mouse
		catDY = 1;                          //cat should move down
	else                                    //otherwise
		if (y_ > p_mouse_->getY())         //if cat is below mouse
			catDY = -1;                     //cat should move up
	//go in that direction
	updatePosition(catDX, catDY);
}
void Cat::updatePosition(int dx, int dy) 
{
	x_ += dx;
	y_ += dy;
}
void Cat::positionAtRandom() 
{
	x_ = rng_(SIZE);        //may fall on mouse
	y_ = rng_(SIZE);
}
int Cat::rng_(const int max)
{
	srand(static_cast<unsigned>(time(0)));
	return (rand() % max) + 1;
}
Mouse* Cat::getMouse()
{
	return p_mouse_;
}