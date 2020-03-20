#include "MovableGridItem.h"

MovableGridItem::MovableGridItem(char symbol_) : GridItem(symbol_), x_(0), y_(0)
{}
int MovableGridItem::getX() const
{
	return x_;
}
int MovableGridItem::getY() const
{
	return y_;
}
bool MovableGridItem::isAtPosition(int x, int y) const
{
	return (x_ == x) && (y_ == y);
}
void MovableGridItem::setPosition(int x, int y)
{
	x_ = x;
	y_ = y;
}
void MovableGridItem::updatePosition(int dx, int dy)
{
	x_ += dx;
	y_ += dy;
}
