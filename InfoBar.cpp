#include "InfoBar.h"



InfoBar::InfoBar()
{
	//set all textbox
	m_font.loadFromFile("Files//aaa.ttf");

	stsShape(m_stage_textbox, 0, sf::Color::Yellow);
	stsShape(m_num_lemmings_textbox, 2, sf::Color::Cyan);
	stsShape(m_pass_lemmings_textbox, 3, sf::Color::Green);
	stsShape(m_dead_lemmings_textbox, 4, sf::Color::Red);
	stsShape(m_score_textbox, 6, sf::Color::Magenta);
}
InfoBar::~InfoBar()
{
}

void InfoBar::draw(sf::RenderWindow & window)
{
	//draw all textbox
	drawTextbox(m_stage_textbox, "stage", m_stage, sf::Color::Black, window);
	drawTextbox(m_num_lemmings_textbox, "lemmings", m_num_of_lemmings, sf::Color::Black, window);
	drawTextbox(m_pass_lemmings_textbox, "pass", m_num_of_pass_lemmings, sf::Color::Blue, window);
	drawTextbox(m_dead_lemmings_textbox, "dead", m_num_of_dead_lemmings, sf::Color::White, window);
	drawTextbox(m_score_textbox, "score", m_score, sf::Color::Black, window);
}

void InfoBar::setBasicData(int stage, int min)
{
	//set the base data
	m_stage = stage;
	m_num_of_lemmings = 0;
	m_min_num_pass_lemmings = min;
}

void InfoBar::setPassLemmings(int pass)
{
	//set how much lemmings pass the exit gate
	m_num_of_pass_lemmings = pass;

	if (m_num_of_pass_lemmings == m_min_num_pass_lemmings)
		m_pass_lemmings_textbox.setFillColor(sf::Color::Magenta);
}

void InfoBar::stsShape(sf::RectangleShape & shape, int num, sf::Color color)
{
	//init the textbox
	shape.setSize(TEXTBOX_SIZE);
	shape.setPosition(sf::Vector2f(POSITON_INFO.x + (num * TEXTBOX_SIZE.x), POSITON_INFO.y));
	shape.setFillColor(color);
}
void InfoBar::drawTextbox(sf::RectangleShape & shape, std::string title, int num, sf::Color color, sf::RenderWindow & window)
{
	//set and draw the textbox
	sf::Text Line(title + '\n' + std::to_string(num), m_font, 25);
	Line.setPosition(sf::Vector2f(shape.getPosition().x + 10.f, shape.getPosition().y + 2));
	Line.setFillColor(color);
	window.draw(shape);
	window.draw(Line);
}
