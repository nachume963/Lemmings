#pragma once

#include "Constants.h"

class GameBoard;

class Button
{
public:
	Button(sf::Vector2f pos, sf::Vector2f size, std::string name_file);
	virtual ~Button();

	//draw
	virtual void draw(sf::RenderWindow & window) const;

	//Pure virtual function
	virtual void click(GameBoard & game_board) = 0;
	//
	virtual void reduceTool(GameBoard & game_board) {};

	//get
	sf::FloatRect getGlobalBounds();
	bool getActiv();

protected:
	sf::Sprite m_button;
	sf::Texture T;
	bool m_activ;
};

