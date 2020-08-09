#pragma once
#include "StaticObject.h"

class ClimbingWall : public StaticObject
{
public:
	ClimbingWall(const sf::Vector2f pos, const sf::Vector2f size, const std::string str, const int side);
	~ClimbingWall();

	virtual int getSide() const override; 

	virtual bool collide(GameObject & other, GameBoard & board) override;
	virtual bool collide(Lemming & other, GameBoard & board) override;

private:
	int m_side;
};

