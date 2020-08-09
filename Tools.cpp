#include "Tools.h"
#include "Controller.h"

Tools::Tools(std::string name_file, int bottun_num, int uses_limits)
	: Button(sf::Vector2f(POSITON_MENU.x, bottun_num * BUTTENS_SIZE + POSITON_MENU.y), SIZE_BUTTON, name_file), m_uses_limits(uses_limits)
{
	m_button_pressed = m_button;
	m_button_pressed.setColor(sf::Color(255, 255, 255, 128));

	m_font.loadFromFile("Files//aaa.ttf");
}
Tools::~Tools()
{
}


void Tools::draw(sf::RenderWindow & window) const
{
	window.draw(m_button);
	
	//draw rec uses limits
	sf::RectangleShape rec(sf::Vector2f(BUTTENS_SIZE / 3, BUTTENS_SIZE / 3));
	rec.setPosition(m_button.getPosition());
	rec.setFillColor(sf::Color::White);
	window.draw(rec);

	//draw uses limits
	sf::Text Line(std::to_string(m_uses_limits), m_font, 25);
	Line.setPosition(m_button.getPosition());
	Line.setFillColor(sf::Color::Black);
	window.draw(Line);
}

void Tools::reduceTool(GameBoard & game_board)
{
	//reduce Tool
	if (!--m_uses_limits)
	{
		game_board.setTool(-1);
		m_activ = !m_activ;
	}
}
