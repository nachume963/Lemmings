#pragma once

#include "Button.h"
class Faster : public Button
{
public:
	Faster(int bottun_num);
	~Faster();

	//go faster
	virtual void click(GameBoard & game_board) override;

private:
	sf::Sprite m_button_pressed;
};

