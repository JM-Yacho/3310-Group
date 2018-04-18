#include "dealer.h"
using namespace std;

void MyDealer::gameMode(int x)
  {
    if(x == 1)                        //if x = 1 then the game shoe has 8 deck
    {
      fillShoe(8);                    //create a shoe of 8 deck
      shoe_size = 8;
      /// send info to player
    }
    else                            // if x = 0 then game mode is infinity
    {
      fillShoe(1);                 // fcreate a shoe consisting of 1 deck, resure it
      shoe_size = 1;
      /// send info to player
    }
  }

card_t MyDealer::drawCard()
  {
    int i, j;
    int card_position = randomNumer();                 // get a random number to get position of card i shoe
    card_inUse = check_rand_num(card_position);
    while(card_inUse == true)               //check if the number has already been used
    {
      card_position = randomNumer();
      card_inUse = check_rand_num(card_position);
      if((rand_num_vector.size() == shoe.size()) && (shoe_size == 8))                     // check if all the card have been use or not
      {
        rand_num_vector.clear();       //clear this vector to reuse card from hoe
      }
    }
    card_t temp = shoe(card_position);         //send this card to player
    return temp;
  }
void MyDealer::fillShoe(int shoe_size)
  {
    int i,j, k;
  ///////////////////////////////
  ///////////FILL IN SHOE///////
  ///////////////////////////////
    if(shoe_size == 8)                     //for a shoe size of 8deck
    {
      for(k = 0; k < 8; i++)                 //get 416 card in shoe
      {
        for ( i = 0; i < 4; i++)              // row 1=club, 2=spade, 3=diamond, 4=heart
        {
          for ( j = 0; j < 13; i++)       // column 0=ace, 2=2, 3=3,..., 12==10=king;
          {
            card_t temp = {j,i};           // j= card number; i=suit
            shoe.push_back(temp);
          }
        }
      }
    }
    else                     //infinite shoe size; with 52 card in shoe
    {
      for ( i = 0; i < 4; i++)              // row 1=club, 2=spade, 3=diamond, 4=heart
      {
        for ( j = 0; j < 13; i++)       // column 0=ace, 2=2, 3=3,..., 12==10=king;
        {
          card_t temp = {j,i};           // j= card number; i=suit
          shoe.push_back(temp);
        }
      }
    }
  }
  void MyDealer::d_play()
  {
    card_t dealt_card;
    if((d_turn == true)&&(p_turn == false))
    {
      if(dhand_size == 10)                //if more then 10 card card, end round
      {
        d_cardValue(dealt_card);
        break;
      }
      dhand_size++;
    }
  }
int d_cardValue(card_t dealt_card)
{

}
void MyDealer::hideCard()
  {

  }

void MyDealer::win()
  {

  }
void MyDealer::bust()
  {

  }
void MyDealer::doubleBet()
  {
    //need to double money given out if win
    // player get card, end turn , move to Dealer
    card_t dealt_card = drawCard();
    player::hit_P(PlayerState p, dealt_card);                  //card to give out to player
    phand_size++;                            //update the amount of card player have
    p_turn = false;                           // end player turn
    d_turn = true;                             // switch to dealer turn
    while((player::total==15) && () )
    {
      dealt_card = drawCard();
      player::hit_D(Game g, dealt_card);
    }
  }
int MyDealer::d_handTotal()
{
  player::
}
int MyDealer::randomNumer()
  {
    int size = shoeSizeGetter();
    int random_number;
      srand (time(NULL));
    if(size == 8)                                 //shoe size is 8 deck
      random_number = (rand() % 416) + 1;
      rand_num_vector.push_back(random_number);       //push random numb to the vector to compare
    else
    {
      random_number = (rand() % 52 )+ 1;
    }
    return random_number;
  }
  bool MyDealer::check_rand_num(int num)
  {
    int i;
    for(i = 0; i < rand_num_vector.size(); i++)
    {
      if(num == rand_num_vector(i))
      {
        return true;
      }
    }
    return false;
  }
