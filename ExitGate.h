#pragma once
#include "StaticObject.h"
class ExitGate :
	public StaticObject
{
public:
	ExitGate(const sf::Vector2f pos, const sf::Vector2f size, int * p2score);
	~ExitGate();

	virtual int getLemmingInside() const override { return m_lemmings_inside;  };//sum of lemmings in the exit gata
	virtual bool collide(GameObject & other, GameBoard & board) override;
	virtual bool collide(Lemming & other, GameBoard & board) override;
private:
	int m_lemmings_inside;
	int * m_p2score;//to calculite scor
};

