#pragma once
#include "Tools.h"

class ClimbingWallConstruction : public Tools
{
public:
	ClimbingWallConstruction(int uses_limits, int bottun_num);
	~ClimbingWallConstruction();

	//set tool
	virtual void click(GameBoard & game_board) override;
};

