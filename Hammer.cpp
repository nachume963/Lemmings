#include "Hammer.h"
#include "Controller.h"

Hammer::Hammer(int uses_limits, int bottun_num)
	:Tools("Files//Hammer.png", bottun_num, uses_limits)
{
}
Hammer::~Hammer()
{
}

void Hammer::click(GameBoard & game_board)
{
	//check uses limits
	if (m_uses_limits > 0)
	{
		if (game_board.getTool() == dig)
			game_board.setTool(-1);
		else if (!m_activ) game_board.setTool(dig);

		m_activ = !m_activ;
		std::swap(m_button, m_button_pressed);
	}
}
