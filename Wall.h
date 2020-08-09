#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	Wall(const sf::Vector2f pos, const sf::Vector2f size);
	~Wall();

	virtual bool collide(GameObject & other, GameBoard & board) override;
	virtual bool collide(Lemming & other, GameBoard & board) override;
};

