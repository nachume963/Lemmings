#include "Menu.h"

#include "Exit.h"
#include "NewGame.h"
#include "ResetLevel.h"
#include "Pause.h"
#include "Faster.h"
#include "Tools.h"
#include "StopSign.h"
#include "Hammer.h"
#include "Parachute.h"
#include "ClimbingWallConstruction.h"
#include "Climb.h"
#include "Med.h"

Menu::Menu()
{
	initBasicMenu();
}
Menu::Menu(std::string baseic_data)
{
	initBasicMenu();

	std::istringstream iss(baseic_data);
	std::string tool;
	int num;

	while (iss >> tool >> num)
		addTool(tool, num);
}
Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow & window) const
{
	window.draw(m_background_menu);

	auto draw_button = [&](auto b) { b->draw(window); };
	std::for_each(m_buttons.begin(), m_buttons.end(), draw_button);
}

void Menu::click(GameBoard & game_board, sf::Vector2f mouse_button_pos)
{
	for (size_t i = 0; i < m_buttons.size(); i++)
		if (m_buttons[i]->getGlobalBounds().contains(mouse_button_pos) || m_buttons[i]->getActiv())
		{
			m_buttons[i]->click(game_board);
		
			if (i < NUM_OF_BASIC_BUTTENS)
				break;
		}	
}
void Menu::clickBasicMenu(GameBoard & game_board, sf::Vector2f mouse_button_pos)
{
	for (size_t i = 0; i < NUM_OF_BASIC_BUTTENS; i++)
		if (m_buttons[i]->getGlobalBounds().contains(mouse_button_pos))
		{
			m_buttons[i]->click(game_board);
				break;
		}
}
void Menu::clickTools(GameBoard & game_board, sf::Vector2f mouse_button_pos)
{
	auto click_button = [&](auto b) { if (b->getGlobalBounds().contains(mouse_button_pos) || b->getActiv()) b->click(game_board); };
	std::for_each(m_buttons.begin() + NUM_OF_BASIC_BUTTENS, m_buttons.end(), click_button);
}

void Menu::reduceTool(GameBoard & game_board)
{
	auto reducetool = [&](auto b) { if(b->getActiv()) b->reduceTool(game_board); };
	std::for_each(m_buttons.begin() + NUM_OF_BASIC_BUTTENS, m_buttons.end(), reducetool);
}

void Menu::initBasicMenu()
{
	m_background_menu.setSize(sf::Vector2f((WINDOE_SIZE.x - BOARD_SIZE.x), BOARD_SIZE.y));
	m_background_menu.setPosition(sf::Vector2f(BOARD_SIZE.x, 0.f));
	m_background_menu.setFillColor(sf::Color::Black);
	

	//constructor. Initializing 3 buttons:
	//Exit
	m_buttons.push_back(std::make_shared<Exit>(m_num_of_buttons++));
	//Reset level
	m_buttons.push_back(std::make_shared<ResetLevel>(m_num_of_buttons++));
	//New game
	m_buttons.push_back(std::make_shared<NewGame>(m_num_of_buttons++));
	//pause
	m_buttons.push_back(std::make_shared<Pause>(m_num_of_buttons++));
	//faster
	m_buttons.push_back(std::make_shared<Faster>(m_num_of_buttons++));
}
void Menu::addTool(std::string tool, int uses_limits)
{
	if (tool == "StopSign")
	{
		m_buttons.push_back(std::make_shared<StopSign>(uses_limits, m_num_of_buttons++));
	}
	if (tool == "Hammer")
	{
		m_buttons.push_back(std::make_shared<Hammer>(uses_limits, m_num_of_buttons++));
	}
	if (tool == "Parachute")
	{
		m_buttons.push_back(std::make_shared<Parachute>(uses_limits, m_num_of_buttons++));
	}
	if (tool == "StairsConstruction")
	{
		m_buttons.push_back(std::make_shared<ClimbingWallConstruction>(uses_limits, m_num_of_buttons++));
	}
	if (tool == "Climb")
	{
		m_buttons.push_back(std::make_shared<Climb>(uses_limits, m_num_of_buttons++));
	}
	if (tool == "Med")
	{
		m_buttons.push_back(std::make_shared<Med>(uses_limits, m_num_of_buttons++));
	}
}
