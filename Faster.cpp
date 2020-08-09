#include "Faster.h"
#include "Controller.h"


Faster::Faster(int bottun_num)
	:Button(sf::Vector2f(POSITON_MENU.x, bottun_num * BUTTENS_SIZE + POSITON_MENU.y), SIZE_BUTTON, "Files//speedometer.png")
{
	m_button_pressed = m_button;
	m_button_pressed.setColor(sf::Color(255, 255, 255, 128));
}
Faster::~Faster()
{
}

void Faster::click(GameBoard & game_board)
{
	//move faster
	m_button = m_button_pressed;
	game_board.setSpeed(300);
}
