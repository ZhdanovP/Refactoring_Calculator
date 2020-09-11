#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

namespace Game {

class Player {
 public:
  Player(const std::string& name = "", int money = 6000)
      : name(name), money(money) {}
  std::string getName() const {
    return name;
  }

  int getMoney() const {
    return money;
  }

  int debit(int amountOfMoney) {
    money -= amountOfMoney;
    return money;
  }

  int addMoney(int amountOfMoney) {
    money += amountOfMoney;
    return money;
  }

 private:
  std::string name;
  int money;
};
}
#endif
