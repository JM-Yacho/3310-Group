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

#include "../src/io.h"

#include "Gameroom.h"

class Controller
{
    public:
        Controller();

        int run_main_window();

};

#endif // CONTROLLER_H
