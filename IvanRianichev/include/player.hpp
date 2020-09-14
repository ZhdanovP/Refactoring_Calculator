#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

namespace Game {

class Player {
 public:
  Player(const std::string& name = "", int money = 6000);

  std::string getName() const;

  int getMoney() const;

  int debit(int amountOfMoney);

  int addMoney(int amountOfMoney);

  int getID() const;

  static void nullifyCounter() {
    counter = 0;
  }

  bool operator==(const Player& other) const;

  bool operator!=(const Player& other) const;

 private:
  static size_t counter;

  std::string name_;
  int money_;
  int id_;
};
}
#endif
