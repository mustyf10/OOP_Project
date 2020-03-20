#if !defined(GridItemH)
#define GridItemH

#include "constants.h"

class GridItem
{
public:
	GridItem(char);
	char getSymbol() const;
protected:
	const char symbol_;
};
#endif