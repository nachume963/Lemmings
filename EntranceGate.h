#pragma once
#include "StaticObject.h"
#include "GameBoard.h"

class EntranceGate :
	public StaticObject
{
public:
	EntranceGate(const sf::Vector2f pos, const sf::Vector2f size, int num_of_lemmings);
	~EntranceGate();

	void entranceLemmings(const float delta, GameBoard & bord, InfoBar & info);//set info and data to endel the entrance of Lemming into level

private:
	int m_num_of_lemmings;
};

