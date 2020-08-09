#include "Lemming.h"
#include "GameBoard.h"


Lemming::Lemming(const sf::Vector2f pos, const sf::Vector2f size, int * p2speed)
	:DynamicObject(pos, size, "Files//lemmingsNew.png"), m_distance_falling({ 0.0f, 0.0f }, false)
	, m_direction(right), m_state(-1), m_movement({ 0.0f, 0.0f }), m_size_bild(size), m_dead(false), m_p2speed(p2speed)
{
	if (!m_anim_tool.loadFromXML("Files//tool_climb_dig_parachute.xml", *m_object.getTexture(), { 2.5f, 3.f }))//loadFromXML
		std::cerr << "cannot open file animation xml";
	m_anim_tool.set("parachute");//defolt animtion

	if (!m_anim_move.loadFromXML("Files//moov_go_fall_stop_med.xml", *m_object.getTexture(), { 3.5f, 3.f }))//loadFromXML
		std::cerr << "cannot open file animation xml";
	m_anim_move.set("walk_r");//defolt animtion
	
	m_object.scale(0.95f, 0.95f);//for the leming be smoler then all objects
	
	m_size = sf::Vector2f(m_object.getGlobalBounds().width, m_object.getGlobalBounds().height);
	
	m_active = false;
	m_tools = { 1, 0, 0, 0 ,0 ,0 ,0, 0 };
}
Lemming::~Lemming()
{
}

void Lemming::move(const float deltaTime, GameBoard & board)
{
	board.ChecksCollisionWithParticularType(*this, exitGate);//if lemming has come to exit
	switch (m_state)//check the lemming state
	{
	case climb:
		lemmingClimb(deltaTime, board);
		return;
	case dig:
		lemmingDig(deltaTime, board);
		return;
	default://defolt state
		lemmingWalk(deltaTime, board);
		break;
	}
}
void Lemming::draw(sf::RenderWindow & window)
{
	if (m_active)//if lemming active
		if (m_state == parachute || m_state == climb || m_state == dig)//chek witch animtion tool or move
		{
			if (m_state == dig) 
				m_anim_tool.tick(10);
			else
				m_anim_tool.tick(5);
			m_anim_tool.draw(window, sf::Vector2f(m_object.getPosition().x, m_object.getPosition().y + m_size.y));
		}
		else
		{
			m_anim_move.tick(5);
			m_anim_move.draw(window, sf::Vector2f(m_object.getPosition().x, m_object.getPosition().y + m_size.y));
		}
}

sf::Vector2f Lemming::getCordinate(const int cordinate)
{
	switch (cordinate)//get spesific cordinate on lemming global bounds
	{
	case up_l:
		return this->m_object.getPosition();
		break;
	case up_r:
		return  sf::Vector2f(this->m_object.getPosition().x + m_size.x, (this->m_object.getPosition().y));
		break;
	case down_l:
		return  sf::Vector2f((this->m_object.getPosition().x), (this->m_object.getPosition().y + m_size.y));
		break;
	case down_r:
		return  sf::Vector2f((this->m_object.getPosition().x + m_size.x), (this->m_object.getPosition().y + m_size.y));
		break;
	case senter_l:
		return  sf::Vector2f((this->m_object.getPosition().x), (this->m_object.getPosition().y + (m_size.y / 2)));
		break;
	case senter_r:
		return  sf::Vector2f((this->m_object.getPosition().x + (m_size.x)), (this->m_object.getPosition().y + (m_size.y / 2)));
		break;
	case senter_down:
		return  sf::Vector2f((this->m_object.getPosition().x + (m_size.x / 2)), (this->m_object.getPosition().y + (m_size.y)));
		break;
	case senter_up:
		return  sf::Vector2f((this->m_object.getPosition().x + (m_size.x / 2)), (this->m_object.getPosition().y));
		break;
	default:
		std::cout << "ERROR" << __LINE__ << __FILE__ << std::endl;
		break;
	}

	return sf::Vector2f(0, 0);
}
void Lemming::changeStep()
{
	m_direction = !m_direction;//switch direction in enam
	if (m_direction == right)//setup grafics
		m_anim_move.set("walk_r");
	else
		m_anim_move.set("walk_l");
}

bool Lemming::collide(GameObject & other, GameBoard & board)
{
	return other.collide(*this, board);//polimorfizem
}
bool Lemming::collide(Lemming & other, GameBoard & board)
{
	if (getSetStates(med) && !getSetStates(stop) && !other.getSetStates(stop) && !other.getSetStates(med))//check if cen kiil teh lemming
	{
		other.setDead();
		other.getSetActive() = false;
		GameMusic::sounds[splat].play();//game music play
	}
	if (getSetStates(stop))//change Step if collid wuth stop
		other.changeStep();
	return false;
}

//private
void Lemming::lemmingFall(const float deltaTime, GameBoard & board)
{
	if (!m_distance_falling.second) {//if lemming begin fall
		GameMusic::sounds[yippie].play();//game music play
		m_distance_falling.second = true;//set bool fall to true
		m_distance_falling.first = m_object.getPosition();//records the postion wen he began to fall
		m_anim_move.set("fall");//set animtion
		if (m_tools[parachute])//check if he eve a parachute
		{
			m_state = parachute;//change state to parachute
			m_anim_tool.set("parachute");//set animtion
		}
	}
	
	if (m_tools[parachute])//check if he eve a parachute
	{
		m_anim_tool.set("parachute");//set animtion
		m_state = parachute;//change state to parachute
	}
	
	doMovement(fall, deltaTime);//move the object logic
	m_object.move(m_movement);//move

}
void Lemming::lemmingWalk(const float deltaTime, GameBoard & board)
{
	sf::Vector2f check_point_go = (m_direction == right ? getCordinate(down_l) : getCordinate(down_r));//check if begin to fall
	sf::Vector2f check_point_direction = (m_direction == right ? getCordinate(senter_r) : getCordinate(senter_l));//check if need to change dirction

	if (board.ChecksCollisionWithParticularType(*this, check_point_go, wall))//ceck if lemming go on wall objects
	{
		chekEndEndlIfReturnFromFall();//ceck if lemming need to fall
		if (getSetActive() == false)//if lemming dead return from go
			return;
		board.ChecksCollisionWithParticularType(*this, check_point_direction, lemming);//double dispathc with other lemmings

		if (board.ChecksCollisionWithWallAndClimbingWall(*this, check_point_direction, m_direction))//double dispathc with walls or stairs
		{
			if (m_tools[climb] || m_state == climb)//ceck if lemming might climb
			{
				lemmingClimb(deltaTime, board);
				return;
			}
			changeStep();//if not climb change step
		}
		if (!lemmingStop(deltaTime, board))//if lemming not stop
		{
			if (m_tools[dig] || m_state == dig)//check if lemming might dig
			{
				lemmingDig(deltaTime, board);
				return;
			}
			chekEndEndlIfNeedBildStairs(board);//endel bild stairs
			doMovement(walk, deltaTime);//move the object logic
			m_object.move(m_movement);//move
		}
		return;
	}
	
	lemmingFall(deltaTime, board);//if not wallk fall
}
bool Lemming::lemmingStop(const float deltaTime, GameBoard & board)
{
	if (m_tools[stop] && m_state != stop)//chck if first time
	{
		m_anim_move.set("stop");//set animtion stop
		m_state = stop;
		m_dead = true;
		return true;
	}

	if (m_tools[stop])//if not the first time do Movement stop
	{
		doMovement(stop, deltaTime);
		return true;
	}

	return false;
}
void Lemming::lemmingClimb(const float deltaTime, GameBoard & board)
{
	sf::Vector2f check_point_go = (m_direction == right ? getCordinate(down_r) : getCordinate(down_l));//check point if collid the roof
	sf::Vector2f check_point_climb = sf::Vector2f(getCordinate(senter_up).x, getCordinate(senter_up).y);//check point if end to climb

	if (m_tools[climb] && m_state != climb)//chck if first time
	{
		if (m_direction == right)//check direction
			m_anim_tool.set("climb_r");//set animtion
		else
			m_anim_tool.set("climb_l");//set animtion
		m_state = climb;
		m_tools[climb] = !m_tools[climb];//torn of tool
		return;
	}

	if (board.ChecksCollisionWithWallAndClimbingWall(*this, check_point_climb, right) && board.ChecksCollisionWithWallAndClimbingWall(*this, check_point_climb, left))//if collid the roof but not stairs 
	{
		m_state = -1;//end state climb
		m_tools[climb] = !m_tools[climb];//torn of tool
		changeStep();
	}

	if (!board.ChecksCollisionWithParticularType(*this, check_point_go, wall))
	{
		m_state = -1;//end state climb
		m_tools[climb] = !m_tools[climb];//torn of tool
		if (m_direction == right)//check direction
			m_movement = { 23.f, 0.5f };//get lemming on the floor
		else
			m_movement = { -23.f, 0.5f };
		m_object.move(m_movement);
	}

	if (m_state == climb)//normal moode climb
	{
		doMovement(climb, deltaTime);
		m_object.move(m_movement);
		return;
	}

	return;
}
void Lemming::lemmingDig(const float deltaTime, GameBoard & board)
{
	sf::Vector2f check_point_dig = getCordinate(senter_down);//check_point if end the diging

	if (m_tools[dig] && m_state != dig)//check if first time
	{
		if (m_direction == right)//check direction
			m_anim_tool.set("dig_r");//set animtion
		else
			m_anim_tool.set("dig_l");//set animtion
		m_tools[dig] = !m_tools[dig];//torn of tool
		m_state = dig;
		return;
	}

	if (m_state == dig)//normal moode dig
	{
		if (!board.ChecksCollisionWithParticularType(*this, check_point_dig, wall))//to end diging
			m_state = -1;
		doMovement(dig, deltaTime);
		return;
	}

	return;
}

void Lemming::chekEndEndlIfReturnFromFall()
{
	if (m_distance_falling.second)//chek (bool) if return from a fall
	{
		if (!m_tools[parachute] && abs(m_distance_falling.first.y - m_object.getPosition().y) >= m_size.y * 3.3)//if fall mor then ObjectSize * 3
		{
			m_dead = true;
			GameMusic::sounds[splat].play();//game music play
			getSetActive() = false;
			return;
		}

		if (m_tools[parachute])//check if eve parachute
		{
			m_tools[parachute] = !m_tools[parachute];//torn of tool
			m_state = -1;//torn of state
		}

		m_distance_falling.second = false;//end falling
		if (m_direction == right)
			m_anim_move.set("walk_r");
		else
			m_anim_move.set("walk_l");
	}
}
void Lemming::chekEndEndlIfNeedBildStairs(GameBoard & board)
{
	if (m_tools[climbing_Wall])//if need to bild stairs
	{
		if (m_direction == right && (board.ChecksCollisionWithParticularType(*this, getCordinate(down_r), wall)))//if need to bild right
			board.getObjectsByKey(wall).push_back(std::make_shared<ClimbingWall>(sf::Vector2f(getCordinate(up_r).x, board.getPosOfObjectDownLemming(*this, getCordinate(down_l))), m_size_bild, "Files//Climbing Wall R.png", right));//bild
		else
		{
			if (m_direction == left && board.ChecksCollisionWithParticularType(*this, getCordinate(down_l), wall))// if need to bild left
			{
				auto climnig_Wall = std::make_shared<ClimbingWall>(getCordinate(up_l), m_size_bild, "Files//Climbing Wall L.png", left);
				climnig_Wall->setPos(sf::Vector2f((getCordinate(up_l).x - climnig_Wall->getGlobalBounds().width), board.getPosOfObjectDownLemming(*this, getCordinate(down_l))));
				board.getObjectsByKey(wall).push_back(climnig_Wall);
			}
		}
		m_tools[climbing_Wall] = !m_tools[climbing_Wall];//torn of tool
		return;
	}
}
void Lemming::doMovement(const int state, const float deltaTime)
{
	m_movement = sf::Vector2f(0.0f, 0.0f);

	switch (state)
	{
	case walk:
		switch (m_direction)
		{
		case left:
			m_movement.x -= *m_p2speed * deltaTime;
			break;
		case right:
			m_movement.x += *m_p2speed * deltaTime;
			break;
		}
		break;
	case fall:
		m_movement.y += *m_p2speed * deltaTime;
		break;
	case climb:
		m_movement.y -= *m_p2speed * deltaTime;
		break;
	default:
		break;
	}
}





