#pragma once
#include "BetweenStages.h"

class Instruction :	public BetweenStages
{
public:
	Instruction();
	~Instruction();

	//click the buttons
	virtual void click(sf::Vector2f mouse_pressed_pos, Controller & controller) override;

private:
	sf::Texture instruction, go_back;
};

