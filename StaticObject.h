#pragma once
#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	StaticObject(const sf::Vector2f pos, const sf::Vector2f size, const std::string name_file);
	virtual ~StaticObject();

	virtual bool collide(GameObject & other, GameBoard & board) override;
	virtual bool collide(ExitGate & other, GameBoard & board) override;
	virtual bool collide(EntranceGate & other, GameBoard & board) override;
	virtual bool collide(Wall & other, GameBoard & board) override;
	virtual bool collide(ClimbingWall & other, GameBoard & board) override;
	virtual bool collide(Lemming & other, GameBoard & board) override;
	virtual bool collide(Spikes & other, GameBoard & board) override;
	virtual bool collide(Border & other, GameBoard & board)  override;
};

