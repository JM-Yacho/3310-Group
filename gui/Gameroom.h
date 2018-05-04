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
	    boost::thread *m_timer_thread;
        bool m_timer_event;
		Fl_Output* action[9];
		Fl_Output* user[9];
		Fl_Output* hand[9];
		Fl_Output* count[9];
		Fl_Light_Button* start;
		Fl_Button* quit_game;
		Fl_Text_Display* game_title;
		

		dds_io<Player,PlayerSeq,PlayerTypeSupport_var,PlayerTypeSupport,PlayerDataWriter_var,
		     PlayerDataWriter,PlayerDataReader_var,PlayerDataReader> *p_io;
		dds_io<Dealer,DealerSeq,DealerTypeSupport_var,DealerTypeSupport,DealerDataWriter_var,
		     DealerDataWriter,DealerDataReader_var,DealerDataReader> *d_io;
		dds_io<Game,GameSeq,GameTypeSupport_var,GameTypeSupport,GameDataWriter_var,
		     GameDataWriter,GameDataReader_var,GameDataReader> *g_io;

	public:
		Gameroom();
		~Gameroom();

      Player m_P; // stores the last data
      Dealer m_D; 
      Game   m_G;
        void timer_expired ();
     	void external_data ( Player );
      	void external_data ( Dealer );
      	void external_data ( Game G );
		void run_game_window(const char*);
		void cb_add_player(int, const char*);

};

#endif // GAMEROOM_H