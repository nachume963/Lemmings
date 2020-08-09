#pragma once
#include "Button.h"

class ResetLevel : public Button
{
public:
	ResetLevel(int bottun_num);
	~ResetLevel();

	//Reset Level
	virtual void click(GameBoard & game_board) override;
};

