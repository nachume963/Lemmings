#include "GameMusic.h"

//inishlaizd statics
sf::SoundBuffer GameMusic::buffers[6];
sf::Sound GameMusic::sounds[6];

GameMusic::GameMusic()
{
	//put in music into memory
	buffers[0].loadFromFile("sounds//GameMusic.ogg");
	sounds[0].setBuffer(buffers[0]);
	sounds[0].setVolume(100);
	buffers[1].loadFromFile("sounds//win.ogg");
	sounds[1].setBuffer(buffers[1]);
	sounds[1].setVolume(100);
	buffers[2].loadFromFile("sounds//youlos.ogg");
	sounds[2].setBuffer(buffers[2]);
	sounds[2].setVolume(50);
	buffers[3].loadFromFile("sounds//splat.ogg");
	sounds[3].setBuffer(buffers[3]);
	sounds[3].setVolume(100);
	buffers[4].loadFromFile("sounds//yippie.ogg");
	sounds[4].setBuffer(buffers[4]);
	sounds[4].setVolume(100);
}


GameMusic::~GameMusic()
{
}

