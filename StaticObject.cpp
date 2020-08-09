#include "StaticObject.h"


StaticObject::StaticObject(const sf::Vector2f pos, const sf::Vector2f size, const std::string name_file)
	:GameObject(pos, size, name_file)
{
}
StaticObject::~StaticObject()
{
}

bool StaticObject::collide(GameObject & other, GameBoard & board)
{
	return false;
}

bool StaticObject::collide(ExitGate & other, GameBoard & board)
{
	return false;
}

bool StaticObject::collide(EntranceGate & other, GameBoard & board)
{
	return false;
}

bool StaticObject::collide(Wall & other, GameBoard & board)
{
	return false;
}

bool StaticObject::collide(ClimbingWall & other, GameBoard & board)
{
	return false;
}

bool StaticObject::collide(Lemming & other, GameBoard & board)
{
	return false;
}

bool StaticObject::collide(Spikes & other, GameBoard & board)
{
	return false;
}

bool StaticObject::collide(Border & other, GameBoard & board)
{
	return false;
}
