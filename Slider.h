#pragma once
#include "IObject.h"
class Slider : public IObject{
private:
	UINT poz_x;
	UINT poz_y;
	slider_function fun;
	slider_type type;
	
public:
	Slider(int x, int y, slider_function f, slider_type t);
	virtual ~Slider();
};

