#if !defined(PlayerH)
#define PlayerH

#include <string>
#include "Score.h"
using namespace std;

class Player{
public:
	Player(string);
	string getName() const;
	int getScoreAmount() const; 
	void setScoreAmount(int);
	void updateScoreAmount(int);
private:
	const string name_;
	Score score_;
};

#endif