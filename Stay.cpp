#include "Stay.h"
#include "Controller.h"


Stay::Stay()
{
	//Arrange the sprites
	stay.loadFromFile("Files//stay.png");

	m_central.setTexture(stay);
	m_central.setPosition(sf::Vector2f(0, 0));
	m_central.scale(sf::Vector2f(WINDOE_SIZE.x / (m_central.getGlobalBounds().width),
		WINDOE_SIZE.y / m_central.getGlobalBounds().height));

	m_button1.setPosition(sf::Vector2f(-1000.f, -1000.f));
	m_button2.setPosition(sf::Vector2f(-1000.f, -1000.f));
}
Stay::~Stay()
{
}

void Stay::click(sf::Vector2f mouse_pressed_pos, Controller & controller)
{
	//play again
	if (m_button3.getGlobalBounds().contains(mouse_pressed_pos))
		m_stil_wait = !m_stil_wait;
}
