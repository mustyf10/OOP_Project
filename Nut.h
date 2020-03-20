#if !defined(NutH)
#define NutH

#include "constants.h"
#include "MovableGridItem.h"
#include "Underground.h"
#include <stdlib.h>	//for srand and rand routines
#include <cassert>	//for assert
#include <ctime>	//for time used in RandomNumberGenerator::seed routines

class Nut : public MovableGridItem
{
public:
	Nut();
	bool hasBeenCollected();
	const bool hasReachedAHole_(Underground ug) const;
	void moveNut(int mouseDX_, int mouseDY_);
	void appear();
	void disappear();
	void placeNut();
	void updatePosition(int dx, int dy);
protected:
	bool collected_;
	static int rng_(const int max);
};

#endif