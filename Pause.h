#pragma once
#include "Button.h"

class Pause : public Button
{
public:
	Pause(int bottun_num);
	~Pause();

	//Pause
	virtual void click(GameBoard & game_board) override;

private:
	sf::Sprite m_button_pressed;
};

