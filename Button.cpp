#include "pch.h"
#include "Button.h"

Button::Button(int x, int y, button_function f) : poz_x(x), poz_y(y), fun(f) {
	
	o_type = eButton;
	float scale = 0.1;

	switch (fun)
	{
	case play_stop:
		texture.loadFromFile("Button_play_stop.png");
		sprite.setScale(scale, scale);
		break;
	case next_song:
		texture.loadFromFile("Button_next_song.png");
		sprite.setScale(scale, scale);
		break;
	case prev_song:
		texture.loadFromFile("Button_prev_song.png");
		sprite.setScale(scale, scale);
		break;
	case mute:
		texture.loadFromFile("Button_mute.png");
		sprite.setScale(scale, scale);
		break;
	case rnd:
		texture.loadFromFile("Button_rnd.png");
		sprite.setScale(scale, scale);
		break;
	default:
		break;
	}

	sprite.setTexture(texture);
	sprite.setPosition(x, y);


}

/*
bool Button::action_on_trigger(){	

	switch (fun)
	{
	case play_stop:
		break;
	case next_song:
		break;
	case prev_song:
		break;
	case mute:
		break;
	case rnd:
		break;
	default:
		break;
	}
	
	return false;
}
*/

