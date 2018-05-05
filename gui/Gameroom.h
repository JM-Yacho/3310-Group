#ifndef GAMEROOM_H
#define GAMEROOM_H

#include <iostream>
#include <string>

#include <boost/thread.hpp>
#include <boost/uuid/uuid.hpp>            // uuid class
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Box.H>

#include "../src/io.h"

class Gameroom
{

	private:
		Fl_Output* action[8];
		Fl_Output* hand[8];
		Fl_Output* count[8];
		Fl_Light_Button* start;
		Fl_Button* quit_game;
		Fl_Text_Display* game_title;

	public:
		Fl_Output* user[8];
		Gameroom();
		~Gameroom();
		void add_player(int n, const char* player);
		void run_game_window(const char*);

};

#endif // GAMEROOM_H