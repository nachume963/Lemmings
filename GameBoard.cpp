#include "GameBoard.h"
#include "Lemming.h"


GameBoard::GameBoard()
{
}
GameBoard::GameBoard(std::vector<std::string> & matrix_board, std::string lemmings_data, std::string menu_data, int stage, int * score)
	:m_matrix_board(matrix_board), m_lemmings_data(lemmings_data), m_menu_data(menu_data)
{
	T.loadFromFile("Files//background board.png");
	m_background_board.setTexture(T);
	m_background_board.setPosition(POSITON_BOARD);
	m_background_board.scale(BOARD_SIZE.x / m_background_board.getGlobalBounds().width,
		BOARD_SIZE.y / m_background_board.getGlobalBounds().height);
	
	m_lemming_speed = 100;//set spid
	m_p2score = score;//set score
	
	std::istringstream iss(lemmings_data);
	iss >> m_num_of_lemmings >> m_min_num_pass_lemmings;//put in data memory 

	m_info.setBasicData(stage, m_min_num_pass_lemmings);//set infobar

	setBoard();
}
GameBoard::~GameBoard()
{
}

void GameBoard::Moves(sf::Clock & clock)
{
	if (!m_pause)//if not game pause 
	{
		float delta = clock.restart().asSeconds();//get time from clock

		//get lemmings outside
		auto entrance_lemming = [&](auto o) { if (o->getSetActive()) o->entranceLemmings(delta, *this, m_info); };
		std::for_each(m_objects[entranceGate].begin(), m_objects[entranceGate].end(), entrance_lemming);

		//move lemmings
		auto move_lemming = [&](auto o) {if (o->getSetActive()) o->move(delta, *this); };
		std::for_each(m_objects[lemming].begin(), m_objects[lemming].end(), move_lemming);

		setInfo();
	}
	clock.restart();
}
void GameBoard::click(sf::Vector2f mouse_pressed_pos)
{
	if (!m_pause)//if not game pause 
	{
		if (RECT_MENU.contains(mouse_pressed_pos))//check if mouse click on menu
			m_menu->click(*this, mouse_pressed_pos);

		if (RECT_BOARD.contains(mouse_pressed_pos) && m_tool >= 0)//check if mouse click on board
			for (auto lemming : m_objects[lemming])
				if (lemming->getSetActive() && lemming->getGlobalBounds().contains(mouse_pressed_pos) && !lemming->get_tool(m_tool))//check if click on lemming
				{
					lemming->set_tool(m_tool);//set tool

					m_menu->reduceTool(*this);//reduce tool
					break;
				}
	}
	else
	{
		if (RECT_MENU.contains(mouse_pressed_pos))//check if mouse click on basic menu
			m_menu->clickBasicMenu(*this, mouse_pressed_pos);
	}
}
void GameBoard::draw(sf::RenderWindow & window)//draw all objects
{
	window.draw(m_background_board);
	
	m_menu->draw(window);//draw menu
	m_info.draw(window);//draw info

	auto draw_obj = [&](auto o) { if (o->getSetActive()) o->draw(window); };
	auto draw_vec = [&](auto pair) { std::for_each(pair.second.begin(), pair.second.end(), draw_obj); };

	std::for_each(m_objects.begin(), m_objects.end(), draw_vec);
}

void GameBoard::CheckCollisionWithAllObjects(GameObject & object)
{
	//Checks collision with all other objects
	auto check_collision_with_obj = [&](auto o) { if (o->getSetActive() && object.getGlobalBounds().intersects(o->getGlobalBounds())) object.collide(*o, *this); };
	auto check_collision_with_vec = [&](auto pair) { std::for_each(pair.second.begin(), pair.second.end(), check_collision_with_obj); };

	std::for_each(m_objects.begin(), m_objects.end(), check_collision_with_vec);
}
bool GameBoard::ChecksCollisionWithParticularType(GameObject & object, int type)
{
	bool b = false;
	//Checks collision with particular type
	auto check_collision_with_obj = [&](auto o) { if (o->getSetActive() && object.getGlobalBounds().intersects(o->getGlobalBounds())) { b = true; object.collide(*o, *this); } };
	std::for_each(m_objects[type].begin(), m_objects[type].end(), check_collision_with_obj);

	return b;
}
bool GameBoard::ChecksCollisionWithParticularType(GameObject & object, sf::Vector2f point, int type)
{
	bool b = false;
	//Checks collision with point particular type
	auto check_collision_with_point = [&](auto o) { if (o->getSetActive() && o->getGlobalBounds().contains(point)) { b = true; object.collide(*o, *this);}};
	std::for_each(m_objects[type].begin(), m_objects[type].end(), check_collision_with_point);

	return b;
}
bool GameBoard::ChecksCollisionWithWallAndClimbingWall(GameObject & object, sf::Vector2f point, int sort)
{
	bool b = false;
	//Checks collision with ClimbingWall
	auto check_collision_with_point = [&](auto o) { if (o->getSetActive() && (o->getSide() == sort || o->getSide() == 3) && o->getGlobalBounds().contains(point)) { b = true; object.collide(*o, *this); } };
	std::for_each(m_objects[wall].begin(), m_objects[wall].end(), check_collision_with_point);

	return b;
}
float GameBoard::getPosOfObjectDownLemming(GameObject & object, sf::Vector2f point)
{
	float H(0.f);
	//get pos of object down lemming
	auto check_collision_with_point = [&](auto o) { if (o->getSetActive() && o->getGlobalBounds().contains(point)) { H = (o->getPos().y - OBJECT_SIZE.y); }};
	std::for_each(m_objects[wall].begin(), m_objects[wall].end(), check_collision_with_point);

	return H;
}

void GameBoard::restartLevel()
{
	//set board from the start
	setBoard();
	setSpeed(100);
	m_info.resetNumOfLemmings();
}

void GameBoard::setBoard()
{	
	//make menu
	m_menu = std::make_unique<Menu>(m_menu_data);
	//clear m_objects
	m_objects.clear();
	//set size object
	OBJECT_SIZE = { BOARD_SIZE.x / m_matrix_board[0].size(), BOARD_SIZE.y / m_matrix_board.size() };
	
	//go over the ascii
	for (size_t i = 0; i < m_matrix_board.size(); i++)
		for (size_t j = 0; j < m_matrix_board[i].size(); j++)
			if (m_matrix_board[i][j] != ' ')
				setGameObject(sf::Vector2f((OBJECT_SIZE.x * j) + POSITON_BOARD.x,
					(OBJECT_SIZE.y * (i)) + POSITON_BOARD.y), OBJECT_SIZE, m_matrix_board[i][j]);
}
void GameBoard::setGameObject(sf::Vector2f pos, sf::Vector2f size, char c)
{
	//set object by char
	switch (c)
	{
	//case '/':
	//	m_objects[lemming].push_back(std::make_shared<Lemming>(pos, size));
	//	break;
	case '#':
		m_objects[wall].push_back(std::make_shared<Wall>(pos, size));
		break;
	case '&':
		m_objects[wall].push_back(std::make_shared<Border>(pos, size));
		break;
	case '*':
		m_objects[wall].push_back(std::make_shared<Spikes>(pos, size));
		break;
	case 'D':
		m_objects[entranceGate].push_back(std::make_shared<EntranceGate>(pos, size, m_num_of_lemmings));
		for (size_t i = 0; i < m_num_of_lemmings; i++)
		{
			m_objects[lemming].push_back(std::make_shared<Lemming>(pos, size, &m_lemming_speed));
		}
		break;
	case 'E':
		m_objects[exitGate].push_back(std::make_shared<ExitGate>(pos, size, m_p2score));
		break;
	case 'R':
		m_objects[wall].push_back(std::make_shared<ClimbingWall>(pos, size, "Files//Climbing Wall R.png", right));
		break;
	case 'L':
		m_objects[wall].push_back(std::make_shared<ClimbingWall>(pos, size, "Files//Climbing Wall L.png", left));
		break;
	case 'W':
		m_objects[water].push_back(std::make_shared<Water>(pos, size));
		break;
	case 'P':
		m_objects[lapid].push_back(std::make_shared<Lapid>(pos, size));
		break;
	case ' ':
	default:
		break;
	}
}

void GameBoard::setInfo()
{
	int pass = 0, deads = 0;
	
	//get detaiks
	pass = m_objects[exitGate][0]->getLemmingInside();
	m_info.setPassLemmings(pass);
	
	auto check_dead = [&](auto o) {if (o->checkDead()) deads++; };
	std::for_each(m_objects[lemming].begin(), m_objects[lemming].end(), check_dead);

	//set info
	m_info.setDeadLemmings(deads);
	m_info.setScore(*m_p2score);

	//if succeeded
	if(pass + deads == m_num_of_lemmings && pass >= m_min_num_pass_lemmings)
		throw std::string("Succeeded");
	//if fails
	if(m_num_of_lemmings - deads < m_min_num_pass_lemmings)
		throw std::string("Fails");
}