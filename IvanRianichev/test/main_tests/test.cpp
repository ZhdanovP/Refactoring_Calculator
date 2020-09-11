#include "monolopy.hpp"
#include "gtest/gtest.h"

using namespace ::std;
using namespace ::Game;
class MonopolyTest : public testing::Test {
 public:
  void SetUp() override {
    players.insert(players.begin(),
                   {Player("Peter"), Player("Ekaterina"), Player("Alexander")});
  }
  void TearDown() override {}

  vector<Player> players;
};

TEST_F(MonopolyTest, GetPlayersListReturnCorrectList) {
  Monopoly monopoly(players);

  vector<Player>* x = monopoly.GetPlayers();
  size_t i = 0;
  for (; i < players.size(); i++) {
    ASSERT_EQ((*x)[i].getName(), players[i].getName());
    ASSERT_EQ((*x)[i].getMoney(), 6000);
  }
  ASSERT_EQ(i, players.size());
}
TEST_F(MonopolyTest, GetFieldsListReturnCorrectList) {
  vector<Field> expectedCompanies({Field("Ford", Field::AUTO, 0, false),
                                   Field("MCDonald", Field::FOOD, 0, false),
                                   Field("Lamoda", Field::CLOTHER, 0, false),
                                   Field("Air Baltic", Field::TRAVEL, 0, false),
                                   Field("Nordavia", Field::TRAVEL, 0, false),
                                   Field("Prison", Field::PRISON, 0, false),
                                   Field("MCDonald", Field::FOOD, 0, false),
                                   Field("TESLA", Field::AUTO, 0, false)});

  Monopoly monopoly(players);
  auto actualCompanies = monopoly.GetFields();
  int i = 0;
  for (auto x : *actualCompanies) {
    ASSERT_EQ(x, expectedCompanies[i++]);
  }
  ASSERT_TRUE(i);
}

TEST_F(MonopolyTest, PlayerBuyNoOwnedCompanies) {
  Monopoly monopoly(players);
  auto x = monopoly.GetFieldByName("Ford");
  monopoly.Buy(1, x);

  auto player = monopoly.GetPlayerInfo(1);
  ASSERT_EQ(player.getMoney(), 5500);
  x = monopoly.GetFieldByName("Ford");
  ASSERT_TRUE(x.getNumber() != 0);
}

TEST_F(MonopolyTest, RentaShouldBeCorrectTransferMoney) {
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
