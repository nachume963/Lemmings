#pragma once

#include "DynamicObject.h"
#include "GameMusic.h"

class Lemming : public DynamicObject
{
public:
	Lemming(const sf::Vector2f pos, const sf::Vector2f size, int * p2speed);
	~Lemming();

	virtual void move(const float deltaTime, GameBoard & board) override;//move lemming according to delta time
	virtual void draw(sf::RenderWindow & window);

	sf::Vector2f getCordinate(const int cordinate);//get specific cordinate on global bounds
	void changeStep();//change from left to right and from right to left
	
	virtual int get_tool(int index)const override { return m_tools[index]; };//return if u eve some tool (by index)
	virtual bool checkDead() override { return m_dead; };//check if Dead
	int & getSetStates(const int state) { return m_tools[state]; };//get memory of stste by refernc to get and set state
	int getState() const { return m_state; };
	int getDirection() const { return m_direction; };//get lemmungs direction
	void setDead() { m_dead = true; };//set lemming to be ded
	virtual void set_tool(const int tool) override { m_tools[tool] = 1; };//set tool by index
	
	virtual bool collide(GameObject & other, GameBoard & board)override;
	virtual bool collide(Lemming & other, GameBoard & board)override;
	
private://function
	void lemmingFall(const float deltaTime, GameBoard & board);
	void lemmingWalk(const float delta, GameBoard & board);
	bool lemmingStop(const float delta, GameBoard & board);
	void lemmingClimb(const float delta, GameBoard & board);
	void lemmingDig(const float deltaTime, GameBoard & board);

	void chekEndEndlIfReturnFromFall();
	void chekEndEndlIfNeedBildStairs(GameBoard & board);
	void doMovement(const int state, const float deltaTime);//move lemming on board acording to state end deltatime

private://members
	std::vector < int > m_tools;
	sf::Vector2f m_movement;
	std::pair< sf::Vector2f, bool > m_distance_falling;//pair to endel falling
	int m_direction, m_state;
	sf::Vector2f m_size, //size of lemming
		m_size_bild;//size to bild stairs
	bool m_dead;
	int * m_p2speed;
};

