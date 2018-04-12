#include "dealer.h"
using namespace std;

void Dealer::gameMode(int x)
  {
    if(x == 1)                        //if x = 1 then the game shoe has 8 deck
    {
      fillDeck(8);                    //create a shoe of 8 deck
      shoe_size = 8;
      /// send info to player
    }
    else                            // if x = 0 then game mode is infinity
    {
      fillDeck(1);                 // fcreate a shoe consisting of 1 deck, resure it
      shoe_size = 1;
      /// send info to player
    }
  }

void Dealer::dealCard()
  {
    int i, j;
    int size = shoeSizeGetter();
    int p_numOfCard;              //how many card a player have
    int d_numOfCard;             // how many card a player have
    int card_position = randomNumer();                 // get a random number to get position of card i shoe
    card_inUse = check_rand_num(card_position);
    while(card_inUse == true)               //check if the number has already been used
    {
      card_position = randomNumer();
      card_inUse = check_rand_num(card_position);
      //if use all card, clear random number vector
    }
    card_t temp = shoe(card_position);                //send this card to player

  }
void Dealer::fillDeck(int shoe_size)
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

void Dealer::hideCard()
  {

  }

void Dealer::win()
  {

  }
void Dealer::bust()
  {

  }
void Dealer::doubleBet()
  {

  }

int Dealer::randomNumer()
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
  bool Dealer::check_rand_num(int num)
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
