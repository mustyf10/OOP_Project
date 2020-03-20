//--------------------------------
//include standard libraries
#include "MouseAndCatGame.h"
MouseAndCatGame::MouseAndCatGame(Interface* pui, Player* p) : p_ui(pui), cat_(), mouse_(), nut_(), player_(p)
{
	//prepare game
	cat_.spotMouse(&mouse_);	//set up cat
}
void MouseAndCatGame::run() 
{
	char option;
	p_ui->drawGridOnScreen(prepareGrid());
	key_ = p_ui->getKeyPressFromUser();
	while (!hasEnded(key_))
	{
		if (isArrowKeyCode(key_))
		{
			tempCatX = cat_.getX();
			tempCatY = cat_.getY();
			tempMouseX = mouse_.getX();
			tempMouseY = mouse_.getY();

			tempNutCollected = nut_.hasBeenCollected();
			undoGrid = prepareGrid();
			
			mouse_.scamper(key_);
			if (cheatModeStatus_ == false)
			{
				cat_.chaseMouse();
				p_ui->drawGridOnScreen(prepareGrid());
			}
			else if (cheatModeStatus_ == true)
			{
				p_ui->drawGridOnScreen(prepareGrid());
				cout << "\nCHEAT MODE ACTIVATED!";
			}
				applyRules();
		}
		if (key_ == 'C')
		{
			cheatMode();
		}
		if (key_ == 'S')
		{
			save();
		}
		if (key_ == 'L')
		{
			load();
		}
		if (key_ == 'U')
		{
			cat_.setPosition(tempCatX, tempCatY);
			mouse_.setPosition(tempMouseX, tempMouseY);

			p_ui->drawGridOnScreen(undoGrid);
			cout << "\n\nUNDO BUTTON PRESSED";
		}
		if (key_ == 'R')
		{
			replay();
		}
		key_ = p_ui->getKeyPressFromUser();
	}
	p_ui->showResultsOnScreen(prepareEndMessage());
	cout << "\n\nWould you like to play again?";
	cin >> option;
	if (option == 'Y' || option == 'y')
	{
		replay();
	}
}
string MouseAndCatGame::prepareGrid()
{
	//prepare a string that holds the grid information
	ostringstream os;
	for (int row(1); row <= SIZE; ++row)	//for each row (vertically)
	{
		for (int col(1); col <= SIZE; ++col)	//for each column (horizontally)
		{
			if ((row == cat_.getY()) && (col == cat_.getX()))
				os << cat_.getSymbol();	//show cat
			else
				if ((row == mouse_.getY()) && (col == mouse_.getX()))
					os << mouse_.getSymbol();	//show mouse
				else 
					if ((row == nut_.getY()) && (col == nut_.getX()))
					os << nut_.getSymbol();    //show nut
				else
				{
					if (underground_.isAHole(col, row))
						os << underground_.getSymbol();	//show hole
					else
						os << FREECELL;	//show free grid cell
				}
		} //end of col-loop
		os << endl;
	} //end of row-loop
	os << "\nName: " << player_->getName();
	os << "	Score: " << player_->getScoreAmount();
	os << "\nPress C to activate cheat. Press R to reset game. Press U to undo last move.";
	os << "\nPress S to save the game. Press L to load the game. Press Q to quit.";
	return os.str();
} //end prepareGrid

bool MouseAndCatGame::isArrowKeyCode(int keycode) 
{
	return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}
void MouseAndCatGame::applyRules() 
{
	tempScore = player_->getScoreAmount();
	tempName = player_->getName();
	if (cat_.hasCaughtMouse())
		mouse_.die();
	else
	if (mouse_.canCollectNut(&nut_))
	{
		nut_.disappear();
	}

	//if ((mouse_.hasReachedAHole(underground_) && nut_.hasReachedAHole_(underground_) == true))
	//{
	//    mouse_.escapeIntoHole();
	//}
	if ((mouse_.hasReachedAHole(underground_) && nut_.hasBeenCollected() == true))
	{
		mouse_.escapeIntoHole();
	}
	if ((mouse_.hasReachedAHole(underground_) == true))
	{
		mouse_.transport();
	}
}
bool MouseAndCatGame::hasEnded(char key) 
{
	return ((key == 'Q') || (!mouse_.isAlive()) || (mouse_.hasEscaped()));
}
string MouseAndCatGame::prepareEndMessage() 
{
	ostringstream os;
	if (mouse_.hasEscaped())
	{
		os << "\n\nEND OF GAME: THE MOUSE ESCAPED UNDERGROUND!";
		player_->updateScoreAmount(1);
	}
	else
		if (!mouse_.isAlive())
		{
			os << "\n\nEND OF GAME: THE CAT ATE THE MOUSE!";
			player_->updateScoreAmount(-1);
		}
		else
			os << "\n\nEND OF GAME: THE PLAYER ENDED THE GAME!";
	return os.str();
}
void MouseAndCatGame::save()
{
	tempScore = player_->getScoreAmount();
	int mX(0), cX(0), mY(0), cY(0), scoreSave(0);
	bool nutCollected;
	ofstream outFile; 	//for output: save game into file
	outFile.open("Saves\\" + tempName + ".sav");
	if (outFile.fail())
	cout << "\nAn error has occurred when opening the file.";
	else
	{
		mX = mouse_.getX();
		cX = cat_.getX();
		mY = mouse_.getY();
		cY = cat_.getY();
		nutCollected = nut_.hasBeenCollected();
		//nutCollected = nut_.hasReachedAHole_(underground_);
		scoreSave = tempScore;

		outFile << mX << endl << mY << endl << cX << endl << cY << endl << nutCollected << endl << scoreSave << endl;
		outFile.close();
		cout << "\nThe game has been saved";
	}
}
void MouseAndCatGame::load()
{
	int mX(0), cX(0), mY(0), cY(0), scoreSave(0);
	bool nutCollected;
	ifstream inFile; 	//for input: read game from file
	inFile.open("Saves\\" + tempName + ".sav");
	if (inFile.fail())
		cout << "\nAn error has occurred when opening the file.";
	else
	{
		char a[6];

		inFile.getline(a, 6);
		mX = atoi(a);
		inFile.getline(a, 6);
		mY = atoi(a);
		inFile.getline(a, 6);
		cX = atoi(a);
		inFile.getline(a, 6);
		cY = atoi(a);
		inFile.getline(a, 6);
		nutCollected = atoi(a);
		inFile.getline(a, 6);
		scoreSave = atoi(a);

		inFile.close();
	}
	mouse_.setPosition(mX, mY);
	cat_.setPosition(cX, cY);
	player_->setScoreAmount(scoreSave);
	if (nutCollected == 1)
		nut_.disappear();
	else if (nutCollected == 0)
		nut_.appear();
	cout << "\nThe game has loaded";
}
void MouseAndCatGame::replay()
{
	cat_.positionAtRandom();
	mouse_.reset();
	nut_.appear();
	nut_.placeNut();
	applyRules();
	MouseAndCatGame::run();
}
void MouseAndCatGame::cheatMode()
{
	cheatModeStatus_ = !cheatModeStatus_;
	if (cheatModeStatus_)
	{
		cout << "\nCHEAT MODE ACTIVATED!";
	}
	else
	{
		cout << "\nCHEAT MODE DEACTIVATED!";
	}
}