#include "pch.h"
#include "TextBox.h"


TextBox::TextBox(int x, int y, text_box_type t): poz_x(x), poz_y(y), type(t){

	o_type = eTextBox;

	double scale = 0.1;

	if (!font.loadFromFile("arial.ttf")){
		std::cout << "Font not found" << std::endl;
	}


	switch (type)
	{
	case current:
		texture.loadFromFile("current.png");
		sprite.setScale(scale * 3, scale / 3);
		break;
	case playlist:
		texture.loadFromFile("playlist.png");
		sprite.setScale(scale * 3, scale * 3);
		break;
	default:
		break;
	}

	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	
}


TextBox::~TextBox(){

}


/*bool TextBox::load_text(std::string s) {

	arr_str.push_back(s);

	txt.setFont(font);
	txt.setCharacterSize(60);
	txt.setStyle(sf::Text::Regular);
	txt.setPosition(this->poz_x, this->poz_y);
	txt.setFillColor(sf::Color::Black);
	txt.setString(s);

	//arr_str.push_back(txt);

	return true;
}*/

bool TextBox::load_text(std::vector<std::string> s, std::string current_song) {

	sf::Text txt;
	UINT X = poz_x;
	UINT Y = poz_y;
	txt.setFont(font);
	txt.setCharacterSize(11); 
	txt.setStyle(sf::Text::Regular);
	txt.setFillColor(sf::Color::Black);
	
	switch (type)
	{
		case current:

			txt.setString(current_song);
			txt.setPosition(X, Y);
			Y = Y + 10;
			arr_txt.push_back(txt);

			break;
		case playlist:

			for (auto i = s.begin(); i != s.end(); ++i) {

				txt.setString(*i);
				txt.setPosition(X, Y);
				Y = Y + 10;
				arr_txt.push_back(txt);

			}

			break;
	}
	/*
	for (auto i = s.begin(); i != s.end(); ++i) {
		
		txt.setString(*i);
		txt.setPosition(X, Y);
		Y = Y + 10;
		arr_txt.push_back(txt);
		
	}
	*/

	return true;
}

bool TextBox::print_text() {


	return false;
}