#ifndef FIELD_HPP
#define FIELD_HPP

#include <string>
#include <memory>
#include "player.hpp"

namespace Game {

class Field {
 public:
  enum Type { AUTO, FOOD, TRAVEL, CLOTHER, PRISON, BANK };

  Field(std::string name, Type type);

  std::string getName() const;

  Type getType() const;

  int getOwnerID() const;

  bool isOwned() const;

  std::shared_ptr<Player> getOwner() const;

  void setOwner(std::shared_ptr<Player> owner);

  bool operator==(const Field& other) const;

  bool operator!=(const Field& other) const;

 private:
  std::string name_;
  Type type_;
  std::shared_ptr<Player> owner_;
  bool owned_;
};
}
#endif
