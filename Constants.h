#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream> 
#include <cmath>
#include <exception>

#include "Animation.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#ifdef _DEBUG 
#pragma comment ( lib , "sfml-audio-d.lib" )
#pragma comment ( lib , "sfml-main-d.lib" ) 
#pragma comment ( lib , "sfml-system-d.lib" ) 
#pragma comment ( lib , "sfml-window-d.lib" ) 
#pragma comment ( lib , "sfml-graphics-d.lib" ) 
#elif defined (NDEBUG) 
#pragma comment ( lib , "sfml-audio.lib" )
#pragma comment ( lib , "sfml-main.lib" ) 
#pragma comment ( lib , "sfml-system.lib" ) 
#pragma comment ( lib , "sfml-window.lib" ) 
#pragma comment ( lib , "sfml-graphics.lib" ) 
#else 
#error "Unrecognized configuration!" 
#endif 

class Lemming;
class Rock;
class Wall;
class ExitGate;
class EntranceGate;
class ClimbingWall; 
class Border;
class Spikes;

//board
static const sf::Vector2f BOARD_SIZE(1100.f, 900.f);
static const sf::Vector2f POSITON_BOARD(0.f, 0.f);//posion on screen
static sf::FloatRect RECT_BOARD(POSITON_BOARD, BOARD_SIZE);


static sf::Vector2f OBJECT_SIZE(0.f, 0.f);

enum objects { lapid, climbingWallLeft, climbingWallRight, wall, exitGate, entranceGate, lemming, water };
enum cordinate { up_r, up_l, down_r, down_l, senter_r, senter_l, senter_up, senter_down };

//lemming
//const int LEMMING_SPEED = 100;
enum direction { right, left };
enum states { parachute, walk, fall, stop, dig, climb, climbing_Wall, med };

//Music
enum sound { gameMusic, win, youlos, splat, yippie };
//Controller
static const sf::Vector2f WINDOE_SIZE(1200.f , 1050.f);

//Menu
static const float BUTTENS_SIZE = 80;//The width of a button
static const int NUM_OF_BASIC_BUTTENS = 5;//Number of buttons
static const sf::Vector2f POSITON_MENU(sf::Vector2f(WINDOE_SIZE.x - (BUTTENS_SIZE + 10.f), 10.f));
static sf::FloatRect RECT_MENU(POSITON_MENU, sf::Vector2f(BUTTENS_SIZE, BOARD_SIZE.y));

static const sf::Vector2f SIZE_BUTTON (BUTTENS_SIZE, BUTTENS_SIZE );
static const sf::Vector2f SIZE_MENU(BUTTENS_SIZE, (BUTTENS_SIZE * NUM_OF_BASIC_BUTTENS));


//info bar
static const sf::Vector2f POSITON_INFO(sf::Vector2f(0.f, BOARD_SIZE.y));
static const sf::Vector2f SIZE_INFO(sf::Vector2f(WINDOE_SIZE.x, (WINDOE_SIZE.y - BOARD_SIZE.y)));
static sf::FloatRect RECT_INFO(POSITON_INFO, SIZE_INFO);
static const sf::Vector2f TEXTBOX_SIZE(sf::Vector2f(150.F, SIZE_INFO.y));