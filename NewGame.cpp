#include "NewGame.h"
#include "Controller.h"


NewGame::NewGame(int bottun_num)
	:Button(sf::Vector2f(POSITON_MENU.x, bottun_num * BUTTENS_SIZE + POSITON_MENU.y), SIZE_BUTTON, "Files//NewGame.png")
{
}
NewGame::~NewGame()
{
}

void NewGame::click(GameBoard & game_board)
{
	//start the game again
	throw std::string("New Game");
}
