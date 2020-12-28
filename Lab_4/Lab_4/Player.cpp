#include "Player.h"
#include <iostream>

void Player::setAccount(int account) {
	account_ = account;
}

int Player::getAccount() {
	return account_;
}

void Player::showCards() {
	std::cout << "Вы:        ";
	for (size_t i = 0; i < hand_.size(); ++i)
	{
		std::cout << *(hand_[i]) << "   ";
	}
	std::cout << std::endl;
}

