#pragma once
#include "Button.h"


class Tools : public Button
{
public:
	Tools(std::string name_file, int bottun_num, int uses_limits);
	virtual ~Tools();

	//draw
	virtual void draw(sf::RenderWindow & window) const;
	//reduce Tool
	virtual void reduceTool(GameBoard & game_board) override;

protected:
	int m_uses_limits;
	sf::Sprite m_button_pressed;
	sf::Font m_font;
	sf::Text m_text;
};

