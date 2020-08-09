#pragma once
#include "Button.h"

class NewGame : public Button
{
public:
	NewGame(int bottun_num);
	~NewGame();

	virtual void click(GameBoard & game_board) override;
};

