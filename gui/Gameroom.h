#ifndef GAMEROOM_H
#define GAMEROOM_H

#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Text_Display.H>

using namespace std;

class Gameroom
{
	public:
		// Fl_Window* game_win;
		Fl_Output* action[9];
		Fl_Output* user[9];
		Fl_Output* hand[9];
		Fl_Output* count[9];
		Fl_Light_Button* start;
		Fl_Button* quit_game;
		Fl_Text_Display* game_title;
		int run_game_win(const char* title);
};

#endif // GAMEROOM_H