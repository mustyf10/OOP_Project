// Underground.h: interface for the Underground class
//
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------
// Date       Programmer    Amendments made & justification (if needed)
//---------------------------------------------------------------------
// 15.11.15   Pascale		Need to be amended for Assignment 1 [Q1 to 4 and 7]
//                          Declare class data and function members private where possible.
//                          Declare const instances, parameters and class functions (wherever possible).
//                          Create constructors with their initialisation list in same order as declaration list
//                          Place code in separate module
//                   		Check design and implementation of relationships to other classes
//                   		Follow UML design.
//							etc.
//---------------------------------------------------------------------
#if !defined(UndergroundH)
#define UndergroundH

#include <cassert>
#include "constants.h"
#include "Hole.h"
#include <stdlib.h>
#include <ctime>

class Underground {
public:
	Underground();
	bool isAHole(int, int) const;
	char getSymbol() const;
	int randomHoleX();
	int randomHoleY();
private:
	const Hole hole1_, hole2_, hole3_;
	static int rng_(const int max);
};

#endif // !defined(UndergroundH)
