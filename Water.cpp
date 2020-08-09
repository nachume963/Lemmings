#include "Water.h"



Water::Water(const sf::Vector2f pos, const sf::Vector2f size)
	:StaticObject(pos, size, "Files//level2.png")
{
	if (!m_anim.loadFromXML("Files//water.xml", *m_object.getTexture(), { 0.5f, 0.5f }))
		std::cerr << "cannot open file animation xml";
	m_anim.set("water");

	m_size = sf::Vector2f(m_object.getGlobalBounds().width, m_object.getGlobalBounds().height);
}


Water::~Water()
{
}

void Water::draw(sf::RenderWindow & window)
{
	m_anim.tick(5);
	m_anim.draw(window, sf::Vector2f(m_object.getPosition().x, m_object.getPosition().y + m_size.y));
}
