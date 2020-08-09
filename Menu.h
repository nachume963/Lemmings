#pragma once

#include "Constants.h"
#include "Button.h"

class Menu
{
public:
	Menu();
	Menu(std::string baseic_data);
	~Menu();

	void draw(sf::RenderWindow & window) const;

	//Function that activates the function by pressing the button
	void click(GameBoard & game_board, sf::Vector2f mouse_button_pos);
	void clickBasicMenu(GameBoard & game_board, sf::Vector2f mouse_button_pos);
	void clickTools(GameBoard & game_board, sf::Vector2f mouse_button_pos);
	void reduceTool(GameBoard & game_board);

private:
	void initBasicMenu();
	void addTool(std::string tool, int num);

private:
	//Vector of pointers to buttons
	std::vector <std::shared_ptr<Button>> m_buttons;
	int m_num_of_buttons = 0;
	sf::RectangleShape m_background_menu;
};

