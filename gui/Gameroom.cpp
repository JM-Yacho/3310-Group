#include "Gameroom.h"

using namespace std;

Fl_Window* game_win;

//----------------------------------------------------

void cb_quit_game(Fl_Widget* w, void* v) 
{
   game_win->hide();
}

void cb_start(Fl_Widget* w, void* v)
{
	((Fl_Light_Button *)w)->deactivate();
}

//----------------------------------------------------

int Gameroom::run_game_win(const char* title)
{
	const int w = 1080;
	const int h = 480;
	game_win = new Fl_Window(w,h,"BlackJack");
	game_win->color(FL_DARK_CYAN);
	game_win->resizable(game_win);

	game_title = new Fl_Text_Display(540,30,0,0,title);

	// Dealer Slot
	user[8] = new Fl_Output(470, 50, 140, 30, "Dealer:");
	user[8]->value("Group15");
	hand[8] = new Fl_Output(470, 100, 140, 30, "Hand:");

	// Player Slots
	int leftspace = 0;
	for(int i = 0; i < 7; i++)
	{
		action[i] = new Fl_Output(50+leftspace, h-250, 100, 30, "Action:");
		user[i] = new Fl_Output(50+leftspace, h-210, 100, 30, "Player:");
		hand[i] = new Fl_Output(50+leftspace, h-170, 100, 30, "Hand:"); 
		count[i] = new Fl_Output(75+leftspace, h-130, 50, 30, ""); 
		leftspace += 150;
	}


	start = new Fl_Light_Button(w-280,70,70,30,"Start");
	start->selection_color(FL_GREEN);
	start->callback((Fl_Callback *)cb_start, 0);


	quit_game = new Fl_Button(w-100, h-50, 70, 30, "Quit");
	quit_game->callback((Fl_Callback *)cb_quit_game, 0);


    game_win->end();
    game_win->show();

    return Fl::run();
}