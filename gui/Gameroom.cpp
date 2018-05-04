#include "Gameroom.h"
#include <functional>

static Gameroom* PTR;

#include "../src/callback.h"

using namespace std;
Fl_Window* game_window;


#define TIMER(SECS) \
    if ( m_timer_thread )\
    {\
       m_timer_thread->interrupt ();\
       delete ( m_timer_thread );\
       m_timer_thread = NULL;\
    }\
    m_timer_thread = new boost::thread ( delay_thread , SECS , std::bind ( &Gameroom::timer_expired , this ) );\


int slot = 0;


//----------------------------------------------------
void delay_thread ( int seconds, std::function <void(void)> callback)
{
  // this routine is created as a posix thread.
  boost::this_thread::sleep_for(boost::chrono::seconds(seconds));
  callback ();
}


void lock ()
{
  cout << "****************************************" << endl;
  // pthread mutex works well
  // suggest you put it in if needed
}

void unlock ()
{
  // see remarks under lock(), above
}

void Gameroom::cb_add_player(int slot_num, const char* player)
{
	user[slot_num]->value(player);
}

void cb_quit_game(Fl_Widget* w, void* v) 
{
   game_window->hide();
}

void cb_start(Fl_Widget* w, void* v)
{
	((Fl_Light_Button *)w)->deactivate();
}

void Gameroom::timer_expired ()
{
std::cout << "TIMER EXPIRED" << std::endl;
   // this is called by the timer thread callback when the delay has expired
   // note: only one timer can be active at a time
   lock ();
   m_timer_event = true;
   unlock ();
}


void Gameroom::external_data (Player P)
{
cout << "PLAYER" << endl;
   lock ();
   // this is called when data is received
   // m_P_sub = P;
   unlock ();
}

void Gameroom::external_data (Dealer D)
{
cout << "DEALER" << D.name << endl;
   lock ();
   // this is called when data is received
   // m_D_sub.name = D.name;
   m_D = D;
   unlock ();
}

void Gameroom::external_data (Game G)
{
cout << "GAME" << endl;
   lock ();
   // this is called when data is received
   // m_G_sub = G;
   unlock ();
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
	user[8] = new Fl_Output(470, 50, 140, 30, "Dealer:");
	user[8]->value("Group15");
	hand[8] = new Fl_Output(470, 100, 140, 30, "Hand:");

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

    game_window->end();
    game_window->show();

}

//----------------------------------------------------

Gameroom::Gameroom()
{
   m_timer_thread = NULL;
   p_io = new dds_io<Player,PlayerSeq,PlayerTypeSupport_var,PlayerTypeSupport,PlayerDataWriter_var,
                     PlayerDataWriter,PlayerDataReader_var,PlayerDataReader>
                ( (char*) "player", false, true );
                       // topic name, publish, subscribe

   d_io = new dds_io<Dealer,DealerSeq,DealerTypeSupport_var,DealerTypeSupport,DealerDataWriter_var,
                     DealerDataWriter,DealerDataReader_var,DealerDataReader>
                ( (char*) "dealer", false, true );

   g_io = new dds_io<Game,GameSeq,GameTypeSupport_var,GameTypeSupport,GameDataWriter_var,
                     GameDataWriter,GameDataReader_var,GameDataReader>
                ( (char*) "game", false, true );
       m_timer_event = false;       
}

Gameroom::~Gameroom(){}

//----------------------------------------------------
