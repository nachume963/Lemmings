#include "ResetLevel.h"
#include "Controller.h"


ResetLevel::ResetLevel(int bottun_num)
	:Button(sf::Vector2f(POSITON_MENU.x, bottun_num * BUTTENS_SIZE + POSITON_MENU.y), SIZE_BUTTON, "Files//ResetLevel.png")
{
}
ResetLevel::~ResetLevel()
{
}

void ResetLevel::click(GameBoard & game_board)
{
	//restart stage
	game_board.restartLevel();
}
