// Cat.h: interface for the Cat class 
//////////////////////////////////////////////////////////////////////

#if !defined(CatH)
#define CatH

#include "constants.h"
#include "Mouse.h"
#include <stdlib.h>	//for srand and rand routines
#include <cassert>	//for assert
#include <ctime>	//for time used in RandomNumberGenerator::seed routines

class Cat : public MovableGridItem
{
public:
	Cat();
	~Cat();
	bool isAtPosition( int x, int y);  
	bool hasCaughtMouse();
	void spotMouse(Mouse* p_mouse);
	void chaseMouse();
	void updatePosition( int dx, int dy);
	void positionAtRandom();
	Mouse* getMouse();
protected:
	Mouse* p_mouse_;
	static int rng_(const int max);
};

#endif // !defined(CatH)