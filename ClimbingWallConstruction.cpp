#include "ClimbingWallConstruction.h"
#include "Controller.h"

ClimbingWallConstruction::ClimbingWallConstruction(int uses_limits, int bottun_num)
	:Tools("Files//ClimbingWallConstruction.png", bottun_num, uses_limits)
{
}
ClimbingWallConstruction::~ClimbingWallConstruction()
{
}

void ClimbingWallConstruction::click(GameBoard & game_board)
{
	//check uses limits
	if (m_uses_limits > 0)
	{
		if (game_board.getTool() == climbing_Wall)
			game_board.setTool(-1);
		else if (!m_activ) game_board.setTool(climbing_Wall);

		m_activ = !m_activ;
		std::swap(m_button, m_button_pressed);
	}
}
