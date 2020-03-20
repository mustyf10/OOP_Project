// Underground.cpp: implementation of the Underground class
//////////////////////////////////////////////////////////////////////

#include "Underground.h"

//////////////////////////////////////////////////////////////////////

Underground::Underground() : hole1_(4, 3), hole2_(15, 10), hole3_(7, 15)
{}

bool Underground::isAHole(int x, int y) const
{
	return (hole1_.isAtPosition(x, y) || hole2_.isAtPosition(x, y) || hole3_.isAtPosition(x, y));
}

char Underground::getSymbol() const{
	return hole1_.getSymbol();
}
int Underground::randomHoleX(){
	int max(3);
	int x_ = rng_(max);
	if (x_ == 1)
	{
		int x = hole1_.getX();
		return x;
	}
	if (x_ == 2)
	{
		int x = hole2_.getX();
		return x;
	}
	if (x_ == 3)
	{
		int x = hole3_.getX();
		return x;
	}
}
int Underground::randomHoleY(){
	int max(3);
	int y_ = rng_(max);
	if (y_ == 1)
	{
		int y = hole1_.getY();
		return y;
	}
	if (y_ == 2)
	{
		int y = hole2_.getY();
		return y;
	}
	if (y_ == 3)
	{
		int y = hole3_.getY();
		return y;
	}
}
int Underground::rng_(const int max)
{
	srand(static_cast<unsigned>(time(0)));
	return (rand() % max) + 1;
}