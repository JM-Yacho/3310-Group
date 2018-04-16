#ifndef DEALER_H
#define DEALER_H

#include "dealer.cpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <string>
using namespace std;

enum game_state  { waiting_to_join, waiting, playing };
enum player_action_t { idle, hitting, standing, splitting, doubling };

const long MAX_PLAYERS_IN_A_GAME = 7;
const long MAX_CARDS_PER_PLAYER = 10;
enum suite_t {hearts,diamonds,clubs,spades};
enum card_kind {ace,two,three,four,five,six,seven,eight,nine,ten,jack,queen,king};
struct card_t
{
   card_kind card;
   suite_t suite;
};

class Dealer {
  private:
    int shoe_size;
    vector<card_t> shoe;                    // create the shoe to play the game
    vector <int> rand_num_vector;          // vector to compare if random number have been call
    bool card_inUse;
    bool check_rand_num();
    void deal_to_dealer ();
    void end_game ();
    void gameMode();                       // pick infinity or 8 deck game mode
    void fillDeck();                       // fill in the deck
    int randomNumer();                     // get a random number


  public:
  Dealer();                                //initialized data;constructor
    void dealCard();                       // Deal cards to players and Dealer
    void hideCard();                       // check to hide healer's second card
    void win();                            // if player or dealer win
    void bust();                           // if player or dealer lose
    void doubleBet();                      // if player or dealer lose
};
#endif
/*
email prof to take out card counting, splitting
*/
