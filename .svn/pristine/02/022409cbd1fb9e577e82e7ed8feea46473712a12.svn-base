#if !defined(MouseAndCatGameH)
#define MouseAndCatGameH

#include <iostream>		//for output and input: cout <<
#include <istream>
#include <string>		//for string
#include <sstream>		//for streamstring
#include <fstream>
#include <iomanip>
#include <conio.h>

using namespace std;

//include class modules
#include "Mouse.h"
#include "Cat.h"
#include "Player.h"
#include "Underground.h"
#include "Interface.h"
#include "Nut.h"

class MouseAndCatGame
{
public:
	MouseAndCatGame(Interface*, Player*);
	void run();
private:
	string prepareGrid();
	bool isArrowKeyCode(int keycode);
	void applyRules();
	bool hasEnded(char key);
	string prepareEndMessage();
	void save();
	void load();
	void replay();
	void cheatMode();
	bool cheatModeStatus_ = false;
	Mouse mouse_;
	Cat cat_;
	Nut nut_;
	Score score_;
	const Underground underground_;
	const Interface* p_ui;
	Player* player_;
	string tempName;
	int tempScore;
	int key_;
	int tempCatX, tempCatY, tempMouseX, tempMouseY;
	bool tempNutCollected;
	string undoGrid;
};
#endif