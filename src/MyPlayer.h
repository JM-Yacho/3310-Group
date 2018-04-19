#ifndef MY_PLAYER_H
#define MY_PLAYER_H

#include "UberCasino.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

class MYPlayer
{
 private:
	PlayerState p_state;
	bool valid;
	card_t place_holder;
 public:
	MyPlayer(PlayerState _p_state,bool _valid) : p_state{_p_state}, valid{_valid} { }
	void intializeHand_P();
	void initalDeal_P(card_t first_card, card_t second_card);
	void hit_P(card_t dealt_card);
	bool canHit_P();
	int handTotal();

	/*void intializeHand_D(Game g);
	void initalDeal_D(Game g, card_t first_card, card_t second_card);
	void hit_D(Game g, card_t dealt_card);
	bool canHit_D(Game g);*/
};

#endif
