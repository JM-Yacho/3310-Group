//player vector or something
//hand
//In UberCasino,, the dealer is not concerned with the wagers or totals of each player.
#include "player.h"

void player::intializeHand_P(){//all cards set to a place holder card that is an ace of hearts and and is invalid
	int i;
	place_holder = {ace,hearts,0};
	for(i = 0; i < MAX_CARDS_PER_PLAYER; ++i){
		p_state.cards[i] = place_holder;
		}
}

void player::initalDeal_P(card_t first_card, card_t second_card){//gives player 2 cards
	p_state.cards[0] = first_card;					//first two in card array
	p_state.cards[1] = second_card;
}

void player::hit_P(card_t dealt_card){//gives player a card--adds card to first available slot of cards[]
	int i;
	for(i = 0; i < MAX_CARDS_PER_PLAYER; ++i){
		if((p_state.cards[i]).valid == 0){break;}
	}
	p_state.cards[i] = dealt_card;
}

bool player::canHit_P(){//returns 0 if CAN*T* hit, returns 1 if CAN hit
	int total, i, cards_held, card_value;
	total = 0;
	cards_held = 0;
	card_value = 0;
	
	for(i = 0; i < MAX_CARDS_PER_PLAYER; ++i){//reurns 0 if total card value > 21
		if((p_state.cards[i]).valid == 0){break;}
		card_value = (p_state.cards[i]).card;
		if(card_value >= 10){card_value = 10;}
		else if(card_value <= 9){++card_value;}
	        total+=card_value;
		}
	if(total >= 21){return 0;}
	
	cards_held = i;

	if(cards_held = 7){return 0;}
		
	return 1;  //retruns 1 if passes both;
}

int player::handTotal(){
	int i,total, card_value;
	total = 0;
	card_value = 0;
		for(i = 0; i < MAX_CARDS_PER_PLAYER; ++i){//reurns 0 if total card value > 21
			if((p_state.cards[i]).valid == 0){break;}
			card_value = (p_state.cards[i]).card;
			if(card_value >= 10){card_value = 10;}
			else if(card_value <= 9){++card_value;}
		        total+=card_value;
		}
	return total;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
void player::intializeHand_D(Game g){//all cards set to a place holder card that is an ace and and is invalid
	int i;
	card_t place_holder = {ace,hearts,0};
	for(i = 0; i < MAX_CARDS_PER_PLAYER; ++i){
		g.dealer_cards[i] = place_holder;
		}
}

void player::initalDeal_D(Game g, card_t first_card, card_t second_card){//gives player 2 cards
	g.dealer_cards[0] = first_card;				 //first two in card array
	g.dealer_cards[1] = second_card;
}

void player::hit_D(Game g, card_t dealt_card){//gives player a card--adds card to first available slot of cards[]
	int i;
	for(i = 0; i < MAX_CARDS_PER_PLAYER; ++i){
		if((g.dealer_cards[i]).valid == 0){break;}
	}
	g.dealer_cards[i] = dealt_card;
}

bool player::canHit_D(Game g){//returns 0 if CAN*T* hit, returns 1 if CAN hit
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
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////





