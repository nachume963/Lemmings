#include "End.h"
#include "Controller.h"


End::End()
{
	//Arrange the sprites
	end.loadFromFile("Files//finish.png");
	exit.loadFromFile("Files//closed.png");

	m_central.setTexture(end);
	m_central.setPosition(sf::Vector2f(0, 0));
	m_central.scale(sf::Vector2f(WINDOE_SIZE.x / (m_central.getGlobalBounds().width),
		WINDOE_SIZE.y / m_central.getGlobalBounds().height));

	m_button1.setTexture(exit);
	m_button1.setPosition(sf::Vector2f(POSITON_BUTTON_BETWEEN, WINDOE_SIZE.y / 2));
	m_button1.scale(sf::Vector2f(SIZE_BUTTON_BETWEEN.x / (m_button1.getGlobalBounds().width),
		SIZE_BUTTON_BETWEEN.y / m_button1.getGlobalBounds().height));
}
End::~End()
{
}

void End::click(sf::Vector2f mouse_pressed_pos, Controller & controller)
{
	//close
	if (m_button1.getGlobalBounds().contains(mouse_pressed_pos))
		controller.finishGame();
	
	//run dmo game
	if (m_button2.getGlobalBounds().contains(mouse_pressed_pos))
		controller.runGame("Dmo Board.txt");
	
	//run game
	if (m_button3.getGlobalBounds().contains(mouse_pressed_pos))
		controller.runGame("Board.txt");
}
