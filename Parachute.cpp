#include "Parachute.h"
#include "Controller.h"

Parachute::Parachute(int uses_limits, int bottun_num)
	:Tools("Files//Parachute.png", bottun_num, uses_limits)
{
}
Parachute::~Parachute()
{
}

void Parachute::click(GameBoard & game_board)
{
	//check uses limits
	if (m_uses_limits > 0)
	{
		if (game_board.getTool() == parachute)
			game_board.setTool(-1);
		else if (!m_activ) game_board.setTool(parachute);

		m_activ = !m_activ;
		std::swap(m_button, m_button_pressed);
	}
}
