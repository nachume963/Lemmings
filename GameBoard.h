#pragma once

#include "Constants.h"

#include "Menu.h"
#include "InfoBar.h"
#include "GameObject.h"

#include "Lemming.h"
#include "Wall.h"
#include "ExitGate.h"
#include "EntranceGate.h"
#include "ClimbingWall.h"
#include "Water.h"
#include "Lapid.h"
#include "Border.h"
#include "Spikes.h"

class GameBoard
{
public:
	GameBoard();
	GameBoard(std::vector<std::string> & matrix_board, std::string lemmings_data, std::string menu_data, int stage, int * score);
	~GameBoard();

	//basic functions
	void Moves(sf::Clock & clock);//move objects
	void click(sf::Vector2f mouse_pressed_pos);//endel click on bord
	void draw(sf::RenderWindow & window);//draw objects
	
	//check collision
	void CheckCollisionWithAllObjects(GameObject & object);//Checks collision with all other objects
	bool ChecksCollisionWithParticularType(GameObject & object, int type);//Checks collision with particular type
	bool ChecksCollisionWithParticularType(GameObject & object, sf::Vector2f point, int type);//Checks collision with point particular type
	bool ChecksCollisionWithWallAndClimbingWall(GameObject & object, sf::Vector2f point, int sort);//Checks collision with ClimbingWall
	float getPosOfObjectDownLemming(GameObject & object, sf::Vector2f point);

	//restart
	void restartLevel();
	//pause
	void pause() { m_pause = !m_pause; };
	
	// get/set
	std::vector<std::shared_ptr<GameObject>> & getObjectsByKey(const int key_val) { return m_objects[key_val]; };
	void setTool(int tool) { m_tool = tool; };
	int getTool() const { return m_tool; };
	void setSpeed(int speed) { m_lemming_speed = speed; };
	

private:
	//initialization
	void setGameObject(sf::Vector2f pos, sf::Vector2f size, char c);//set obgects from ascii to memory (vector)
	void setBoard();//Organized board
	void setInfo();//Organized Info

private:
	//members...
	std::vector<std::string> m_matrix_board;//olde the ascii board details
	std::string m_lemmings_data, m_menu_data;//olde the basic data abuot the objects
	
	std::unique_ptr<Menu> m_menu;
	InfoBar m_info;
	std::map<const int, std::vector<std::shared_ptr<GameObject>>> m_objects;//olde the data
	
	sf::Sprite m_background_board;
	sf::Texture T;

	int m_num_of_lemmings, m_min_num_pass_lemmings;
	int m_tool = -1, m_lemming_speed;
	bool m_pause;
	int * m_p2score = nullptr;
};

