#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

typedef const unsigned int CUI;
typedef unsigned int UINT;
CUI resolution_x = 200;
CUI resolution_y = 400;
CUI center_x = resolution_x / 2;
CUI center_y = resolution_y / 2;

enum obj_type {eButton = 0, eSlider = 1, eSlider_pointer = 2, eTextBox = 3};
enum button_size { small = 0, medium = 1, large = 2 };
enum button_function { play_stop = 0, next_song = 1, prev_song = 2, mute = 3, rnd = 4 };
enum slider_type {horizontal =0, vertical = 1};
enum slider_function {song_progress = 0, volume = 1};
enum text_box_type {current = 0, playlist = 1};