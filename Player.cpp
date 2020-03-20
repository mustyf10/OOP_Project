#include "Player.h"

Player::Player(string name) :name_(name), score_()
{}

string Player::getName() const
{
	return name_;
}

int Player::getScoreAmount() const
{
	return score_.getAmount();
}
void Player::setScoreAmount(int a)
{
	score_.setAmount(a);
}

void Player::updateScoreAmount(int a)
{
	score_.updateAmount(a);
}
