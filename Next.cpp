#include "Next.h"
#include "Controller.h"


Next::Next()
{
	//Arrange the sprites
	next.loadFromFile("Files//next.png");

	m_central.setTexture(next);
	m_central.setPosition(sf::Vector2f(0, 0));
	m_central.scale(sf::Vector2f(WINDOE_SIZE.x / (m_central.getGlobalBounds().width),
		WINDOE_SIZE.y / m_central.getGlobalBounds().height));

	m_button1.setPosition(sf::Vector2f(-1000.0, -1000.0));
	m_button2.setPosition(sf::Vector2f(-1000.0, -1000.0));
}
Next::~Next()
{
}

void Next::click(sf::Vector2f mouse_pressed_pos, Controller & controller)
{
	//play next
	if (m_button3.getGlobalBounds().contains(mouse_pressed_pos))
		m_stil_wait = !m_stil_wait;
}
