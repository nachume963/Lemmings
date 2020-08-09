#pragma once
#include "Tools.h"

class Med : public Tools
{
public:
	Med(int uses_limits, int bottun_num);
	~Med();

	//set tool
	virtual void click(GameBoard & game_board) override;
};

