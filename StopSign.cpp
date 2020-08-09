#include "StopSign.h"
#include "Controller.h"

StopSign::StopSign(int uses_limits, int bottun_num)
	:Tools("Files//StopSign.png", bottun_num, uses_limits)
{
}
StopSign::~StopSign()
{
}

void StopSign::click(GameBoard & game_board)
{
	//check uses limits
	if (m_uses_limits > 0)
	{
		if (game_board.getTool() == stop)
			game_board.setTool(-1);
		else if (!m_activ) game_board.setTool(stop);

		m_activ = !m_activ;
		std::swap(m_button, m_button_pressed);
	}
}
