#include "monolopy.hpp"
#include "gtest/gtest.h"

using namespace ::std;
using namespace ::Game;

TEST(LAB2, GetPlayersListReturnCorrectList) {
  vector<Player> players(
      {Player("Peter"), Player("Ekaterina"), Player("Alexander")});

  Monopoly monopoly(players);

  vector<Player>* x = monopoly.GetPlayers();
  size_t i = 0;
  for (; i < players.size(); i++) {
    ASSERT_EQ((*x)[i].getName(), players[i].getName());
    ASSERT_EQ((*x)[i].getMoney(), 6000);
  }
  ASSERT_EQ(i, players.size());
}
TEST(LAB2, GetFieldsListReturnCorrectList) {
  vector<Field> expectedCompanies({Field("Ford", Field::AUTO, 0, false),
                                   Field("MCDonald", Field::FOOD, 0, false),
                                   Field("Lamoda", Field::CLOTHER, 0, false),
                                   Field("Air Baltic", Field::TRAVEL, 0, false),
                                   Field("Nordavia", Field::TRAVEL, 0, false),
                                   Field("Prison", Field::PRISON, 0, false),
                                   Field("MCDonald", Field::FOOD, 0, false),
                                   Field("TESLA", Field::AUTO, 0, false)});
  vector<Player> players(
      {Player("Peter"), Player("Ekaterina"), Player("Alexander")});

  Monopoly monopoly(players);
  auto actualCompanies = monopoly.GetFields();
  int i = 0;
  for (auto x : *actualCompanies) {
    ASSERT_EQ(x, expectedCompanies[i++]);
  }
  ASSERT_TRUE(i);
}

TEST(LAB2, PlayerBuyNoOwnedCompanies) {
  vector<Player> players(
      {Player("Peter"), Player("Ekaterina"), Player("Alexander")});

  Monopoly monopoly(players);
  auto x = monopoly.GetFieldByName("Ford");
  monopoly.Buy(1, x);

  auto player = monopoly.GetPlayerInfo(1);
  ASSERT_EQ(player.getMoney(), 5500);
  x = monopoly.GetFieldByName("Ford");
  ASSERT_TRUE(x.getNumber() != 0);
}

TEST(LAB2, RentaShouldBeCorrectTransferMoney) {
  vector<Player> players(
      {Player("Peter"), Player("Ekaterina"), Player("Alexander")});
  Monopoly monopoly(players);
  auto x = monopoly.GetFieldByName("Ford");
  monopoly.Buy(1, x);

  x = monopoly.GetFieldByName("Ford");
  monopoly.Renta(2, x);
  auto player1 = monopoly.GetPlayerInfo(1);
  ASSERT_EQ(player1.getMoney(), 5750);

  auto player2 = monopoly.GetPlayerInfo(2);
  ASSERT_EQ(player2.getMoney(), 5750);
}

bool operator==(Field& a, Field& b) {
  return a.getName() == b.getName() && a.getType() == b.getType() &&
         a.getNumber() == b.getNumber() && a.isOccupied() == b.isOccupied();
}
