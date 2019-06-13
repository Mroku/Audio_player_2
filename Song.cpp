#include "pch.h"
#include "Song.h"


Song::Song()
{

}


Song::~Song()
{

}

bool Song::load_song(std::string str)
{
	if (!this->music.openFromFile("PlayList//" + str))
	{
		std::cout << "Ther is no file like: " << str << std::endl;
		return 0;
	}
	std::cout << "Loaded file: " << str << std::endl;
	return 1;
}

bool Song::play_song()
{

	this->music.play();

	return 0;
}

bool Song::pause_song() 
{
	this->music.pause();

	return 0;
}

bool Song::stop_song()
{
	this->music.stop();
	return 0;
}