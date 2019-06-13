#include "pch.h"
#include "Background.h"


Background::Background(){
	texture.loadFromFile("Back.jpg");
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
}


Background::~Background(){
}
