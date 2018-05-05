#include "Gameroom.h"
#include "../src/dealer.h"

static Gameroom* PTR;
dealer D;

using namespace std;
Fl_Window* game_window;

Gameroom gm;

//----------------------------------------------------

void Gameroom::add_player(const char* player)
{
	user[0]->value(player);
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
	gm.user[7] = new Fl_Output(470, 50, 140, 30, "Dealer:");
	gm.user[7]->value("Group15");
	gm.hand[7] = new Fl_Output(470, 100, 140, 30, "Hand:");

	// Create Player Slots
	int leftspace = 0;
	for(int i = 0; i < 7; i++)
	{
		gm.action[i] = new Fl_Output(50+leftspace, h-250, 100, 30, "Action:");
		gm.user[i] = new Fl_Output(50+leftspace, h-210, 100, 30, "Player:");
		gm.hand[i] = new Fl_Output(50+leftspace, h-170, 100, 30, "Hand:"); 
		gm.count[i] = new Fl_Output(75+leftspace, h-130, 50, 30, ""); 
		leftspace += 150;
	}

	start = new Fl_Light_Button(w-280,70,70,30,"Start");
	start->selection_color(FL_GREEN);
	start->callback((Fl_Callback *)cb_start, 0);

	quit_game = new Fl_Button(w-100, h-50, 70, 30, "Quit");
	quit_game->callback((Fl_Callback *)cb_quit_game, 0);

	gm.user[0]->value("##TEST VAL FROM GAMEROOM.CPP; FIGURE OUT HOW TO INCREMENT SLOT BY 1 INSTEAD OF 2##");
    // game_window->end();
    game_window->show();
    // add_player(0,"TEST");
}

//----------------------------------------------------

Gameroom::Gameroom(){}

Gameroom::~Gameroom(){}

//----------------------------------------------------
