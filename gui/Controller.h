#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Widget.H>

#include "../src/io.h"

class Controller
{
    public:
        Controller();

        int start();

};

#endif // CONTROLLER_H
