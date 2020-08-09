#pragma once
#include "StaticObject.h"
class Spikes :
	public StaticObject
{
public:
	Spikes(const sf::Vector2f pos, const sf::Vector2f size);
	~Spikes();

	virtual bool collide(GameObject & other, GameBoard & board)override;
	virtual bool collide(Lemming & other, GameBoard & board)override;
};

