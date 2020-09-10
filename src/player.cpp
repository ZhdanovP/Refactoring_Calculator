
#include "player.hpp"

using namespace player;

int Player::s_id_counter{0};

Player::Player(std::string name, int balance):
    name_(name),
    balance_(balance)
{
    ++s_id_counter;
    id_ = s_id_counter;
}

int Player::getId() const
{
    return id_;
}

std::string Player::getName() const
{
    return name_;
}

int Player::getBalance() const
{
    return balance_;
}

void Player::changeBalance(int value)
{
    balance_ += value;
}

void Player::resetCounter()
{
    s_id_counter = 0;
}
