#include "Dealer.h"
#include <ctime>

Dealer::Dealer(){
	decks_ = new Deck[4];
}

Deck* Dealer::getDeck(int i){
	return &decks_[i];
}

void Dealer::shuffleDecks(){
	int pos, pos2;
	for (size_t i = 0; i < 4; i++)
	{
		std::srand(i);
		for (size_t j = 0; j < 208; j++)
		{
			pos = std::rand() % 52;
			pos2 = std::rand() % 52;
			decks_[i].swapCards(pos, pos2);
		}
	}
}

