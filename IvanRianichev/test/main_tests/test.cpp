#include "monopoly.hpp"
#include "gtest/gtest.h"

using namespace ::std;
using namespace ::Game;
class MonopolyTest : public testing::Test {
 public:
  explicit MonopolyTest()
      : players({make_shared<Player>("Peter"),
                 make_shared<Player>("Olga"),
                 make_shared<Player>("Alexander")})
      , monopoly(players) {}
  ~MonopolyTest() {
    Player::nullifyCounter();
  }
  vector<shared_ptr<Player> > players;
  Monopoly monopoly;
};

TEST_F(MonopolyTest, GetPlayersListReturnCorrectList) {
  Monopoly monopoly(players);

  auto x = monopoly.GetPlayers();
  size_t i = 0;
  for (; i < players.size(); i++) {
    ASSERT_EQ(x[i]->getName(), players[i]->getName());
    ASSERT_EQ(x[i]->getMoney(), 6000);
  }
  ASSERT_EQ(i, players.size());
}
TEST_F(MonopolyTest, GetFieldsListReturnCorrectList) {
  vector<shared_ptr<Field> > expectedCompanies(
      {make_shared<Field>("Ford", Field::AUTO),
       make_shared<Field>("MCDonald", Field::FOOD),
       make_shared<Field>("Lamoda", Field::CLOTHER),
       make_shared<Field>("Air Baltic", Field::TRAVEL),
       make_shared<Field>("Nordavia", Field::TRAVEL),
       make_shared<Field>("Prison", Field::PRISON),
       make_shared<Field>("MCDonald", Field::FOOD),
       make_shared<Field>("TESLA", Field::AUTO)});

  auto actualCompanies = monopoly.GetFields();
  size_t i = 0;
  for (; i < actualCompanies.size(); i++) {
    ASSERT_EQ(*(actualCompanies[i]), *(expectedCompanies[i]));
  }
  ASSERT_EQ(i, actualCompanies.size());
}

TEST_F(MonopolyTest, PlayerBuyNoOwnedCompanies) {
  auto x = monopoly.GetFieldByName("Ford");
  monopoly.Buy(players.at(1), x);

  auto player = monopoly.GetPlayerInfo(1);
  ASSERT_EQ(player->getMoney(), 5500);
  x = monopoly.GetFieldByName("Ford");
  ASSERT_TRUE(x->isOwned());
}

TEST_F(MonopolyTest, RentaShouldBeCorrectTransferMoney) {
  auto x = monopoly.GetFieldByName("Ford");
  monopoly.Buy(players.at(1), x);

  x = monopoly.GetFieldByName("Ford");
  monopoly.Renta(players.at(2), x);
  auto player1 = monopoly.GetPlayerInfo(1);
  ASSERT_EQ(player1->getMoney(), 5750);

  auto player2 = monopoly.GetPlayerInfo(2);
  ASSERT_EQ(player2->getMoney(), 5750);
}
