#include "GameObject.h"



GameObject::GameObject(const sf::Vector2f pos, const sf::Vector2f size, const std::string name_file)
{
	//Inserts the correct texture
	T.loadFromFile(name_file);
	m_object.setTexture(T);

	//Inserting the correct position
	m_object.setPosition(pos);

	//Adjusts the correct size
	m_object.scale(size.x / m_object.getGlobalBounds().width,
		size.y / m_object.getGlobalBounds().height);
}
GameObject::~GameObject()
{
}

void GameObject::draw(sf::RenderWindow & window)
{
	window.draw(m_object);
}

bool & GameObject::getSetActive()
{
	return m_active;
}

sf::FloatRect GameObject::getGlobalBounds() const
{
	return m_object.getGlobalBounds();
}
