#pragma once
#include "Constants.h"

class Controller;
class Start;
class End;
class Stay;
class Next;

static const sf::Vector2f SIZE_BUTTON_BETWEEN((BUTTENS_SIZE * 3), BUTTENS_SIZE);
static const float POSITON_BUTTON_BETWEEN = (WINDOE_SIZE.x / 2) - (SIZE_BUTTON_BETWEEN.x / 2);

class BetweenStages
{
public:
	BetweenStages();
	~BetweenStages();

	//Manage the transition to the next step
	void moveToNextStage(sf::RenderWindow & window, Controller & controller);
	//Managing a case that should remain a stage
	void remainThisStage(sf::RenderWindow & window, Controller & controller);
	//uns the beginning of the game
	void openingScreen(sf::RenderWindow & window, Controller & controller);
	//Runs the end of the game
	void finishScreen(sf::RenderWindow & window, Controller & controller);

	//draw
	void draw(sf::RenderWindow & window) const;
	//Handle Events
	void HandleEvents(sf::RenderWindow & window, Controller & controller);

protected:
	//Pressing the various buttons
	virtual void click(sf::Vector2f mouse_pressed_pos, Controller & controller) {};

protected:
	//To get out of the loop
	bool m_stil_wait;
	//different Sprite to main board and buttons
	sf::Sprite m_central, m_button1, m_button2, m_button3;
	//For the buttons
	sf::Texture play, play_dmo;
};

