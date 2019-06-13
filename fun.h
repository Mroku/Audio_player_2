#pragma once


bool draw_by_array(sf::RenderWindow* p_window, IObject* p_bck, std::vector<IObject*> arr, std::vector<std::string>& str_vec1, std::string current_song) {

	
	p_window->draw(p_bck->sprite);
	


	for (std::vector<IObject*>::size_type i = 0; i != arr.size(); i++) {
		

		switch (arr[i]->o_type) {

		case eButton:

			p_window->draw(arr[i]->sprite);

			break;
		case eSlider:

			p_window->draw(arr[i]->sprite);

			break;
		case eSlider_pointer:

			p_window->draw(arr[i]->sprite);

			break;
		case eTextBox:

			

			switch (dynamic_cast<TextBox*>(arr.back())->type)
			{
			case current:
				
				p_window->draw(arr[i]->sprite);
				dynamic_cast<TextBox*>(arr.back())->load_text(str_vec1, current_song);
				p_window->draw(*arr[i]->arr_txt.begin());
				

			case playlist:
				//p_window->draw(arr[i]->sprite);
				/*
				for (auto j = arr[i]->arr_txt.begin(); j != arr[i]->arr_txt.end(); ++j) {

					p_window->draw(*j);

				}*/
				p_window->draw(arr[i]->sprite);
				for (auto j = arr[i]->arr_txt.begin(); j != arr[i]->arr_txt.end(); ++j)
				{
					p_window->draw(*j);
				}
				
			default:
				break;
			}

			/*
			p_window->draw(arr[i]->sprite);
			dynamic_cast<TextBox*>(arr.back())->load_text(str_vec1, current_song);

			
			


			for (auto j = arr[i]->arr_txt.begin(); j != arr[i]->arr_txt.end(); ++j) {
				
				p_window->draw(*j);
				
			}
			

			*/
			break;
		default:
			break;
		}
		
	}
	
	return true;
}



bool eventcontrol(sf::RenderWindow* p_window, Song* song, std::string* current_song, std::vector<std::string> vec_playlist) {

	sf::Event windowEvent;
	while (p_window->pollEvent(windowEvent)) {

		if (windowEvent.type == sf::Event::Closed || windowEvent.type == sf::Event::KeyPressed && windowEvent.key.code == sf::Keyboard::Escape) {
			p_window->close();
		}

		if (windowEvent.type == sf::Event::KeyPressed && windowEvent.key.code == sf::Keyboard::P) {
			song->play_song();
		}

		if (windowEvent.type == sf::Event::KeyPressed && windowEvent.key.code == sf::Keyboard::O) {
			song->pause_song();
		}

		if (windowEvent.type == sf::Event::KeyPressed && windowEvent.key.code == sf::Keyboard::N) {
			
			static int finder = 0;

			song->stop_song();

			while (vec_playlist[finder] == *current_song)
			{
				finder++;
				if (finder >= vec_playlist.size())
				{	
					finder = 0;
				}
			}

			song->load_song(vec_playlist[finder]);
			song->play_song();
			*current_song = vec_playlist[finder];
		}

		if (windowEvent.type == sf::Event::KeyPressed && windowEvent.key.code == sf::Keyboard::B) {
			static int finder = vec_playlist.size()-1;

			song->stop_song();

			while (vec_playlist[finder] == *current_song)
			{
				finder--;
				if (finder < 0)
				{
					finder = vec_playlist.size() - 1;
				}
			}

			song->load_song(vec_playlist[finder]);
			song->play_song();
			*current_song = vec_playlist[finder];
		}
	}
	return 1;
}

bool get_file_name(std::vector<std::string>& str) 
{
	struct _finddata_t ff;
	long hFile;
	std::string dir = "C:\\Users\\Kacper\\source\\repos\\SFMLGame\\SFMLGame\\PlayList";
	std::string path;
	std::string findname;

	path = dir;
	path += "\\*.*";
	hFile = _findfirst(path.c_str(), &ff);
	if (hFile != -1L)
	{
		do
		{
			if (ff.attrib != _A_SUBDIR)
			{
				findname = ff.name;
				std::cout << findname << std::endl;
				str.push_back(findname);
			}
		} while (_findnext(hFile, &ff) == 0);
		_findclose(hFile);
	}
	return 1;
}