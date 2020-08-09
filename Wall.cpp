#include "Wall.h"
#include "Lemming.h"


Wall::Wall(const sf::Vector2f pos, const sf::Vector2f size)
	:StaticObject(pos, size, "Files//Wall.png")
{
}
Wall::~Wall()
{
}

bool Wall::collide(GameObject & other, GameBoard & board)
{
	return other.collide(*this, board);	
}

bool Wall::collide(Lemming & other, GameBoard & board)
{
	sf::Uint8 t; 
	if (other.getState() == dig)
	{
		t = this->m_object.getColor().a;		
		if (t == 0)
			getSetActive() = false;			
		else
			this->m_object.setColor(sf::Color(255, 255, 255, sf::Uint8(t - 0.05)));
	}
	return false;
}
