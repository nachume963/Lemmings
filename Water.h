#pragma once
#include "StaticObject.h"

class Water :
	public StaticObject
{
public:
	Water(const sf::Vector2f pos, const sf::Vector2f size);
	~Water();

	virtual void draw(sf::RenderWindow & window) override;

private:
	AnimationManager m_anim;
	sf::Vector2f m_size;
};

