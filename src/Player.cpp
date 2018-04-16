//player vector or something
//hand
//In UberCasino,, the dealer is not concerned with the wagers or totals of each player.
#include "Player.h"

void intializeHand(UberCasino::PlayerState player){//all cards set to ace and and invalid
	int i;
	for(i = 0; i < MAX_CARDS_PER_PLAYER; ++i){
		(player.cards[i]).card = 0;
		(player.cards[i]).valid = 0;
		}
}


void initalDeal(UberCasino::PlayerState player, UberCasino::card_t first_card, UberCasino::card_t second_card){
	player.cards[0] = first_card;
	player.cards[1] = second_card;
}


void hit(UberCasino::PlayerState player, UberCasino::card_t dealt_card){//gives player a card--adds card to first available slot of cards[]
	int i;
	for(i = 0; i < MAX_CARDS_PER_PLAYER; ++i){
		if((player.cards[i]).valid == 0){break;}
	}
	player.cards[i] = dealt_card;
}


bool canHit(UberCasino::PlayerState player){//returns 0 if CAN*T* hit, returns 1 if CAN hit
	int total, i, cards_held, card_value;
	
	for(i = 0; i < MAX_CARDS_PER_PLAYER; ++i){//reurns 0 if total card value > 21
		if((player.cards[i]).valid == 0){break;}
		card_value = player.cards[i]).card;
		if(card_value >= 10){card_value = 10;}
		else if(card_value <= 9){++card_Value;}
	        total+=card_value;
		}
	if(total >= 21){return 0;}
	
	cards_held = i;

	if(cards_held = 7){return 0;}
		
	return 1;  //retruns 1 if passes both;
}






