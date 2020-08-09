#include "Exit.h"
#include "Controller.h"


Exit::Exit(int bottun_num)
	:Button(sf::Vector2f(POSITON_MENU.x, bottun_num * BUTTENS_SIZE + POSITON_MENU.y), SIZE_BUTTON, "Files//Exit.png")
{
}
Exit::~Exit()
{
}

void Exit::click(GameBoard & game_board)
{
	//close the windo
	throw std::string("Exit");
}
