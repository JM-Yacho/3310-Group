#include "Gameroom.h"
#include "../src/dealer.h"

static Gameroom* PTR;
dealer D;

using namespace std;
Fl_Window* game_window;

//----------------------------------------------------

void Gameroom::add_player(int slot,const char* player)
{
	user[0]->value("TEST");
	// cannot access memory at address
}

void cb_start(Fl_Widget* w, void* v)
{
	D.user_input("start");
	((Fl_Light_Button *)w)->deactivate();
}

void cb_quit_game(Fl_Widget* w, void* v) 
{
	// try to implement a way to reset dealer back to a 'wait' state for new game when quitting
   game_window->end();
   game_window->hide();
}


//----------------------------------------------------

void  Gameroom::run_game_window(const char* title)
{
	Gameroom G = Gameroom();
	PTR = &G;
	// Create the game window
	const int w = 1080;
	const int h = 480;
	game_window = new Fl_Window(w,h,"BlackJack");
	game_window->color(FL_DARK_CYAN);
	game_window->resizable(game_window);

	game_title = new Fl_Text_Display(540,30,0,0,title);


	// Create Dealer Slot
	user[7] = new Fl_Output(470, 50, 140, 30, "Dealer:");
	user[7]->value("Group15");
	hand[7] = new Fl_Output(470, 100, 140, 30, "Hand:");

	// Create Player Slots
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

    // game_window->end();
    game_window->show();
    // add_player(0,"TEST");
       cout << "GAMEROOM.cpp " << user[0]->value() << endl;
}

//----------------------------------------------------

Gameroom::Gameroom(){}

Gameroom::~Gameroom(){}

//----------------------------------------------------
