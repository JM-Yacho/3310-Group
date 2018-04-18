#ifndef PLAYER_H
#define PLAYER_H

#include "UberCasino.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

class player
{
 private:

 public:
	//Player createPlayer(
	//Player players[MAX_PLAYERS_IN_A_GAME];
	void intializeHand_P(PlayerState p);
	void initalDeal_P(PlayerState p, card_t first_card, card_t second_card);
	void hit_P(PlayerState p, card_t dealt_card);
	bool canHit_P(PlayerState p);

	void intializeHand_D(Game g);
	void initalDeal_D(Game g, card_t first_card, card_t second_card);
	void hit_D(Game g, card_t dealt_card);
	bool canHit_D(Game g);
};

#endif
