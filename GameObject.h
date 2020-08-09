#pragma once

#include "Constants.h"

//////////////////////////////////
class GameBoard;
class InfoBar;
/////////////////////////////////

class GameObject
{
public:
	GameObject() {};
	GameObject(sf::Vector2f pos, sf::Vector2f size, std::string name_file);
	virtual ~GameObject();

	//polimorfic draw
	virtual void draw(sf::RenderWindow & window);
	//polimorfic move
	virtual void move(const float delta, GameBoard & board) {};
	//polimorfic get / set tool
	virtual void set_tool(const int tool) {};
	virtual int get_tool(int index) const { return -1; };
	virtual bool checkDead() { return false; };
	virtual int getLemmingInside() const { return 0; };
	//polimorfic entranceLemming
	virtual void entranceLemmings(const float delta, GameBoard & bord, InfoBar  & info) {};
	//polimorfic climingWall
	virtual int getSide() const { return 3; };

	//Virtual functions that deal with conflicts between the various objects
	virtual bool collide(GameObject & other, GameBoard & board) = 0;
	virtual bool collide(ExitGate & other, GameBoard & board) = 0;
	virtual bool collide(EntranceGate & other, GameBoard & board) = 0;
	virtual bool collide(Wall & other, GameBoard & board) = 0;
	virtual bool collide(ClimbingWall & other, GameBoard & board) = 0;
	virtual bool collide(Lemming & other, GameBoard & board) = 0;
	virtual bool collide(Spikes & other, GameBoard & board) = 0;
	virtual bool collide(Border & other, GameBoard & board) = 0;

	bool & getSetActive();
	sf::FloatRect getGlobalBounds() const;
	sf::Vector2f getPos() const { return m_object.getPosition(); };
	void setPos(const sf::Vector2f pos) { m_object.setPosition(pos); };

protected:
	sf::Sprite m_object;
	sf::Texture T;
	bool m_active;//GameObject activity
};

