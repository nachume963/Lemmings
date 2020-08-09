#include "DynamicObject.h"
#include "Lemming.h"


DynamicObject::DynamicObject(const sf::Vector2f pos, const sf::Vector2f size, const std::string name_file)
	:GameObject(pos, size, name_file)
{

}
DynamicObject::~DynamicObject()
{
}

bool DynamicObject::collide(GameObject & other, GameBoard & board)
{
	return other.collide(*this, board);
}

bool DynamicObject::collide(ExitGate & other, GameBoard & board)
{
	return false;
}

bool DynamicObject::collide(EntranceGate & other, GameBoard & board)
{
	return false;
}

bool DynamicObject::collide(Wall & other, GameBoard & board)
{
	return false;
}

bool DynamicObject::collide(ClimbingWall & other, GameBoard & board)
{
	return false;
}

bool DynamicObject::collide(Lemming & other, GameBoard & board)
{
	return false;
}

bool DynamicObject::collide(Spikes & other, GameBoard & board)
{
	return false;
}

bool DynamicObject::collide(Border & other, GameBoard & board)
{
	return false;
}
