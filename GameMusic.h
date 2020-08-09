#pragma once
#include "GameBoard.h"

class GameMusic
{
public:
	GameMusic();
	~GameMusic();

	static sf::SoundBuffer buffers[6];//old the music
	static sf::Sound sounds[6];//can play the music
private:
	
};

