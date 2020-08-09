#pragma once

#include "StaticObject.h"
class Lapid :
	public StaticObject
{
public:
	Lapid(const sf::Vector2f pos, const sf::Vector2f size);
	~Lapid();

	virtual void draw(sf::RenderWindow & window) override;

private:

	AnimationManager m_anim;
	sf::Vector2f m_size;
};

