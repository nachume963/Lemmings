#include "ClimbingWall.h"
#include "Lemming.h"


ClimbingWall::ClimbingWall(const sf::Vector2f pos, const sf::Vector2f size, const std::string str, const int side)
	:StaticObject(pos, size, str), m_side(side)
{
	m_object.scale((size.x / m_object.getGlobalBounds().width) + 0.119f + 1.f,
		(size.y / m_object.getGlobalBounds().height));
}
ClimbingWall::~ClimbingWall()
{
}

int ClimbingWall::getSide() const
{
	return m_side;
}

bool ClimbingWall::collide(GameObject & other, GameBoard & board)
{
	return other.collide(*this, board);
}

bool ClimbingWall::collide(Lemming & other, GameBoard & board)
{
	sf::Uint8 t; 
	if (other.getState() == dig)//endel dig stairs
	{
		t = this->m_object.getColor().a;
		if (t == 0)
			getSetActive() = false;
		else
			this->m_object.setColor(sf::Color(255, 255, 255, sf::Uint8(t - 0.05)));
	}

	if (other.getDirection() == right)//the stairs givs the lemibg the option to climb on them
	{
		if (getGlobalBounds().contains(other.getCordinate(up_r)))//Checks that the lemming is in range to get a climb
		{
			other.set_tool(climb);
		}
	}
	else
	{
		if (getGlobalBounds().contains(other.getCordinate(up_l)))//Checks that the lemming is in range to get a climb
		{
			other.set_tool(climb);
		}
	}
	return false;
}
