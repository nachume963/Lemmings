#pragma once
#include "BetweenStages.h"

class Instruction;

class Start : public BetweenStages
{
public:
	Start();
	~Start();

	//click the buttons
	virtual void click(sf::Vector2f mouse_pressed_pos, Controller & controller) override;
private:
	sf::Texture start, instruction;
};

