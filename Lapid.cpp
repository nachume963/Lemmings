#include "Lapid.h"



Lapid::Lapid(const sf::Vector2f pos, const sf::Vector2f size)
	:StaticObject(pos, size, "Files//level3.png")
{
	if (!m_anim.loadFromXML("Files//lapid.xml", *m_object.getTexture(), { 0.5f, 0.5f }))
		std::cerr << "cannot open file animation xml";
	m_anim.set("lapid");

	m_size = sf::Vector2f(m_object.getGlobalBounds().width, m_object.getGlobalBounds().height);
}


Lapid::~Lapid()
{
}

void Lapid::draw(sf::RenderWindow & window)
{
	m_anim.tick(5);//zip in animtion 
	m_anim.draw(window, sf::Vector2f(m_object.getPosition().x, m_object.getPosition().y + m_size.y));
}

