#include "ExitGate.h"
#include "Lemming.h"


ExitGate::ExitGate(const sf::Vector2f pos, const sf::Vector2f size, int * p2score)
	:StaticObject(pos, size, "Files//ExitGate.png"), m_lemmings_inside(0), m_p2score(p2score)
{
}
ExitGate::~ExitGate()
{
}

bool ExitGate::collide(GameObject & other, GameBoard & board)
{
	return other.collide(*this, board);//polimorfizem
}

bool ExitGate::collide(Lemming & other, GameBoard & board)
{
	m_lemmings_inside++;//num of lemming in the gate
	*m_p2score += 2;//update barinfo
	other.getSetActive() = 0;//lemming off
	return false;
}
