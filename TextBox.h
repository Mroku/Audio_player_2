#pragma once
#include "IObject.h"
class TextBox : public IObject{
private:
	UINT poz_x;
	UINT poz_y;
	sf::Font font;

public:
	//std::vector<std::string> arr_str;
	
	text_box_type type;
	TextBox(int x, int y, text_box_type t);
	virtual ~TextBox();

	//bool load_text(std::string s);
	bool load_text(std::vector<std::string> s, std::string current_song);
	bool print_text();

};

