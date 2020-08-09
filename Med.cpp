#include "Med.h"
#include "Controller.h"



Med::Med(int uses_limits, int bottun_num)
	:Tools("Files//Med.png", bottun_num, uses_limits)
{
}
Med::~Med()
{
}

void Med::click(GameBoard & game_board)
{
	//check uses limits
	if (m_uses_limits > 0)
	{
		if (game_board.getTool() == med)
			game_board.setTool(-1);
		else if (!m_activ) game_board.setTool(med);

		m_activ = !m_activ;
		std::swap(m_button, m_button_pressed);
	}
}
