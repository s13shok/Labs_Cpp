#define _CRT_SECURE_NO_WARNINGS
#include "Dealer.h"
#include <ctime>
#include <iostream>
Dealer::Dealer() {
	decks_ = new Deck[4];
}

Dealer::~Dealer() {
	delete[] decks_;
}

Deck* Dealer::getDeck(int i) {
	return &decks_[i];
}

Card* Dealer::getRandomCard() {
	static int random = 0;
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	std::srand(now->tm_hour + now->tm_min + now->tm_sec + ++random);
	return decks_[rand() % 4].getCard();
}


void Dealer::shuffleDecks() {
	int pos, pos2;
	static int random = 0;
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	for (size_t i = 0; i < 4; ++i)
	{
		std::srand(now->tm_hour + now->tm_min + now->tm_sec + ++random);
		for (size_t j = 0; j < 208; ++j)
		{
			pos = std::rand() % 52;
			pos2 = std::rand() % 52;
			decks_[i].swapCards(pos, pos2);
		}
	}
}

void Dealer::showDecks() {
	std::cout << "Колоды:   [" << decks_[0].getSize() << "] ["
		<< decks_[1].getSize() << "] ["
		<< decks_[2].getSize() << "] ["
		<< decks_[3].getSize() << ']' << std::endl;
}

void Dealer::showCardsWithHidden() {
	std::cout << "Дилер:     " << *(hand_[0]) << "   ??" << std::endl;
}

void Dealer::showCards() {
	std::cout << "Дилер:     " << *(hand_[0]) << "   " << *(hand_[1]) << std::endl;
}



