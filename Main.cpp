#include "MouseAndCatGame.h"
int main()
{
	Interface ui;
	Player player(ui.getPlayerNameFromUser());
	MouseAndCatGame game(&ui, &player);

	game.run();

	ui.holdWindow();
	return 0;
}