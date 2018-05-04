#include "Controller.h"

using namespace std;

Gameroom show_game_window;

Fl_Window* main_win;
Fl_Button* add;
Fl_Button* test_room;
Fl_Button* inf_room;
Fl_Button* eight_deck_room;
Fl_Button* main_quit;

//----------------------------------------------------

Controller::Controller(){}

void cb_test(Fl_Widget* w, void* v) 
{
   show_game_window.run_game_window("Test Game");
}

void cb_inf(Fl_Widget* w, void* v) 
{
   show_game_window.run_game_window("Infinite Deck Game");
}

void cb_8deck(Fl_Widget* w, void* v) 
{
   show_game_window.run_game_window("8-Deck Game");
}

void cb_quit(Fl_Widget* w, void* v) 
{
   main_win->hide();
}

//----------------------------------------------------

void Controller::run_main_window()
{
	Controller C = Controller();
	fl_register_images();
	const int w = 380;
	const int h = 480;
	main_win = new Fl_Window(w,h,"UberCasino - Dealer");
	main_win->color(FL_DARK_CYAN);
	main_win->resizable(main_win);
// Test
	// Fl_Box* box = new Fl_Box(150,150,50,50);
	// img = new Fl_PNG_Image("./images/2D.png");
	// box->image(img);

	// add = new Fl_Button(w-130, h-220, 110, 30, "Test Game");
	// add->callback((Fl_Callback *)cb_add, 0);


	test_room = new Fl_Button(w-130, h-220, 110, 30, "Test Game");
	test_room->callback((Fl_Callback *)cb_test, 0);	

	inf_room = new Fl_Button(w-130, h-170, 110, 30, "Infinite Deck");
	inf_room->callback((Fl_Callback *)cb_inf, 0);	

	eight_deck_room = new Fl_Button(w-130, h-120, 110, 30, "8-Deck Game");
	eight_deck_room->callback((Fl_Callback *)cb_8deck, 0);


	main_quit = new Fl_Button(w-110, h-50, 70, 30, "Quit");
	main_quit->callback((Fl_Callback *)cb_quit, 0);	

    main_win->end();
    main_win->show();

    // return Fl::run();

}

//----------------------------------------------------

Controller::~Controller(){}

//----------------------------------------------------
