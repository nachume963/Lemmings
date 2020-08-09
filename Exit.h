#pragma once
#include "Button.h"

class Exit : public Button
{
public:
	Exit(int bottun_num);
	~Exit();

	virtual void click(GameBoard & game_board) override;
};

