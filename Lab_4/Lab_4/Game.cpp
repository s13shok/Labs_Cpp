#include "Game.h"
#include <iostream>
#include <ctime>

Game::Game() {
	dealer_ = new Dealer();
	dealer_->shuffleDecks();
	player_ = new Player();
	wasDouble_ = false;
	wasTriple_ = false;
	isEnd_ = false;
}

Game::~Game() {
	delete player_;
	delete dealer_;
}

void Game::play() {
	setlocale(LC_ALL, "RUSSIAN");
	std::cout << "Ваша ставка? ";
	bet_ = getValue();
	for (size_t i = 0; i < 2; ++i)
	{
		player_->takeCard(dealer_->getRandomCard());
		dealer_->takeCard(dealer_->getRandomCard());
	}
	showTable();

	dialog();
}

void Game::showTable() {
	dealer_->showDecks();
	if (!isEnd_)
	{
		dealer_->showCardsWithHidden();
	}
	else
	{
		dealer_->showCards();
	}
	player_->showCards();
}

void Game::dialog() {
	select_ = 0;
	actionMenu();
	select_ = getValue();
	while (select_ != 0)
	{
		switch (select_)
		{
		case 1:
			isEnd_ = true;
			showTable();
			endGame();
			select_ = 0;
			break;
		case 2:
			more();
			showTable();
			if (select_ != 0)
			{
				actionMenu();
				select_ = getValue();
			}
			break;
		case 3:
			if (!wasDouble_) {
				wasDouble_ = true;
				bet_ *= 2;
				more();
			}
			else if (!wasTriple_) {
				wasTriple_ = true;
				bet_ += (bet_ / 2);
				more();
			}
			showTable();
			if (select_ != 0)
			{
				actionMenu();
				select_ = getValue();
			}
			break;
		default:
			showTable();
			std::cout << "Введите кооректное число!" << std::endl;
			actionMenu();
			select_ = getValue();
			break;
		}
	}
}

void Game::actionMenu() {
	short actionNo = 0;
	std::cout << ++actionNo << ". Хватит" << std::endl;
	std::cout << ++actionNo << ". Ещё" << std::endl;
	if (!wasDouble_) {
		std::cout << ++actionNo << ". Дабл" << std::endl;
	}
	else if (!wasTriple_) {
		std::cout << ++actionNo << ". Трипл" << std::endl;
	}
}

int Game::getValue()
{
	while (true)
	{
		int input;
		std::cin >> input;

		if (std::cin.fail() || input <= 0)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Введите кооректное число!\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return input;
		}
	}
}

void Game::more() {
	player_->takeCard(dealer_->getRandomCard());
	int playerScore = player_->getScore();
	try {
		if (playerScore > 21)
		{
			throw true;
		}
	}
	catch (...) {
		isEnd_ = true;
		std::cout << "Перебор! Вы проиграли! Ваш проигрыш: " << bet_ << std::endl;
		player_->setAccount(player_->getAccount() - bet_);
		std::cout << "Всего:" << player_->getAccount() << std::endl;
		select_ = 0;
	}
}

void Game::endGame() {
	select_ = 0;
	int dealerScore = dealer_->getScore();
	int playerScore = player_->getScore();
	int bonus = bet_ - 5;
	int counter = 0;
	for (size_t i = 0; i < player_->getCards(); ++i)
	{
		int value = player_->showCard(i)->getValue();
		if (value == 7) {
			counter++;
		}
	}
	if (counter == 3)
	{
		bonus *= 250;
	}
	else if (counter == 2)
	{
		bonus *= 25;
	}
	else if (counter == 1)
	{
		bonus *= 5;
	}
	else
	{
		bonus = 0;
	}
	if (bonus < 0) {
		bonus = 0;
	}
	if (playerScore == 21 && player_->getCards() == 2)
	{
		if (playerScore == dealerScore) {
			std::cout << "Ровно, вам возрвращена ваша ставка:" << bet_ << std::endl;
			player_->setAccount(player_->getAccount() + bet_);
			std::cout << "Всего:" << player_->getAccount();
		}
		else
		{
			std::cout << "Поздравляем! Вы выиграли! Сумма вашего выигрыша:" << bet_ * 2 + bonus << std::endl;
			player_->setAccount(player_->getAccount() + bet_ * 2 + bonus);
			std::cout << "Всего:" << player_->getAccount();
		}
	}
	else if (playerScore <= dealerScore) {
		std::cout << "Вы проиграли! Проиграна ставка:" << bet_ << std::endl;
		player_->setAccount(player_->getAccount() - bet_);
		std::cout << "Всего:" << player_->getAccount();
	}
	else if (playerScore >= dealerScore) {
		std::cout << "Поздравляем! Вы выиграли! Сумма вашего выигрыша:" << bet_ * 2 + bonus << std::endl;
		player_->setAccount(player_->getAccount() + bet_ * 2 + bonus);
		std::cout << "Всего:" << player_->getAccount();
	}
}

