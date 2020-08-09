#include "Instruction.h"



Instruction::Instruction()
{
	//Arrange the sprites
	instruction.loadFromFile("Files//Lemmings_instruction.png");
	go_back.loadFromFile("Files//go_back.png");

	m_central.setTexture(instruction);
	m_central.setPosition(sf::Vector2f(0, 0));
	m_central.scale(sf::Vector2f(WINDOE_SIZE.x / (m_central.getGlobalBounds().width),
		WINDOE_SIZE.y / m_central.getGlobalBounds().height));

	m_button1.setTexture(go_back);
	m_button1.setPosition(POSITON_MENU);
	m_button1.scale(sf::Vector2f(BUTTENS_SIZE / (m_button1.getGlobalBounds().width),
		BUTTENS_SIZE / m_button1.getGlobalBounds().height));

	m_button2.setPosition(sf::Vector2f(-1000.f, -1000.f));
	m_button3.setPosition(sf::Vector2f(-1000.f, -1000.f));
}
Instruction::~Instruction()
{
}

void Instruction::click(sf::Vector2f mouse_pressed_pos, Controller & controller)
{
	//go back
	if (m_button1.getGlobalBounds().contains(mouse_pressed_pos))
		m_stil_wait = !m_stil_wait;
}
