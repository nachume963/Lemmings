#pragma once
#include "BetweenStages.h"

class End : public BetweenStages
{
public:
	End();
	~End();

	//click the buttons
	virtual void click(sf::Vector2f mouse_pressed_pos, Controller & controller) override;
private:
	sf::Texture end, exit;
};

