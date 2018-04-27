#include "Controller.h"

using namespace std;

Fl_Window* win;

Fl_Output* action[9];
Fl_Output* user[9];
Fl_Output* hand[9];
Fl_Output* count[9];
Fl_Button* quit;

//----------------------------------------------------

void cb_quit(Fl_Widget* w, void* v) {

   win->hide();
}

//----------------------------------------------------

Controller::Controller(){}

int Controller::start()
{
	const int w = 1080;
	const int h = 480;
	win = new Fl_Window(w,h,"BlackJack");
	win->color(FL_DARK_CYAN);
	win->resizable(win);

	// Dealer Slot
	user[8] = new Fl_Output(470, 50, 140, 30, "Dealer:");
	user[8]->value("Group15");
	hand[8] = new Fl_Output(470, 100, 140, 30, "Hand:");

	// Player Slots
	int leftspace = 0;
	for(int i = 0; i < 7; i++)
	{
		// bet[i] = new Fl_Output(50+leftspace, 280, 100, 30, "Bet $:"); 
		// inc[i] = new Fl_Output(50+leftspace, 320, 100, 30, "$:"); 
		action[i] = new Fl_Output(50+leftspace, h-250, 100, 30, "Action:");
		user[i] = new Fl_Output(50+leftspace, h-210, 100, 30, "Player:");
		hand[i] = new Fl_Output(50+leftspace, h-170, 100, 30, "Hand:"); 
		count[i] = new Fl_Output(75+leftspace, h-130, 50, 30, ""); 
		leftspace += 150;
	}
	quit = new Fl_Button(w-100, h-50, 70, 30, "Quit");
	quit->callback((Fl_Callback *)cb_quit, 0);	
    win->end();
    win->show();

    return Fl::run();
}

//----------------------------------------------------
