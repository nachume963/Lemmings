#include "Controller.h"



Controller::Controller()
	:m_window(sf::VideoMode(int(WINDOE_SIZE.x), int(WINDOE_SIZE.y)),
		"Lemmings. prod by. Haim Fisher & Nachum Ehrlich", sf::Style::Default)
{
}
Controller::~Controller()
{
}

void Controller::run()
{
	GameMusic::sounds[gameMusic].play();//game music play
	GameMusic::sounds[gameMusic].setLoop(true);//play in loop
	
	//between stages management start
	m_between_stages.openingScreen(m_window, *this);
}
void Controller::runGame(std::string name_file)
{
	m_finish_game = false;
	//open file to read
	std::ifstream in;//to reed from file
	in.open(name_file);

	//stages loop
	while (m_window.isOpen())
	{
		readFromFile(in);//reed from file
		m_clock.restart();
		//game loop
		while (m_window.isOpen())
		{
			//try - catch the situations
			try
			{
				HandleEvents();
				m_board->Moves(m_clock);//move objects
				draw(m_window);//draw objects
			}
			catch (const std::out_of_range e)
			{
				e.what();
			}
			catch (const std::string message)
			{
				if (message == "Exit")
					finishGame();

				else if (message == "New Game")
				{
					m_score = 0;
					runGame(name_file);
				}

				else if (message == "Succeeded")
				{
					if (m_finish_game)
					{
						m_between_stages.finishScreen(m_window, *this);
						break;
					}
					else
					{
						m_between_stages.moveToNextStage(m_window, *this);

						break;
					}
				}
					
				else if (message == "Fails")
				{
					m_between_stages.remainThisStage(m_window, *this);
					m_board->restartLevel();
					m_clock.restart();
					continue;
				}
				else throw;
			}
		}
	}
	in.close();
}

void Controller::finishGame()
{
	//finish
	m_window.close();
}

void Controller::readFromFile(std::ifstream & in)
{
	//read the Ascii data
	std::vector<std::string> matrix_board;
	std::string line, lemmings_data, menu_data, stage;

	while (std::getline(in, stage) && !stage.size());//Loade first line
	std::getline(in, lemmings_data);
	std::getline(in, menu_data);
	while (std::getline(in, line) && line.size())
		matrix_board.push_back(line);

	m_board = std::make_unique <GameBoard>(matrix_board, lemmings_data, menu_data, std::stoi(stage), &m_score);

	//end of file - finish to read
	std::getline(in, line);
	if (in.eof())//if has come to end of file
		m_finish_game = !m_finish_game;
}

void Controller::draw(sf::RenderWindow & window) const
{
	//draw the board, menu, info
	window.clear(sf::Color(203, 187, 160));
	
	m_board->draw(window);
	
	window.display();
}
void Controller::HandleEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			finishGame();
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//Mapping the click
				sf::Vector2f mouse_pressed_pos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
				//Calls to button function or to board
				m_board->click(mouse_pressed_pos );
				
				//if restart level restart the clock
				if (RECT_MENU.contains(mouse_pressed_pos))
					m_clock.restart();
				break;
			}
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				finishGame();
			break;
		}
	}
}