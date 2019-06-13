#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "declaration.h"
#include "IObject.h"

class Button : public IObject{

	//Pozycja lewego gornego rogu 
	UINT poz_x;
	UINT poz_y;
	button_function fun;
	
	
	
public:
	
	Button(int x, int y, button_function f);
	
	bool action_on_trigger();
	
};