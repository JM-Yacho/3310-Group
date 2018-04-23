#include <FL/Fl.H> 
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
using namespace std;

//---------------------------------------------------
 
class SimpleWindow : public Fl_Window{
 
   public:
      SimpleWindow(int w, int h, const char* title );
      ~SimpleWindow();
      // Fl_Output* bet[9];
      // Fl_Output* inc[9];
      Fl_Output* action[9];
      Fl_Output* user[9];
      Fl_Output* hand[9];
      Fl_Output* count[9];
      Fl_Button* quit;
    
   private:
      static void cb_quit(Fl_Widget*, void*);
      inline void cb_quit_i();
};



//----------------------------------------------------

int main (){
  
   SimpleWindow win(1080,480,"BlackJack");
   return Fl::run();
}

//----------------------------------------------------

SimpleWindow::SimpleWindow(int w, int h, const char* title):Fl_Window(w,h,title){
   int leftspace = 0;
   begin();     

      // Dealer Slot
      user[8] = new Fl_Output(470, 50, 140, 30, "Dealer:");
      user[8]->value("Group15");
      hand[8] = new Fl_Output(470, 100, 140, 30, "Hand:");

      // Player Slots
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

      quit = new Fl_Button(w-100, h-50, 70, 30, "&Quit");
      quit->callback(cb_quit, this);

   end();
   resizable(this);
   show();
}


//----------------------------------------------------

SimpleWindow::~SimpleWindow(){}

//----------------------------------------------------

void SimpleWindow::cb_quit(Fl_Widget* , void* v) {

   ( (SimpleWindow*)v )->cb_quit_i();
}


void SimpleWindow::cb_quit_i() {

    hide();
}

//----------------------------------------------------
