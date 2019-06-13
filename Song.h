#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "declaration.h"

class Song
{
public:
	sf::Music music;

	Song();

	bool load_song(std::string str);
	bool play_song();
	bool pause_song();
	bool stop_song();



	virtual ~Song();
};

