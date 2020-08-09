#include "Border.h"
#include "Lemming.h"


Border::Border(const sf::Vector2f pos, const sf::Vector2f size)
	:StaticObject(pos, size, "Files//Wall.png")
{
}


Border::~Border()
{
}

bool Border::collide(GameObject & other, GameBoard & board)
{
	return other.collide(*this, board);
}

bool Border::collide(Lemming & other, GameBoard & board)
{
	if (other.getSetStates(dig))
	{
		other.getSetStates(dig) = false;//Because it's a border
	}

	return false;
}