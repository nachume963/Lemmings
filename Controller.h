#pragma once

#include "Constants.h"
#include "GameBoard.h"
#include "BetweenStages.h"
#include "GameMusic.h"

class Controller
{
public:
	Controller();
	~Controller();

	//run
	void run();
	//run game or dmo game
	void runGame(std::string name_file);

	//close
	void finishGame();
	
private:
	//read stages from file
	void readFromFile(std::ifstream & in);

	//draw
	void draw(sf::RenderWindow & window) const;
	//Handle Events
	void HandleEvents();

private:
	sf::RenderWindow m_window;
	std::unique_ptr<GameBoard> m_board;
	BetweenStages m_between_stages;
	sf::Clock m_clock;
	GameMusic music;

	bool m_finish_game;
	int m_score = 0;
};

