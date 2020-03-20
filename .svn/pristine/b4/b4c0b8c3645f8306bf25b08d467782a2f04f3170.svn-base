#if !defined (MovableGridItemH)
#define MovableGridItemH

#include "GridItem.h"

class MovableGridItem : public GridItem
{
public:
	MovableGridItem(char);
	int getX() const;
	int getY() const;
	bool isAtPosition(int x, int y) const;
	void setPosition(int x, int y);
	void updatePosition(int dx, int dy);
protected:
	int x_, y_;
};

#endif