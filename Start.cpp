#include "Start.h"
#include "Controller.h"
#include "Instruction.h"


Start::Start()
{
	//Arrange the sprites
	start.loadFromFile("Files//start.png");
	instruction.loadFromFile("Files//instruction.png");

	m_central.setTexture(start);
	m_central.setPosition(sf::Vector2f(0, 0));
	m_central.scale(sf::Vector2f(WINDOE_SIZE.x / (m_central.getGlobalBounds().width),
		WINDOE_SIZE.y / m_central.getGlobalBounds().height));

	m_button1.setTexture(instruction);
	m_button1.setPosition(sf::Vector2f(POSITON_BUTTON_BETWEEN, WINDOE_SIZE.y / 2));
	m_button1.scale(sf::Vector2f(SIZE_BUTTON_BETWEEN.x / (m_button1.getGlobalBounds().width),
		SIZE_BUTTON_BETWEEN.y / m_button1.getGlobalBounds().height));
}
Start::~Start()
{
}

void Start::click(sf::Vector2f mouse_pressed_pos, Controller & controller)
{
	//instruction
	if (m_button1.getGlobalBounds().contains(mouse_pressed_pos))
	{
		sf::RenderWindow window(sf::VideoMode(int(WINDOE_SIZE.x), int(WINDOE_SIZE.y)), "Instruction", sf::Style::Default);
		Instruction instruction_;

		instruction_.draw(window);
		instruction_.HandleEvents(window, controller);
	}

	//run dmo game
	if (m_button2.getGlobalBounds().contains(mouse_pressed_pos))
		controller.runGame("Dmo Board.txt");
	
	//run game
	if (m_button3.getGlobalBounds().contains(mouse_pressed_pos))
		controller.runGame("Board.txt");
}
