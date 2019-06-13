#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "declaration.h"

class IObject
{



public:
	sf::Texture texture;
	sf::Sprite sprite;
	obj_type o_type;
	//sf::Text txt;
	//std::vector<std::string> arr_str;
	std::vector<sf::Text> arr_txt;

	IObject();
	virtual ~IObject();

	//virtual void draw_object() = 0;
};

