#include "player.hpp"

Player::Player(std::string playerName, FigureType playerFigure)
    : name(playerName), figure(playerFigure), money(6000)
{}

int Player::substractFromMoney(int moneyAmount)
{
    money -= moneyAmount;
    return money;
}
int Player::addToMoney(int moneyAmount)
{
    money += moneyAmount;
    return money;
}

bool Player::operator==(const Player& rhs) const
{
    return getName() == rhs.getName() &&
        getFigure() == rhs.getFigure() &&
        getCurrentMoney() == rhs.getCurrentMoney();
}