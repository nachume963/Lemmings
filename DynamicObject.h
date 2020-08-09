#pragma once
#include "GameObject.h"

class DynamicObject : public GameObject
{
public:
	DynamicObject() {};
	DynamicObject(const sf::Vector2f pos, const sf::Vector2f size, const std::string name_file);
	virtual ~DynamicObject();

	virtual bool collide(GameObject & other, GameBoard & board) override;
	virtual bool collide(ExitGate & other, GameBoard & board) override;
	virtual bool collide(EntranceGate & other, GameBoard & board) override;
	virtual bool collide(Wall & other, GameBoard & board) override;
	virtual bool collide(ClimbingWall & other, GameBoard & board) override;
	virtual bool collide(Lemming & other, GameBoard & board) override;
	virtual bool collide(Spikes & other, GameBoard & board)  override;
	virtual bool collide(Border & other, GameBoard & board) override;

protected:

	AnimationManager m_anim_move, m_anim_tool;
};

