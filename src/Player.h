#ifndef PLAYER_H
#define PLAYER_H

#include "UberCasino.idl"
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

void intializeHand(UberCasino::PlayerState player);
void initalDeal(UberCasino::PlayerState player, UberCasino::card_t first_card, UberCasino::card_t second_card);
void hit(UberCasino::PlayerState player, UberCasino::card_t dealt_card);
bool canHit(UberCasino::PlayerState player);

#endif
