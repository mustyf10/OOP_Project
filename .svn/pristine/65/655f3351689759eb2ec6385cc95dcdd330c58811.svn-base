#if !defined(FixedGridItemH)
#define FixedGridItemH

#include "constants.h"
#include "GridItem.h"

class FixedGridItem : public GridItem
{
public:
	FixedGridItem(char, int, int);
	int getX() const;
	int getY() const;
	bool isAtPosition(int x, int y) const;
protected:
	const int x_, y_;
};

#endif