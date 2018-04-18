//player vector or something
//hand
//In UberCasino,, the dealer is not concerned with the wagers or totals of each player.
#include "Player.h"

void intializeHand_P(PlayerState p){//all cards set to a place holder card that is an ace and and is invalid
	int i;
	card_t place_holder = {ace,hearts,0};
	for(i = 0; i < MAX_CARDS_PER_PLAYER; ++i){
		p.cards[i] = place_holder;
		}
}

void initalDeal_P(PlayerState p, card_t first_card, card_t second_card){//gives player 2 cards
	p.cards[0] = first_card;									       //first two in card array
	p.cards[1] = second_card;
}

void hit_P(PlayerState p, card_t dealt_card){//gives player a card--adds card to first available slot of cards[]
	int i;
	for(i = 0; i < MAX_CARDS_PER_PLAYER; ++i){
		if((p.cards[i]).valid == 0){break;}
	}
	p.cards[i] = dealt_card;
}

bool canHit_P(PlayerState p){//returns 0 if CAN*T* hit, returns 1 if CAN hit
	int total, i, cards_held, card_value;
	total = 0;
	cards_held = 0;
	card_value = 0;
	
	for(i = 0; i < MAX_CARDS_PER_PLAYER; ++i){//reurns 0 if total card value > 21
		if((p.cards[i]).valid == 0){break;}
		card_value = (p.cards[i]).card;
		if(card_value >= 10){card_value = 10;}
		else if(card_value <= 9){++card_value;}
	        total+=card_value;
		}
	if(total >= 21){return 0;}
	
	cards_held = i;

	if(cards_held = 7){return 0;}
		
	return 1;  //retruns 1 if passes both;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
void intializeHand_D(Game g){//all cards set to a place holder card that is an ace and and is invalid
	int i;
	card_t place_holder = {ace,hearts,0};
	for(i = 0; i < MAX_CARDS_PER_PLAYER; ++i){
		g.dealer_cards[i] = place_holder;
		}
}

void initalDeal_D(Game g, card_t first_card, card_t second_card){//gives player 2 cards
	g.dealer_cards[0] = first_card;				                                //first two in card array
	g.dealer_cards[1] = second_card;
}

void hit_D(Game g, card_t dealt_card){//gives player a card--adds card to first available slot of cards[]
	int i;
	for(i = 0; i < MAX_CARDS_PER_PLAYER; ++i){
		if((g.dealer_cards[i]).valid == 0){break;}
	}
	g.dealer_cards[i] = dealt_card;
}

bool canHit_D(Game g){//returns 0 if CAN*T* hit, returns 1 if CAN hit
	int total, i, cards_held, card_value;
	total = 0;
	cards_held = 0;
	card_value = 0;
	
	for(i = 0; i < MAX_CARDS_PER_PLAYER; ++i){//reurns 0 if total card value > 21
		if((g.dealer_cards[i]).valid == 0){break;}
		card_value = (g.dealer_cards[i]).card;
		if(card_value >= 10){card_value = 10;}
		else if(card_value <= 9){++card_value;}
	        total+=card_value;
		}
	if(total >= 21){return 0;}
	
	cards_held = i;

	if(cards_held = 7){return 0;}
		
	return 1;  //retruns 1 if passes both;
}




