// Mouse.cpp: implementation of the Mouse class
//////////////////////////////////////////////////////////////////////

#include "Mouse.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Mouse::Mouse() : MovableGridItem(MOUSE),
                alive_(true), escaped_(false)
{
	positionAtRandom();
}

//////////////////////////////////////////////////////////////////////
// Public functions
//////////////////////////////////////////////////////////////////////

void Mouse::reset()
{
	alive_ = true;
	hasAteNut_ = false;
	escaped_ = false;
	positionAtRandom();
}
bool Mouse::isAtPosition(int x, int y) const 
{
	return (x_ == x) && (y_ == y);
}
bool Mouse::isAlive() const 
{
	return alive_;
}
bool Mouse::hasEscaped() const 
{
	return escaped_;
}
const bool Mouse::hasReachedAHole(Underground ug) const
{
	return ug.isAHole(getX(), getY());
}
void Mouse::die() 
{
	alive_ = false;
}
void Mouse::escapeIntoHole() 
{
	escaped_ = true;
}
const bool Mouse::canCollectNut(Nut* pNut) {
	if (isAtPosition(pNut->getX(), pNut->getY()))
		hasAteNut_ = true;
	else
		hasAteNut_ = false;
	return hasAteNut_;
}
void Mouse::scamper(char k) 
{ //move mouse in required direction
  //pre: Key is an arrow representing the direction in which the mouse moves
	//find direction indicated by key
	int mouseDX_;
	int mouseDY_;
	switch(k)               //...depending on the selected key...
	{
		case LEFT:           //when LEFT arrow pressed...
			mouseDX_ = -1;    //decrease the X coordinate
			mouseDY_ = 0;
			break;
		case RIGHT:          //when RIGHT arrow pressed...
			mouseDX_ = +1;    //increase the X coordinate
			mouseDY_ = 0;
			break;
		case UP:             //when UP arrow pressed...
			mouseDX_ = 0;
			mouseDY_ = -1;    //decrease the Y coordinate
			break;
		case DOWN:           //when DOWN arrow pressed...
			mouseDX_ = 0;
			mouseDY_ = +1;    //increase the Y coordinate
			break;
	}
	//update mouse coordinates if move is possible
	if (((x_ + mouseDX_) >= 1) && ((x_ + mouseDX_) <= SIZE) &&
		 ((y_ + mouseDY_) >= 1) && ((y_ + mouseDY_) <= SIZE) )
	{
		updatePosition(mouseDX_, mouseDY_);		//go in that direction
	}
}
void Mouse::transport()
{
	Underground ug;
	transportPosition(ug.randomHoleX(), ug.randomHoleY());
}

//////////////////////////////////////////////////////////////////////
// Private functions
//////////////////////////////////////////////////////////////////////

void Mouse::updatePosition(int dx, int dy) 
{
	x_ += dx;
	y_ += dy;
}
void Mouse::transportPosition(int dx, int dy)
{
	x_ = dx;
	y_ = dy;
}
void Mouse::positionAtRandom()
{
	x_ = rng_(SIZE);        //may fall on mouse
	y_ = rng_(SIZE);
}
int Mouse::rng_(const int max)
{
	//srand(static_cast<unsigned>(time(0)));
	return (rand() % max) + 1;
}