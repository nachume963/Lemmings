#pragma once
#include "Tools.h"

class Parachute : public Tools
{
public:
	Parachute(int uses_limits, int bottun_num);
	virtual ~Parachute();

	//set tool
	virtual void click(GameBoard & game_board) override;
};

