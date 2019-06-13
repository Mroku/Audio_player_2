#include "pch.h"
#include "Slider.h"


Slider::Slider(int x, int y, slider_function f, slider_type t) : poz_x(x), poz_y(y), fun(f), type(t){
	o_type = eSlider;
	double scale = 0.1;


	switch (t)
	{
	case horizontal:
		texture.loadFromFile("slider_h.png");
		sprite.setScale(scale*3, scale/3);
		break;
	case vertical:
		texture.loadFromFile("slider_v.png");
		sprite.setScale(scale/3, scale*3);
		break;
	default:
		break;
	}
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}


Slider::~Slider(){



}
