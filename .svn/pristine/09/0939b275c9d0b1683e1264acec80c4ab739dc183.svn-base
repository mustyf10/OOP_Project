#include "Nut.h"

Nut::Nut() : MovableGridItem(NUT), collected_(false)
{
	placeNut();
}

bool Nut::hasBeenCollected()
{
	return (collected_);
}

const bool Nut::hasReachedAHole_(Underground ug) const
{
	return ug.isAHole(getX(), getY());
}

void Nut::moveNut(int mouseDX_, int mouseDY_)
{

	if (((x_ + 2 * mouseDX_) >= 1) && ((x_ + 2 * mouseDX_) <= SIZE) &&
		((y_ + 2 * mouseDY_) >= 1) && ((y_ + 2 * mouseDY_) <= SIZE))
	{

		updatePosition(mouseDX_, mouseDY_);
	}
}

void Nut::appear()
{
	collected_ = false;
	placeNut();
	setPosition(x_, y_);
}

void Nut::disappear()
{
	collected_ = true;
	setPosition(0, 0);
}

void Nut::placeNut()
{
	x_ = rng_(SIZE);        //may fall on mouse
	y_ = rng_(SIZE);
}
int Nut::rng_(const int max)
{
	//srand(static_cast<unsigned>(time(0)));
	return (rand() % max) + 1;
}

void Nut::updatePosition(int dx, int dy)
{
	x_ += dx;
	y_ += dy;
}