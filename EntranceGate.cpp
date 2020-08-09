#include "EntranceGate.h"

EntranceGate::EntranceGate(const sf::Vector2f pos, const sf::Vector2f size, int num_of_lemmings)
	:StaticObject(pos, size, "Files//EntranceGate.png"), m_num_of_lemmings(num_of_lemmings)
{
}
EntranceGate::~EntranceGate()
{
}

void EntranceGate::entranceLemmings(const float delta, GameBoard & bord, InfoBar & info)
{
	static float time = -1.50;//Because of the first lemming
	time += delta;//edd delta time to time
	while (time > 1.50 && m_num_of_lemmings > 0)
	{
		time = 0;
		bord.getObjectsByKey(lemming)[--m_num_of_lemmings]->getSetActive() = true;//release lemming
		info.setNumOfLemmings();
	}
}
