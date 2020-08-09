#pragma once
#include "Constants.h"

class InfoBar
{
public:
	InfoBar();
	~InfoBar();

	//draw
	void draw(sf::RenderWindow & window);

	//set data
	void setBasicData(int stage, int min);
	void resetNumOfLemmings() { m_num_of_lemmings = 0; };
	void setNumOfLemmings() { m_num_of_lemmings++; };
	void setPassLemmings(int pass);
	void setDeadLemmings(int dead) { m_num_of_dead_lemmings = dead; };
	void setScore(int score) { m_score = score; };

private:
	//sts Shape
	void stsShape(sf::RectangleShape & shape, int num, sf::Color color);
	//draw one Textbox
	void drawTextbox(sf::RectangleShape & shape, std::string title, int num, sf::Color color, sf::RenderWindow & window);

private:
	//font
	sf::Font m_font;
	//Rectangle Shape textbox
	sf::RectangleShape m_stage_textbox, m_num_lemmings_textbox,
		m_pass_lemmings_textbox, m_dead_lemmings_textbox, m_score_textbox;
	//info data
	int m_stage, m_num_of_lemmings, m_min_num_pass_lemmings, 
		m_num_of_pass_lemmings, m_num_of_dead_lemmings, m_score;

};

