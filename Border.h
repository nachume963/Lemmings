#pragma once
#include "StaticObject.h"
class Border :
	public StaticObject
{
public:
	Border(const sf::Vector2f pos, const sf::Vector2f size);
	~Border();

	virtual bool collide(GameObject & other, GameBoard & board) override;
	virtual bool collide(Lemming & other, GameBoard & board) override;
};

