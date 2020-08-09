#include "BetweenStages.h"
#include "Controller.h"

#include "Start.h"
#include "End.h"
#include "Stay.h"
#include "Next.h"

BetweenStages::BetweenStages()
{
	//Arrange the sprites
	play.loadFromFile("Files//play.png");
	play_dmo.loadFromFile("Files//play dmo.png");

	m_button2.setTexture(play_dmo);
	m_button2.setPosition(sf::Vector2f(POSITON_BUTTON_BETWEEN, (WINDOE_SIZE.y / 2) + (1.3f * SIZE_BUTTON_BETWEEN.y)));
	m_button2.scale(sf::Vector2f(SIZE_BUTTON_BETWEEN.x / (m_button2.getGlobalBounds().width),
		SIZE_BUTTON_BETWEEN.y / m_button2.getGlobalBounds().height));
	
	m_button3.setTexture(play);
	m_button3.setPosition(sf::Vector2f(POSITON_BUTTON_BETWEEN, (WINDOE_SIZE.y / 2) + (2.6f * SIZE_BUTTON_BETWEEN.y)));
	m_button3.scale(sf::Vector2f(SIZE_BUTTON_BETWEEN.x / (m_button3.getGlobalBounds().width),
		SIZE_BUTTON_BETWEEN.y / m_button3.getGlobalBounds().height));
}
BetweenStages::~BetweenStages()
{
}

void BetweenStages::draw(sf::RenderWindow & window) const
{
	//draw all
	window.draw(m_central);
	window.draw(m_button1);
	window.draw(m_button2);
	window.draw(m_button3);
	window.display();
}
void BetweenStages::HandleEvents(sf::RenderWindow & window, Controller & controller)
{
	sf::Event event;
	m_stil_wait = true;
	//Waiting for the order
	while (window.waitEvent(event) && m_stil_wait)
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//Mapping the click
				sf::Vector2f mouse_pressed_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				//Calls to button function
				click(mouse_pressed_pos, controller);

				break;
			}
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				break;
			break;
		}
	}
}

void BetweenStages::moveToNextStage(sf::RenderWindow & window, Controller & controller)
{
	//Activates the next stage
	Next next;

	next.draw(window);
	next.HandleEvents(window, controller);
}
void BetweenStages::remainThisStage(sf::RenderWindow & window, Controller & controller)
{
	// stay in the stage
	Stay stay;

	stay.draw(window);
	stay.HandleEvents(window, controller);
}
void BetweenStages::openingScreen(sf::RenderWindow & window, Controller & controller)
{
	//Manage the start
	Start start;

	start.draw(window);
	start.HandleEvents(window, controller);
}
void BetweenStages::finishScreen(sf::RenderWindow & window, Controller & controller)
{
	//Manage the end
	End end;

	end.draw(window);
	end.HandleEvents(window, controller);
}
