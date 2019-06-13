#include "pch.h"
#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "declaration.h"
#include "Button.h"
#include "Background.h"
#include "Slider.h"
#include "Slider_pointer.h"
#include "TextBox.h"
#include "vector"
#include "string"
#include "Song.h"
#include <direct.h>
#include <io.h>
#include "fun.h"



int main()
{
	sf::RenderWindow window{ {resolution_x, resolution_y, 32}, "Music Player" };
	sf::Color kolor = sf::Color::Black;
	
	std::vector<std::string> vec_playlist;
	std::string current_song;

	get_file_name(vec_playlist);

	std::vector<IObject*> arr;
	arr.push_back(new Button(center_x-25, center_y-50, play_stop));
	arr.push_back(new Button(center_x+30, center_y-45, next_song));
	arr.push_back(new Button(center_x-80, center_y-45, prev_song));

	arr.push_back(new Slider(center_x-75, center_y-75, song_progress, horizontal));
	arr.push_back(new Slider(center_x+80, center_y+25, volume, vertical));

	
	std::vector<std::string> str_vec1;

	auto getting_names = [&](std::string x) { str_vec1.push_back(x); };

	std::for_each(vec_playlist.begin(), vec_playlist.end(), getting_names);

	current_song = vec_playlist[0];
	
	arr.push_back(new TextBox(center_x-85, center_y+25, playlist));
	dynamic_cast<TextBox*>(arr.back())->load_text(str_vec1, current_song);

	arr.push_back(new TextBox(center_x - 75, center_y - 100, current));
	dynamic_cast<TextBox*>(arr.back())->load_text(str_vec1, current_song);

	IObject* p_bck = new Background;
	
	Song song_1;

	song_1.load_song(vec_playlist[0]);
	//current_song = vec_playlist[0];

	song_1.play_song();



	while (window.isOpen()) {



		

		window.clear(kolor);

		eventcontrol(&window, &song_1, &current_song, vec_playlist);

		draw_by_array(&window, p_bck, arr, str_vec1, current_song);

		


		window.display();

	}


}
