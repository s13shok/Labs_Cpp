#pragma once
#include "Deck.h"
#include <vector>
#include "Card.h"
class Dealer
{
	Deck* decks_;
	std::vector<Card> hand_;
public:
	Dealer();
	Deck* getDeck(int i);
	void shuffleDecks();
};

