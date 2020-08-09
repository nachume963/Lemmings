#pragma once
#include "Tools.h"

class Hammer : public Tools
{
public:
	Hammer(int uses_limits, int bottun_num);
	~Hammer();

	//set tool
	virtual void click(GameBoard & game_board) override;
};

