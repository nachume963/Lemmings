#include "Spikes.h"
#include "Lemming.h"



Spikes::Spikes(const sf::Vector2f pos, const sf::Vector2f size)
	:StaticObject(pos, size, "Files//Spikes.png")
{
	m_object.scale(0.95f, 0.95f);
}


Spikes::~Spikes()
{
}

bool Spikes::collide(GameObject & other, GameBoard & board)
{
	return other.collide(*this, board);
}

bool Spikes::collide(Lemming & other, GameBoard & board)
{
	other.setDead();
	other.getSetActive() = false;
	return false;
}
