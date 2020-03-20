#include "Interface.h" 

int Interface::getKeyPressFromUser() const {
//get key or command selected by user
	//read in the selected arrow key or command letter
	int keyPressed(_getch());
	//ignore symbol following cursor key
	while (keyPressed == 224) 
		keyPressed = _getch();
	//return the key in uppercase
	return(toupper(keyPressed));
}

void Interface::drawGridOnScreen(const string& gridData) const  {
	system("cls"); //clear screen
	cout << gridData;
}

void Interface::showResultsOnScreen(string message) const {
	cout << message;
}

void Interface::holdWindow() const  {
	cout << "\n\n";
	system("pause");
}
string Interface::getPlayerNameFromUser()
{
	string name;
	cout << "Enter Player name: ";
	cin >> name;
	return name;
}