#pragma once
#include "BetweenStages.h"

class Next : public BetweenStages
{
public:
	Next();
	~Next();

	//click the buttons
	virtual void click(sf::Vector2f mouse_pressed_pos, Controller & controller) override;
private:
	sf::Texture next;
};

