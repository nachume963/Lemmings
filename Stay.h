#pragma once
#include "BetweenStages.h"

class Stay : public BetweenStages
{
public:
	Stay();
	~Stay();

	//click the buttons
	virtual void click(sf::Vector2f mouse_pressed_pos, Controller & controller) override;
private:
	sf::Texture stay;
};

