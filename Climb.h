#pragma once
#include "Tools.h"

class Climb : public Tools
{
public:
	Climb(int uses_limits, int bottun_num);
	~Climb();

	//set tool
	virtual void click(GameBoard & game_board) override;
};

