#pragma once
#include "Tools.h"

class StopSign : public Tools
{
public:
	StopSign(int uses_limits, int bottun_num);
	~StopSign();

	//set tool
	virtual void click(GameBoard & game_board) override;
};

