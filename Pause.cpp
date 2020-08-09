#include "Pause.h"
#include "Controller.h"


Pause::Pause(int bottun_num)
	:Button(sf::Vector2f(POSITON_MENU.x, bottun_num * BUTTENS_SIZE + POSITON_MENU.y), SIZE_BUTTON, "Files//Pause.png")
{
	m_button_pressed = m_button;
	m_button_pressed.setColor(sf::Color(255, 255, 255, 128));
}
Pause::~Pause()
{
}

void Pause::click(GameBoard & game_board)
{
	//pause the game
	game_board.pause();
	std::swap(m_button, m_button_pressed);
}