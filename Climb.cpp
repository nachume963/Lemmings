#include "Climb.h"
#include "Controller.h"

Climb::Climb(int uses_limits, int bottun_num)
	:Tools("Files//Climb.png", bottun_num, uses_limits)
{
}
Climb::~Climb()
{
}

void Climb::click(GameBoard & game_board)
{
	//check uses limits
	if (m_uses_limits > 0)
	{
		if (game_board.getTool() == climb)
			game_board.setTool(-1);
		else if (!m_activ) game_board.setTool(climb);

		m_activ = !m_activ;
		std::swap(m_button, m_button_pressed);
	}
}
