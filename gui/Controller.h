#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Box.H>

// #include "../src/io.h"
// #include "../src/callback.h"
// #include "../src/dealer.h"
// #include "../src/player.h"

#include "Gameroom.h"

class Controller
{
    public:
        Controller();
        ~Controller();
        void run_main_window();
        // void cb_quit(Fl_Widget*, void*);
		// Fl_PNG_Image* img;
};

#endif // CONTROLLER_H
